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

//step

     const int Types = 6;
    float rate[Types]={0.2,0.3,0.4,0.6,0.8,0.95};

    //float rate[Types]={0.95};
    Count counter ={100,50,1000};
    SFilename filename = {open: "euleriangraph/euleriangraph0000.txt", save: "result.txt"};

    SMethod  method[Types]={
        {"List Incydencji",&CGraph::CreateList,&CGraph::DFSEulerNR}
    };


    STestProperties test_properties ={
        name: "Test1",
        counter :&counter,
        filename : &filename,
        show:NOTHING,
        result: SUM,
        repeat:false,
        directed: false,
        types : Types,
        rate : rate,
        method:method
    };



    CTest * test = new CTest(&test_properties);
    test->Testing();
    delete test;


/*
//step2
    for(int i =0;i<10;++i){
            std::cout << "R: " << i << std::endl;
            string istring = to_string(i + 1);
    const int Types2 = 6;
    float rate2[Types2]={0.2,0.3,0.4,0.6,0.8,0.95};
    Count counter2 ={38,1,40};
    SFilename filename2 = {open: "Hamiltongraph/Hamiltongraph"+istring +"/connectedgraph00.txt", save: "result"+istring +".txt"};

    SMethod  method2[Types2]={
        {"List Incydencji",&CGraph::CreateIncidenceList,&CGraph::SearchHamiltonCycle}
    };


    STestProperties test_properties ={
        name: "Test2",
        counter :&counter2,
        filename : &filename2,
        show:NOTHING,
        result: SUM,
        repeat:false,
        directed: false,
        types : Types2,
        rate : rate2,
        method:method2
    };



    CTest * test = new CTest(&test_properties);
    test->Testing();
    delete test;

}





    //test hamilton

     for(int i =0;i<10;++i){
            std::cout << "R: " << i << std::endl;
            string istring = to_string(i + 1);
    const int Types2 = 3;
    float rate2[Types2]={0.2,0.6,0.95};
    Count counter2 ={100,100,300};
    SFilename filename2 = {open: "Hamiltongraph/Hamiltongraph"+istring +"/connectedgraph000.txt", save: "result"+istring +".txt"};

    SMethod  method2[Types2]={
        {"List Incydencji",&CGraph::CreateIncidenceList,&CGraph::SearchHamiltonCycle}
    };


    STestProperties test_properties ={
        name: "Test2",
        counter :&counter2,
        filename : &filename2,
        show:NOTHING,
        result: SUM,
        repeat:false,
        directed: false,
        types : Types2,
        rate : rate2,
        method:method2
    };



    CTest * test = new CTest(&test_properties);
    test->Testing();
    delete test;
    }

/*


    CGraph * graph = new CUndirectedGraph(ALL,"dyskretna.txt",6,0.55);
    //CGraph * graph = new CUndirectedGraph(NOTHING,"euleriangraph/euleriangraph0500.txt",1000,0.95);
    graph->ShowEdges();


    graph->CreateList();
    //graph->ShowIncidenceList();




    if(graph->DFSEulerNR())cout << "Dziala" << endl;
    else cout << "Nie" << endl;

    //graph->SearchHamiltonCycle();
    delete graph;



/*
    CList * List = new CList;
    List->AddtoList(5);
    List->AddtoList(7);
    List->AddtoList(9);
    List->AddtoList(4);
    List->ShowList();
    cout << endl;
    List->DeletefromList(4);
    List->DeletefromList(5);

    List->ShowList();
    delete List;

    */

        cout << "Hello world!" << endl;

    return 0;
}
