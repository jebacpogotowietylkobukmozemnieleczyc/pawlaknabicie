#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

#include "list.h"
#include <list>


enum EStatus{
    UNDONE,
    PROCESS,
    DONE
};

enum EResult{
    SUM,
    AVERAGE
};

enum EShow{
    NOTHING,
    ERROR,
    ALL
};

typedef struct SEdge {
    unsigned start_vertex;
    unsigned end_vertex;

} edge;




class CGraph
{



    protected:
    EShow show;
    int ** incidence_matrix;
    unsigned v;
    unsigned e;
    SEdge * edges;
    bool ** adjacency_matrix;
    std::list<int>*  lista;


    EStatus * status;
    public:
    CGraph(EShow show, std::string filename, int vertex, float rate);
    virtual ~CGraph();

     CList ** incidence_list;

    void ShowEdges();
    void ShowAdjacencyMatrix();
    void ShowIncidenceMatrix();
    void ShowIncidenceList();

    virtual void CreateAdjacencyMatrix(){};
    virtual void CreateIncidenceMatrix(){};
    virtual void CreateIncidenceList(){};
    virtual void CreateList(){};

    virtual bool  ExistEdges(int  start_vertex,int end_vertex){};
    virtual bool  ExistAdjacencyMatrix(int start_vertex,int end_vertex){};
    virtual bool  ExistIncidenceMatrix(int start_vertex,int end_vertex){};
    virtual bool  ExistIncidenceList(int start_vertex,int end_vertex){};

    virtual bool  Topologicalsorting(int l,int l2){};

    virtual bool CheckEulerianCycle(){};
    virtual bool DFS(int n,int * cc){};
    virtual bool SearchEulerianCycle(int l,int l2) {};
    virtual bool DFSEuler(int n,int stack[],int* i){};
    virtual bool DFSHamilton(int n,bool status[],CList* List,__int64  * Start,double * PCFreq){};
    virtual bool SearchHamiltonCycle(int l,int l2){};
    virtual bool DFSEulerNR(int l,int l2) {};

    virtual bool CreateConnectedGraph() {};

    int GetE() {return e;};
    SEdge GetEdges(int i) {return edges[i];};


};


class CUndirectedGraph : public CGraph{


    public:
    CUndirectedGraph(EShow show,std::string filename, int vertex, float rate);
    virtual ~CUndirectedGraph();


    void CreateAdjacencyMatrix();
    void CreateIncidenceMatrix();
    void CreateIncidenceList();
     void CreateList();

    bool  ExistEdges(int  start_vertex,int end_vertex);
    bool  ExistAdjacencyMatrix(int start_vertex,int end_vertex);
    bool  ExistIncidenceMatrix(int start_vertex,int end_vertex);
    bool  ExistIncidenceList(int start_vertex,int end_vertex);

    bool CheckEulerianCycle();
    bool DFS(int n,int * cc,int * cu);
    bool SearchEulerianCycle(int l,int l2) ;
    bool DFSEuler(int n,int stack[],int *i);
    bool DFSHamilton(int n,bool status[],CList* List,__int64  * Start,double * PCFreq);
    bool SearchHamiltonCycle(int l,int l2);
    bool DFSEulerNR(int l,int l2);

    bool CreateConnectedGraph();

};


class CDirectedGraph : public CGraph{
private:

    int * stack;
public:
      CDirectedGraph(EShow show,std::string filename, int vertex, float rate);
      virtual ~CDirectedGraph();
      void CreateIncidenceList();
      bool Topologicalsorting(int l,int l2);
      bool Vertex(int n,int * iS);


};


#endif

