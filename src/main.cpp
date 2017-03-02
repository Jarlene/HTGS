
#include <future>

#include <htgs/api/Bookkeeper.hpp>
#include <htgs/api/TaskGraph.hpp>
#include <htgs/api/Runtime.hpp>

class TestData : public htgs::IData {
 public:
  TestData(int v) : val(v){  }
  int getVal() { return val; }
 private:
  int val;
};

class TestRule : public htgs::IRule<TestData, TestData> {
 public:

  TestRule(std::string name) : name(name) {}

  virtual ~TestRule() {

  }
  virtual bool isRuleTerminated(size_t pipelineId) {
    return name != "Rule1";
  }
  virtual void shutdownRule(size_t pipelineId) {  }

  virtual void applyRule(std::shared_ptr<TestData> data, size_t pipelineId) {
    if (name == "Rule1")
      addResult(data);
  }

  virtual std::string getName() {
    std::stringstream ss;
    ss << name << " " << this;
    return ss.str();
  }
 private:
  std::string name;
};

class TestRuleBad : public htgs::IRule<TestData, htgs::VoidData> {
 public:

  TestRuleBad(std::string name) : name(name) {}

  virtual ~TestRuleBad() {

  }
  virtual bool isRuleTerminated(size_t pipelineId) {
    return name != "Rule1";
  }
  virtual void shutdownRule(size_t pipelineId) {  }

  virtual void applyRule(std::shared_ptr<TestData> data, size_t pipelineId) {
  }

  virtual std::string getName() {
    std::stringstream ss;
    ss << name << " " << this;
    return ss.str();
  }
 private:
  std::string name;
};

class TestTask : public htgs::ITask<TestData, TestData> {
 public:
  TestTask(int n) : ITask(n), n(n) { }

  ~TestTask() override {

  }
  void initialize() override {
  }
  void executeTask(std::shared_ptr<TestData> data) override {
    addResult(data);
  }
  void shutdown() override {

  }
  std::string getName() override {
    std::stringstream ss;
    ss << "TestTask: " + std::to_string(n) << " " << this;
    return ss.str();
  }

  TestTask *copy() override {
    return new TestTask(n);
  }
 private:
  int n;
};

int main()
{

#pragma GCC diagnostic ignored "-Wunused-variable"

  int NUM_DATA = 10;
  bool useBK = true;
  int nVertices = 5;
  TestData *testData;



  htgs::Bookkeeper<TestData> *bk = new htgs::Bookkeeper<TestData>();
  auto testRule1 = std::make_shared<TestRule>("Rule1");
  auto testRule2 = std::make_shared<TestRule>("Rule2");
  auto testRule3 = std::make_shared<TestRule>("Rule3");
  auto testRule4 = std::make_shared<TestRule>("Rule4");

  auto tGraph = new htgs::TaskGraph<TestData, TestData>();


  std::vector<TestTask *> tasks;
  for (int i = 0; i < nVertices; i++)
  {
    tasks.push_back(new TestTask(i+1));
  }

  for (int i = 0; i < nVertices; i++)
  {
    if (i == 0)
    {
      tGraph->setGraphConsumerTask(tasks[i]);
    }

    if (i == nVertices-1)
    {
      tGraph->setGraphProducerTask(tasks[i]);
    }

    if (i > 0 && i < nVertices)
    {
      if (i == 2 && useBK)
      {
        tGraph->addEdge(tasks[i-1], bk);
        // TODO: Fix segfault when not connecting the graph correctly (provide more useful error report ... )
        tGraph->addRuleEdge(bk, testRule1, tasks[i]);
        tGraph->addRuleEdge(bk, testRule2, tasks[0]);
        tGraph->addRuleEdge(bk, testRule3, tasks[1]);
        tGraph->addRuleEdge(bk, testRule4, bk);
      }
      else
      {
        tGraph->addEdge(tasks[i-1], tasks[i]);
      }
    }

  }

  tGraph->copy(0, 1)->writeDotToFile("test.dot");
  tGraph->writeDotToFile("testorig.dot");

  system("dot -Tpng -o test.png test.dot");
  system("dot -Tpng -o testorig.png testorig.dot");

  auto execGraph = tGraph->copy(0, 1);


  execGraph->incrementGraphProducer();

  auto runtime = new htgs::Runtime(execGraph);

  runtime->executeRuntime();


  for (int i = 0; i < NUM_DATA; i++)
  {
    execGraph->produceData(new TestData(i));
  }

  execGraph->decrementGraphProducer();

  while(!execGraph->isOutputTerminated())
  {
    auto data = execGraph->consumeData();
    if (data == nullptr)
      std::cout << "NULL DATA Received" << std::endl;
    else
      std::cout << "Data: " << data->getVal() << " received" << std::endl;
  }

  runtime->waitForRuntime();


  execGraph->writeDotToFile("testExec.dot", DOTGEN_FLAG_SHOW_ALL_THREADING);

  system("dot -Tpng -o testExec.png testExec.dot");

  std::cout << "Test completed" << std::endl;
}
