#include <iostream>
#include <cstdlib>
#include <ctime>
#include "test.h"
#include "list.h"
#include "graph.h"
using namespace std;




int main()
{
    srand( time( NULL ) );


    CGraph * graph = new CDirectedGraph(NOTHING,"test.txt",10,0.25);
    graph->CreateIncidenceList();
    if(!graph->Topologicalsorting(1,0))std::cout << "Cykl";
    delete graph;

    std::cout << std::endl;
    graph = new CDirectedGraph(NOTHING,"test2.txt",10,0.25);
    graph->CreateIncidenceList();
    if(!graph->Topologicalsorting(1,0))std::cout << "Cykl";;
    delete graph;

    std::cout << std::endl;



    graph = new CUndirectedGraph(NOTHING,"testu.txt",17,0.16911);
    graph->CreateIncidenceList();
    std::cout << "DFS" << std::endl;
    graph->Dephfirstsearch();
    std::cout << "BFS" << std::endl;
     graph->Breadthfirstsearch();
    delete graph;


    /*
    CGraph * graph = new CUndirectedGraph("graph.txt",10,0.6);
    graph->ShowEdges();

    graph->CreateAdjacencyMatrix();
    graph->ShowAdjacencyMatrix();

    graph->CreateIncidenceMatrix();
    graph->ShowIncedenceMatrix();

    graph->CreateIncidenceList();
    graph->ShowIncedenceList();

    if(graph->ExistEdges(6,6))cout << "Exist EL" << endl;
    else cout << "No Exist EL" << endl;

    if(graph->ExistAdjacencyMatrix(6,3))cout << "Exist AM" << endl;
    else cout << "No Exist AM" << endl;

    if(graph->ExistIncedenceMatrix(6,4))cout << "Exist IM" << endl;
    else cout << "No Exist IM" << endl;

    if(graph->ExistIncedenceList(6,1))cout << "Exist IL" << endl;
    else cout << "No Exist IL" << endl;


    delete graph;


    cout << endl<< "1 Test " << endl<< endl;
    graph = new CUndirectedGraph("graph.txt",10,0.6);
    graph->ShowEdges();
    delete graph;

    cout << endl<< "2 Test " << endl<< endl;


    //Test1
   const int Types = 4;
    Count counter ={10,10,500};
    SFilename filename = {open: "completegraph.txt", save: "result.txt"};

    SMethod  method[Types]={
        {"Lista_krawedzi",NULL,&CGraph::ExistEdges},
        {"AdjacencyMatrix",&CGraph::CreateAdjacencyMatrix,&CGraph::ExistAdjacencyMatrix},
        {"IncidenceMatrix",&CGraph::CreateIncidenceMatrix,&CGraph::ExistIncidenceMatrix},
        {"IncidenceList",&CGraph::CreateIncidenceList,&CGraph::ExistIncidenceList}
    };
//&CGraph::ExistAdjacencyMatrix
//&CGraph::ExistIncidenceMatrix
//&CGraph::ExistIncidenceList

    STestProperties test_properties ={
        name: "Test1",
        counter :&counter,
        filename : &filename,
        show:NOTHING,
        result: SUM,
        repeat:true,
        directed: false,
        types : Types,
        rate : 0.6,
        method:method
    };



    CTest * test = new CTest(&test_properties);
    test->Testing();
    delete test;


/*
  const int Types = 1;
    Count counter ={25,25,2000};
    SFilename filename = {open: "DAGgraph.txt", save: "resultzad2.txt"};

    SMethod  method[Types]={
        {"IncidenceList",&CGraph::CreateIncidenceList,&CGraph::Topologicalsorting}
    };
//&CGraph::ExistAdjacencyMatrix
//&CGraph::ExistIncidenceMatrix
//&CGraph::ExistIncidenceList

    STestProperties test_properties ={
        name: "Test2",
        counter :&counter,
        filename : &filename,
        show:NOTHING,
        result: SUM,
        repeat:false,
        directed: true,
        types : Types,
        rate : 0.3,
        method:method
    };



    CTest * test = new CTest(&test_properties);
    test->Testing();
    delete test;
    /*
    //Test2
    cout << endl << "SuperTest2" << endl;

    const int Types2 = 1;
    Count counter2 ={5,5,15};
    SFilename filename2 = {open: "graph.txt", save: "result.txt"};

    SMethod  method2[Types2]={
        {"IncidenceList",&CGraph::CreateIncidenceList,&CGraph::Topologicalsorting}
    };

    STestProperties test_properties2 ={
        counter :&counter2,
        filename : &filename2,
        show:NOTHING,
        result: AVERAGE,
        repeat: false,
        directed: false,
        types : Types2,
        rate : 0.3,
        method:method2
    };



     test = new CTest(&test_properties2);
    test->Testing();
    delete test;




    CGraph * graph = new CDirectedGraph("directedgraph2.txt",10,0.8);
    graph->ShowEdges();
    graph->CreateIncidenceList();
    graph->ShowIncidenceList();
    if(graph->Topologicalsorting(5,5)==true)cout << "spoko!" << endl;
    else cout << "Nie spoko!" << endl;


    delete graph;




*/
    cout << "Hello world!" << endl;
    return 0;
}
