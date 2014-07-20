#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "list.h"
#include <queue>


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
    EStatus * status;
    EShow show;
    int ** incidence_matrix;
    unsigned v;
    unsigned e;
    SEdge * edges;
    bool ** adjacency_matrix;

    CList ** incidence_list;

    int * stack;

    public:
    CGraph(EShow show, std::string filename, int vertex, float rate);
    virtual ~CGraph();

    void ShowEdges();
    void ShowAdjacencyMatrix();
    void ShowIncidenceMatrix();
    void ShowIncidenceList();

    virtual void CreateAdjacencyMatrix(){};
    virtual void CreateIncidenceMatrix(){};
    virtual void CreateIncidenceList(){};

    virtual bool  ExistEdges(int  start_vertex,int end_vertex){};
    virtual bool  ExistAdjacencyMatrix(int start_vertex,int end_vertex){};
    virtual bool  ExistIncidenceMatrix(int start_vertex,int end_vertex){};
    virtual bool  ExistIncidenceList(int start_vertex,int end_vertex){};

    virtual bool  Topologicalsorting(int l,int l2){};

    virtual bool BFS(int n,std::queue < int > myqueue) {};
    virtual bool Breadthfirstsearch(){};

    virtual bool DFS(int n,int*iS) {};
    virtual bool Dephfirstsearch() {};

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

    bool  ExistEdges(int  start_vertex,int end_vertex);
    bool  ExistAdjacencyMatrix(int start_vertex,int end_vertex);
    bool  ExistIncidenceMatrix(int start_vertex,int end_vertex);
    bool  ExistIncidenceList(int start_vertex,int end_vertex);

    bool BFS(int n,std::queue < int > myqueue) ;
    bool Breadthfirstsearch();

    bool DFS(int n,int*iS);
    bool Dephfirstsearch();

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

