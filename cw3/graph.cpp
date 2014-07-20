#include "graph.h"
#include<fstream>
#include <iostream>




CGraph::CGraph(EShow show,std::string filename, int vertex, float rate){
    adjacency_matrix = NULL;
    incidence_matrix=NULL;
    incidence_list =NULL;
    std::ifstream file;
    file.open(filename.c_str());

    v= vertex;
    e=(vertex*(vertex-1))/2 *rate;//rate
    edges = new SEdge[e];
    int tester = 0;
    for(int i =0;i<e;i++){
        int sv =0;
        int ev =0;
        file >>  sv >> ev;
        //std::cout << "sv: " << sv << " ev: " << ev  << " i: " << i << "e:" << e << std::endl;
        if(sv==0 && ev==0){
            if(show!=NOTHING)std::cout << "Brak krawedzi w pliku." << std::endl;
            break;
        }
        else if(sv>=vertex || ev >= vertex){
            i--;
             if(show==ALL)std::cout << "Zly vertex." << i <<  " " << sv << "-" << ev << std::endl;
            continue;
        }
        if(show==ALL)printf("%d - %d \n",sv,ev);
        edges[i].start_vertex = sv;
        edges[i].end_vertex =ev;

    }
    file.close();

}

CGraph::~CGraph(){
    if(adjacency_matrix!=NULL){
        for(int i = 0; i < v; i++)
            delete[] adjacency_matrix[i];

        delete[] adjacency_matrix;
    }


    if(incidence_matrix!=NULL){
        for(int i = 0; i < v; i++)
            delete[] incidence_matrix[i];


        delete[] incidence_matrix;
    }

    if(incidence_list!=NULL){
        for(int i = 0; i < v; i++)
            delete incidence_list[i];


        delete[] incidence_list;
    }

    delete[] edges;

}

CUndirectedGraph::~CUndirectedGraph(){};


CUndirectedGraph::CUndirectedGraph(EShow show,std::string filename,int vertex, float rate) :CGraph(show,filename,vertex,rate){};


CDirectedGraph::~CDirectedGraph(){};


CDirectedGraph::CDirectedGraph(EShow show,std::string filename,int vertex, float rate) :CGraph(show,filename,vertex,rate){};




void CGraph::ShowEdges(){
   for(int i =0;i<e;i++)
        std::cout << edges[i].start_vertex << " " << edges[i].end_vertex << std::endl;
}







void CGraph::ShowAdjacencyMatrix(){
    std::cout <<  "-->";
    for(int i =0;i<v;i++)
        std::cout << i << " ";
    std::cout << std::endl <<  std::endl;
    for(int i =0;i<v;i++){
        std::cout << i << "| ";
        for(int j =0;j<v;j++)
            std::cout << adjacency_matrix[i][j] << " ";
        std::cout << std::endl;
    }
}




void CGraph::ShowIncidenceMatrix(){
    std::cout <<  "-->";
    for(int i =0;i<e;i++)
        std::cout << i << " ";
    std::cout << std::endl <<  std::endl;
    for(int i =0;i<v;i++){
        std::cout << i << "| ";
        for(int j =0;j<e;j++)
            std::cout << incidence_matrix[i][j] << " ";
        std::cout << std::endl;
    }
}



void CGraph::ShowIncidenceList(){
    for(int i =0;i<v;i++){
        std::cout << i << " --> ";
        incidence_list[i]->ShowList();
        std::cout << std::endl;
    }

}




//CUndirectedGraph::CUndirectedGraph() : CGraph() {};



void CUndirectedGraph::CreateAdjacencyMatrix(){

    adjacency_matrix = new bool * [v];
    for(int i = 0; i < v; i++)
        adjacency_matrix[i] = new bool [v];

    for(int i =0;i<v;i++)
        for(int j =0;j<v;j++)
            adjacency_matrix[i][j]=0;

    for(int i = 0;i<e;i++){
        adjacency_matrix[edges[i].start_vertex][edges[i].end_vertex] = 1;
        //directed without
        adjacency_matrix[edges[i].end_vertex][edges[i].start_vertex] = 1;
    }




}

void CUndirectedGraph::CreateIncidenceMatrix(){

    incidence_matrix = new int * [v];
    for(int i = 0; i < v; i++)
        incidence_matrix[i] = new int [e];

    for(int i =0;i<v;i++)
        for(int j =0;j<e;j++)
            incidence_matrix[i][j]=0;


    for(int i = 0;i<e;i++){

        incidence_matrix[edges[i].start_vertex][i] = 1;
        //undirected -1
        incidence_matrix[edges[i].end_vertex][i] = 1;
        //change
    }




}


void CUndirectedGraph::CreateIncidenceList(){

    incidence_list = new CList * [v];
    for(int i = 0; i < v; i++)
        incidence_list[i] = new CList;


    for(int i = 0;i<e;i++){

        incidence_list[edges[i].start_vertex]->AddtoList(edges[i].end_vertex);
        //undirected without
        incidence_list[edges[i].end_vertex]->AddtoList(edges[i].start_vertex);
    }




}


bool CUndirectedGraph::ExistEdges(int start_vertex,int end_vertex){
    for(int i = 0; i<e; i++)
    if((edges[i].start_vertex==start_vertex) && (edges[i].end_vertex==end_vertex))return true;
    return false;
}


bool CUndirectedGraph::ExistAdjacencyMatrix(int start_vertex,int end_vertex){
    if(adjacency_matrix[start_vertex][end_vertex]==1)return true;
    else return false;
}


bool CUndirectedGraph::ExistIncidenceMatrix(int start_vertex,int end_vertex){
    for(int i = 0;i<e;i++)if(incidence_matrix[start_vertex][i]==1 && incidence_matrix[end_vertex][i]==1)return true;
    return false;
}

bool CUndirectedGraph::ExistIncidenceList(int start_vertex,int end_vertex){
    if(incidence_list[start_vertex]->Search(end_vertex)!=NULL)return true;
    else return false;
}

void CDirectedGraph::CreateIncidenceList(){

    incidence_list = new CList * [v];
    for(int i = 0; i < v; i++)
        incidence_list[i] = new CList;


    for(int i = 0;i<e;i++){

        incidence_list[edges[i].start_vertex]->AddtoList(edges[i].end_vertex);

    }




}


bool CDirectedGraph::Topologicalsorting(int l,int l2){
    status = new EStatus[v];
    stack = new int [v];
    int iS = v;

    for(int i =0;i<v;i++)status[i]= UNDONE;

    for(int i =0;i<v;i++){
        if(status[i]==DONE)continue;
        if(Vertex(i,&iS)==false)return false;

    }
    delete[] status;
    //show
    if(l>0)
    for(int i =0;i<v;i++)std::cout <<  stack[i] << " ";

    delete[] stack;
    return true;

}

bool CDirectedGraph::Vertex(int n,int*iS){
    status[n] = PROCESS;

    list_element * current = incidence_list[n]->GetHead();
    //if(current!=NULL)std::cout << n << "->" << current->id << std::endl;
    while(current!=NULL){
         //std::cout << "while" << std::endl;
        if(status[current->id]==PROCESS) return false;
        else if(status[current->id]==UNDONE){
                if(Vertex(current->id,iS)==false) return false;
        }
        current = current->next;
    }

    status[n] = DONE;
    stack[--*iS]=n;
    //std::cout << "Topo" << n << std::endl;

    return true;
}

bool CUndirectedGraph::Breadthfirstsearch(){
    status = new EStatus[v];
    for(int i =0;i<v;i++)status[i]= UNDONE;
    std::queue < int > myqueue;

    for(int i =0;i<v;i++){
        if(status[i]==UNDONE){

             status[i] = DONE;
            myqueue.push(i);
            std::cout << i  << " ";
            BFS(i,myqueue);
        }
    }

    delete[] status;

    return true;

}


bool CUndirectedGraph::BFS(int n,std::queue < int > myqueue){


    list_element * current = incidence_list[n]->GetHead();
    while(current!=NULL){
        if(status[current->id]==UNDONE){

        std::cout << current->id  << " ";
        status[current->id] = DONE;
        myqueue.push(current->id);

        }
        current = current->next;
    }

    if(!myqueue.empty()){
            int next = myqueue.front();
            myqueue.pop();
            BFS(next,myqueue);
    }

    return true;
}



bool CUndirectedGraph::DFS(int n,int*iS){
    status[n] = DONE;
    std::cout <<  n << " ";
    list_element * current = incidence_list[n]->GetHead();

    while(current!=NULL){
      if(status[current->id]==UNDONE){
			DFS(current->id,iS);
        }
        current = current->next;
    }
    return true;
}


bool CUndirectedGraph::Dephfirstsearch(){
    status = new EStatus[v];
    int iS = v;
     for(int i =0;i<v;i++)status[i]= UNDONE;

    for(int i =0;i<v;i++)if(status[i]==UNDONE)DFS(i,&iS);
    delete[] status;

    std::cout <<  std::endl;
    return true;
}


