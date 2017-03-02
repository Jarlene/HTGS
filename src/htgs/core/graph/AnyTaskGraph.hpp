//
// Created by tjb3 on 2/24/17.
//

#ifndef HTGS_ANYTASKGRAPH_HPP
#define HTGS_ANYTASKGRAPH_HPP

#include <list>
#include <htgs/core/task/AnyTaskScheduler.hpp>
#include <string>
#include <htgs/core/task/TaskScheduler.hpp>
#include <htgs/api/ITask.hpp>
#include <cstddef>
#include <htgs/core/graph/edge/EdgeDescriptor.hpp>
#include <fstream>


namespace htgs {

/**
 * @typedef ITaskMap
 * Creates a mapping between an ITask and a task scheduler.
 */
typedef std::map<AnyITask *, AnyTaskScheduler *> ITaskMap;

/**
 * @typedef ITaskPair
 * Defines a pair to be added into an ITaskMap
 */
typedef std::pair<AnyITask *, AnyTaskScheduler *> ITaskPair;


class AnyTaskGraph {
 public:

  AnyTaskGraph (size_t pipelineId, size_t numPipelines) : pipelineId(pipelineId), numPipelines(numPipelines) {
    taskSchedulers = new std::list<AnyTaskScheduler *>();
    taskCopyMap = new ITaskMap();
  }

  virtual ~AnyTaskGraph() {
    for (auto task : *taskSchedulers)
    {
      if (task != nullptr)
      {
        delete task;
        task = nullptr;
      }
    }
    delete taskSchedulers;

    delete taskCopyMap;
    taskCopyMap = nullptr;
  }

  /**
  * Pure virtual function to get the vertices of the TaskGraph
  * @return the vertices of the TaskGraph
  */
  virtual std::list<AnyTaskScheduler *> *getTaskSchedulers() {
    return this->taskSchedulers;
  }

  template <class T, class U>
  ITask<T, U> *getCopy(ITask<T, U> *orig)
  {
//    TaskScheduler<T, U> *taskScheduler = nullptr;

    for (auto tCopy : *taskCopyMap) {
      if (tCopy.first == orig) {
        return (ITask<T, U> *)tCopy.second->getTaskFunction();
      }
    }

    return nullptr;
//
//    // If the scheduler is found, then the copy was already made. return the one from the scheduler
//    if (taskScheduler != nullptr) {
//      return taskScheduler->getTaskFunction();
//    } else{
//      // If the scheduler is not found, then create a copy and add it
//      ITask<T, U> *copy = orig->copyITask();
//
//      // Add the copy to this graph in case copy is called multiple times on same task
//      taskScheduler = new TaskScheduler<T, U>(copy, copy->getNumThreads(), copy->isStartTask(), copy->isPoll(), copy->getMicroTimeoutTime(), pipelineId, numPipelines);
//      this->taskSchedulers->push_back(taskScheduler);
//      return copy;
//    }
  }

  template <class T, class U>
  TaskScheduler<T, U> *getTaskScheduler(ITask<T, U> *task) {

    TaskScheduler<T, U> *taskScheduler = nullptr;

    for (auto tSched : *taskSchedulers)
    {
      if (tSched->getTaskFunction() == task)
      {
        taskScheduler = (TaskScheduler<T, U> *)tSched;
        break;
      }
    }

    if (taskScheduler == nullptr)
    {
      taskScheduler = new TaskScheduler<T, U>(task, task->getNumThreads(), task->isStartTask(), task->isPoll(), task->getMicroTimeoutTime(), pipelineId, numPipelines);
      this->taskSchedulers->push_back(taskScheduler);
    }

    return taskScheduler;

  }

  void addTaskScheduler(AnyTaskScheduler *taskScheduler)
  {
    for (auto tSched : *taskSchedulers)
    {
      if (tSched == taskScheduler)
        return;
    }

    this->taskSchedulers->push_back(taskScheduler);
  }


  size_t getPipelineId() { return this->pipelineId; }

  size_t getNumPipelines() { return this->numPipelines; }

  virtual AnyTaskScheduler *getGraphConsumerTaskScheduler() = 0;
  virtual AnyTaskScheduler *getGraphProducerTaskScheduler() = 0;

  virtual std::shared_ptr<AnyConnector> getInputConnector() = 0;
  virtual std::shared_ptr<AnyConnector> getOutputConnector() = 0;

  /**
   * Writes the dot representation of the task graph to disk
   * @param file the file path (will not create directories)
   */
//  virtual void writeDotToFile(std::string file) = 0;

  /**
   * Writes the dot representation of the task graph to disk
   * @param file the file path (will not create directories)
   * @param dotGenFlags the various dot file generation flags to use
   */
//  virtual void writeDotToFile(std::string file, int dotGenFlags) = 0;



  /**
   * Writes the dot representation of the task graph to disk
   * @param file the file path (will not create directories)
   */
  void writeDotToFile(std::string file) {
    writeDotToFile(file, 0);
  }

  void writeDotToFile(std::string file, int flags) {
    std::ofstream f(file);
    f << genDotGraph(flags);
    f.flush();

    std::cout << "Writing dot file for task graph to " << file << std::endl;
  }


  /**
   * Generate the content only of the graph (excludes all graph definitions and attributes)
   */
  std::string genDotGraphContent(int flags) {
    std::ostringstream oss;

    for (AnyTaskScheduler *bTask : *taskSchedulers) {
      oss << bTask->getDot(flags);
    }

    if ((flags & DOTGEN_FLAG_HIDE_MEM_EDGES) != 0) {

//      if (memReleaser->size() > 0) {
//        for (const auto &kv : *this->memReleaser) {
//          auto connector = kv.second->at(this->pipelineId);
//          oss << std::string("mainThread") << " -> " << connector->getDotId() << ";" << std::endl;
//        }
//
//        oss << "mainThread[label=\"Main Thread\"];\n";
//      }
    }

    return oss.str();
  }

  /**
   * Generates the dot graph as a string
   */
  std::string genDotGraph(int flags) {
    std::ostringstream oss;

    oss << "digraph { rankdir=\"TB\"" << std::endl;
    oss << "forcelabels=true;" << std::endl;
    oss << "node[shape=record, fontsize=10, fontname=\"Verdana\"];" << std::endl;
    oss << "edge[fontsize=10, fontname=\"Verdana\"];" << std::endl;
    oss << "graph [compound=true];" << std::endl;

    for (AnyTaskScheduler *bTask : *taskSchedulers) {
      oss << bTask->getDot(flags);
    }

    if (getGraphConsumerTaskScheduler() != nullptr)
      oss << this->getInputConnector()->getDotId() << "[label=\"Graph Input\n" << this->getInputConnector()->getProducerCount() <<  (((DOTGEN_FLAG_SHOW_IN_OUT_TYPES & flags) != 0) ? ("\n"+this->getInputConnector()->typeName()) : "") << "\"];" << std::endl;

    if (getGraphProducerTaskScheduler() != nullptr)
      oss << "{ rank = sink; " << this->getOutputConnector()->getDotId() << "[label=\"Graph Output\n" << this->getOutputConnector()->getProducerCount() <<  (((DOTGEN_FLAG_SHOW_IN_OUT_TYPES & flags) != 0) ? ("\n"+this->getOutputConnector()->typeName()) : "") << "\"]; }" << std::endl;


    if ((flags & DOTGEN_FLAG_HIDE_MEM_EDGES) == 0) {
//      if (memReleaser->size() > 0) {
//        for (const auto &kv : *this->memReleaser) {
//          for (const auto &memConnector : *kv.second)
//            oss << std::string("mainThread") << " -> " << memConnector->getDotId() << ";" << std::endl;
//        }
//      }
    }

    if (oss.str().find("mainThread") != std::string::npos)
    {
      oss << "{ rank = sink; mainThread[label=\"Main Thread\", fillcolor = aquamarine4]; }\n";
    }


#ifdef PROFILE
    std::string desc = "";
    std::unordered_map<std::string, double> *timeMap;
    std::unordered_map<std::string, std::string> *colorMap;

    if ((flags & DOTGEN_FLAG_SHOW_PROFILE_COMP_TIME) != 0)
    {
      desc = "Compute Time (sec): ";
      timeMap = this->getComputeTimeAverages();

    }
    else if ((flags & DOTGEN_FLAG_SHOW_PROFILE_WAIT_TIME) != 0)
    {
      desc = "Wait Time (sec): ";
      timeMap = this->getWaitTimeAverages();
    }
    else if ((flags & DOTGEN_FLAG_SHOW_PROFILE_MAX_Q_SZ) != 0)
    {
      desc = "Max Q Size";
      timeMap = this->getMaxQSizeAverages();
    }

    if (desc != "") {
      colorMap = this->genColorMap(timeMap);
      oss << this->genProfileGraph(flags, timeMap, desc, colorMap);

      delete timeMap;
      delete colorMap;
    }
#endif

    oss << "}" << std::endl;

    return oss.str();
  }


  void copyTasks(std::list<AnyTaskScheduler *> *tasks)
  {
    for (auto task : *tasks)
    {
      this->createCopy(task);
    }
  }

  AnyTaskScheduler *getTaskSchedulerCopy(AnyITask *iTask)
  {
    for (auto tCopy : *taskCopyMap) {
      if (tCopy.first == iTask) {
        return tCopy.second;
      }
    }

    return nullptr;
  }

 private:


  void createCopy(AnyTaskScheduler *taskScheduler)
  {
    AnyITask *origITask = taskScheduler->getTaskFunction();

    // If the original ITask is not in the taskCopyMap, then add a new copy and map it to the original
    if (this->taskCopyMap->find(origITask) == this->taskCopyMap->end())
    {
      AnyTaskScheduler *taskSchedulerCopy = taskScheduler->copy(false);
      taskCopyMap->insert(ITaskPair(origITask, taskSchedulerCopy));
    }
  }


  ITaskMap *taskCopyMap;
  std::list<AnyTaskScheduler *> *taskSchedulers;

  size_t pipelineId; //!< The pipelineId for the task graph
  size_t numPipelines; //!< The number of pipelines from this graph


};

}

#endif //HTGS_ANYTASKGRAPH_HPP
