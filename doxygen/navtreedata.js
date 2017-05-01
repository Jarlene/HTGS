var NAVTREE =
[
  [ "HTGS", "index.html", [
    [ "Hybrid Task Graph Scheduler (HTGS) - An application programming interface to generate hybrid pipeline workflow systems", "index.html", [
      [ "Installation ", "index.html#installation", null ],
      [ "Approach ", "index.html#approach", null ],
      [ "HTGS Design Methodology ", "index.html#methodlogy", null ],
      [ "Overview of HTGS ", "index.html#overview", null ],
      [ "Tutorials ", "index.html#tutorials", null ]
    ] ],
    [ "Getting Started", "install-instructions.html", null ],
    [ "Tutorial 0", "tutorial0.html", [
      [ "Downloading the Tutorials ", "tutorial0.html#tut0-download", null ],
      [ "Getting Started using the Command-Line ", "tutorial0.html#tut0-cmd", null ],
      [ "Getting Started using Eclipse CDT ", "tutorial0.html#tut0-eclipse", null ],
      [ "Getting Started using CLion ", "tutorial0.html#tut0-clion", null ]
    ] ],
    [ "Tutorial 1", "tutorial1.html", [
      [ "Objectives ", "tutorial1.html#tut1-objectives", null ],
      [ "API Used ", "tutorial1.html#tut1-api-used", null ],
      [ "Implementation ", "tutorial1.html#tut1-implementation", [
        [ "Data", "tutorial1.html#tut1-data", [
          [ "Input data implementation", "tutorial1.html#tut1-input-data", null ],
          [ "Output data implementation", "tutorial1.html#tut1-output-data", null ],
          [ "Notes", "tutorial1.html#tut1-data-notes", null ]
        ] ],
        [ "Tasks", "tutorial1.html#tut1-tasks", [
          [ "AddTask Implementation", "tutorial1.html#tut1-addtask-implementation", null ],
          [ "Notes", "tutorial1.html#tut1-task-notes", null ]
        ] ],
        [ "Creating and Executing the htgs::TaskGraphConf", "tutorial1.html#tut1-create-and-execute-taskgraph", [
          [ "Main function (create and execute TaskGraph)", "tutorial1.html#tut1-main-function", null ],
          [ "Debugging and profiling a htgs::TaskGraphConf", "tutorial1.html#tut1-debug", null ],
          [ "Notes", "tutorial1.html#taskgraph-notes", null ]
        ] ]
      ] ],
      [ "Summary ", "tutorial1.html#summary", null ]
    ] ],
    [ "Tutorial 2A", "tutorial2a.html", [
      [ "Objectives ", "tutorial2a.html#tut2a-objectives", null ],
      [ "API Used ", "tutorial2a.html#tut2a-api-used", null ],
      [ "Implementation ", "tutorial2a.html#tut2a-implementation", [
        [ "Data", "tutorial2a.html#tut2a-data", [
          [ "MatrixRequestData", "tutorial2a.html#tut2a-matrix-request", null ],
          [ "MatrixBlockData", "tutorial2a.html#tut2a-matrix-data", null ],
          [ "MatrixBlockMulData", "tutorial2a.html#tut2a-matrix-mul-data", null ],
          [ "Notes", "tutorial2a.html#tut2a-data-notes", null ]
        ] ],
        [ "Tasks", "tutorial2a.html#tut2a-tasks", [
          [ "GenMatrixTask", "tutorial2a.html#tut2a-gen-matrix-task", null ],
          [ "HadamardProductTask", "tutorial2a.html#tut2a-hadamard-product-task", null ],
          [ "Notes", "tutorial2a.html#tut2a-task-notes", null ]
        ] ],
        [ "Managing Dependencies with the Bookkeeper and IRule", "tutorial2a.html#tut2a-bookkeeper", [
          [ "Notes", "tutorial2a.html#tut2a-bookkeeper-notes", null ]
        ] ],
        [ "Creating and Executing the htgs::TaskGraphConf", "tutorial2a.html#tut2a-create-and-execute-taskgraph", [
          [ "Main function (Hadamard Product)", "tutorial2a.html#tut2a-main-function", null ],
          [ "Notes", "tutorial2a.html#tut2a-taskgraph-notes", null ]
        ] ]
      ] ],
      [ "Summary ", "tutorial2a.html#tut2a-summary", null ]
    ] ],
    [ "Tutorial 2B", "tutorial2b.html", [
      [ "Objectives ", "tutorial2b.html#tut2b-objectives", null ],
      [ "API Used ", "tutorial2b.html#tut2b-api-used", null ],
      [ "Implementation ", "tutorial2b.html#tut2b-implementation", [
        [ "Data", "tutorial2b.html#tut2b-data", null ],
        [ "Tasks", "tutorial2b.html#tut2b-tasks", [
          [ "ReadDiskMatrixTask", "tutorial2b.html#tut2b-read-matrix-task", null ],
          [ "HadamardProductTaskWithReleaseMem", "tutorial2b.html#tut2b-hadamard-product-task", null ],
          [ "Notes", "tutorial2b.html#tut2b-task-notes", null ]
        ] ],
        [ "Managing Dependencies with a Bookkeeper and IRules", "tutorial2b.html#tut2b-bookkeeper", null ],
        [ "Throttling Tasks with a Memory Manager", "tutorial2b.html#tut2b-memory-manager", [
          [ "Static Memory Manager", "tutorial2b.html#tut2b-static-mm", null ],
          [ "Dynamic Memory Manager", "tutorial2b.html#tut2b-dynamic-mm", null ],
          [ "Notes", "tutorial2b.html#tut2b-memorymanagement-notes", null ]
        ] ],
        [ "Creating and Executing the TaskGraph", "tutorial2b.html#tut2b-create-and-execute-taskgraph", [
          [ "Main function (Hadamard Product)", "tutorial2b.html#tut2b-main-function", null ],
          [ "Notes", "tutorial2b.html#tut2b-taskgraph-notes", null ]
        ] ]
      ] ],
      [ "Summary ", "tutorial2b.html#tut2b-summary", null ]
    ] ],
    [ "Tutorial 3A", "tutorial3a.html", [
      [ "Objectives ", "tutorial3a.html#tut3a-objectives", null ],
      [ "API Used ", "tutorial3a.html#tut3a-api-used", null ],
      [ "Implementation ", "tutorial3a.html#tut3a-implementation", [
        [ "Data", "tutorial3a.html#tut3a-data", null ],
        [ "Tasks", "tutorial3a.html#tut3a-tasks", [
          [ "LoadMatrixTask", "tutorial3a.html#tut3a-load-matrix-task", null ],
          [ "MatMulBlkTask", "tutorial3a.html#tut3a-matmul-task", null ],
          [ "MatMulAccumTask", "tutorial3a.html#tut3a-matmul-accum-task", null ],
          [ "MatMulOutputTask", "tutorial3a.html#tut3a-matmul-output-task", null ],
          [ "Notes", "tutorial3a.html#tut3a-task-notes", null ]
        ] ],
        [ "Managing Dependencies with the Bookkeeper and IRule", "tutorial3a.html#tut3a-bookkeeper", [
          [ "MatMulDistributeRule", "tutorial3a.html#tut3a-distr-rule", null ],
          [ "MatMulLoadRule", "tutorial3a.html#tut3a-load-rule", null ],
          [ "MatMulAccumulateRule", "tutorial3a.html#tut3a-acc-rule", null ],
          [ "MatMulOutputRule", "tutorial3a.html#tut3a-output-rule", null ],
          [ "Notes", "tutorial3a.html#tut3a-bookkeeper-notes", null ]
        ] ],
        [ "Creating and Executing the htgs::TaskGraphConf", "tutorial3a.html#tut3a-create-and-execute-taskgraph", [
          [ "Main function (Matrix Multiplication)", "tutorial3a.html#tut3a-main-function", null ],
          [ "Notes", "tutorial3a.html#tut3a-taskgraph-notes", null ]
        ] ]
      ] ],
      [ "Summary ", "tutorial3a.html#tut3a-summary", null ]
    ] ],
    [ "Tutorial 3B", "tutorial3b.html", [
      [ "Objectives ", "tutorial3b.html#tut3b-objectives", null ],
      [ "API Used ", "tutorial3b.html#tut3b-api-used", null ],
      [ "Implementation ", "tutorial3b.html#tut3b-implementation", [
        [ "Data", "tutorial3b.html#tut3b-data", null ],
        [ "Tasks", "tutorial3b.html#tut3b-tasks", [
          [ "LoadMatrixTask", "tutorial3b.html#tut3b-load-matrix-task", null ],
          [ "MatMulBlkTask", "tutorial3b.html#tut3b-matmul-task", null ],
          [ "MatMulAccumTask", "tutorial3b.html#tut3b-matmul-accum-task", null ],
          [ "MatMulOutputTask", "tutorial3b.html#tut3b-matmul-output-task", null ],
          [ "Notes", "tutorial3b.html#tut3b-task-notes", null ]
        ] ],
        [ "Managing Dependencies with the Bookkeeper and IRule", "tutorial3b.html#tut3b-bookkeeper", [
          [ "MatMulDistributeRule", "tutorial3b.html#tut3b-distr-rule", null ],
          [ "MatMulLoadRule", "tutorial3b.html#tut3b-load-rule", null ],
          [ "MatMulAccumulateRule", "tutorial3b.html#tut3b-acc-rule", null ],
          [ "MatMulOutputRule", "tutorial3b.html#tut3b-output-rule", null ],
          [ "Notes", "tutorial3b.html#tut3b-bookkeeper-notes", null ]
        ] ],
        [ "Creating and Executing the htgs::TaskGraphConf", "tutorial3b.html#tut3b-create-and-execute-taskgraph", [
          [ "Main function (Matrix Multiplication)", "tutorial3b.html#tut3b-main-function", null ],
          [ "Notes", "tutorial3b.html#tut3b-taskgraph-notes", null ]
        ] ]
      ] ],
      [ "Summary ", "tutorial3b.html#tut3b-summary", null ]
    ] ],
    [ "Namespaces", null, [
      [ "Namespace List", "namespaces.html", "namespaces" ]
    ] ],
    [ "Classes", "annotated.html", [
      [ "Class List", "annotated.html", "annotated_dup" ],
      [ "Class Index", "classes.html", null ],
      [ "Class Hierarchy", "hierarchy.html", "hierarchy" ],
      [ "Class Members", "functions.html", [
        [ "All", "functions.html", "functions_dup" ],
        [ "Functions", "functions_func.html", "functions_func" ],
        [ "Variables", "functions_vars.html", null ],
        [ "Related Functions", "functions_rela.html", null ]
      ] ]
    ] ],
    [ "Files", null, [
      [ "File List", "files.html", "files" ],
      [ "File Members", "globals.html", [
        [ "All", "globals.html", null ],
        [ "Macros", "globals_defs.html", null ]
      ] ]
    ] ]
  ] ]
];

var NAVTREEINDEX =
[
".html",
"classhtgs_1_1_any_task_graph_conf.html#af036e1aa6ec1fa431d2428c30d896653",
"classhtgs_1_1_memory_data.html#a31811d95506bd1e1b4f9f8f4d7323eb7",
"classhtgs_1_1_task_manager.html#af3aedc8010045d4936f549f377aa1dd9"
];

var SYNCONMSG = 'click to disable panel synchronisation';
var SYNCOFFMSG = 'click to enable panel synchronisation';