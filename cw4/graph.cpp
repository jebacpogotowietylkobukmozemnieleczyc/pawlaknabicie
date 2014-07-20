#include "graph.h"
#include<fstream>
#include<stack>
#include <iostream>
#include<windows.h>
#include<algorithm>


CGraph::CGraph(EShow show,std::string filename, int vertex, float rate){
    adjacency_matrix = NULL;
    incidence_matrix=NULL;
    incidence_list =NULL;
    lista = NULL;
    v= vertex;
    if(rate>1) e =(int)rate;
    else e=(vertex*(vertex-1))/2 * rate;






if(filename!="")
{


    std::ifstream file;
    file.open(filename.c_str());




    //rate

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

     if(lista!=NULL)delete[] lista;






    delete[] edges;

}

CUndirectedGraph::~CUndirectedGraph(){};


CUndirectedGraph::CUndirectedGraph(EShow show,std::string filename,int vertex, float rate) :CGraph(show,filename,vertex,rate){
if(filename=="")CreateConnectedGraph();
};


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

void CUndirectedGraph::CreateList(){

    lista = new std::list<int> [v];



    for(int i = 0;i<e;i++){
            //std::cout << edges[i].start_vertex << " " << edges[i].end_vertex << std::endl;
        lista[edges[i].start_vertex].push_back(edges[i].end_vertex);
        //undirected without
        lista[edges[i].end_vertex].push_back(edges[i].start_vertex);

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
    //for(int i =0;i<v;i++)std::cout << "Klimas" << stack[i] << std::endl;

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




bool CUndirectedGraph::CheckEulerianCycle(){
    status = new EStatus[v];
    for(int i =0;i<v;i++)status[i]=UNDONE;
    int cc = 1;
    int cu = 0;
    if(DFS(0,&cc,&cu)==true)cu++;
    delete[] status;
    if(cc!=v)return false; // spojnosc
    if(cu!=0)return false; //cykl
    return true;

}

bool CUndirectedGraph::DFS(int n,int* cc,int* cu){
    status[n] = DONE;


    int degree =0;
    for (std::list<int>::iterator it=lista[n].begin(); it != lista[n].end(); ++it){
        degree ++;
        if(status[*it]!=DONE){
            if(DFS(*it,cc,cu)==true)(*cu)++;
            (*cc)++;
        }


    }


    if(degree%2==1)return true;
    else return false;
}



bool CUndirectedGraph::SearchEulerianCycle(int l,int l2){

    if(CheckEulerianCycle()){

    int * stack = new int[e+1];
    int i = e;
    //bool * use = new * bool[v];
    //for(int i =0;i<v;++i)use[i] = new bool[v];

    DFSEuler(0,stack,&i);

    //for(int i =0 ;i<e+1;i++)std::cout << stack[i] << " ";
    delete[] stack;



    /*
    for(int i =0;i<v;++i){
        std::cout << std::endl << i << "-->";
        for (std::list<int>::iterator  it=lista[i].begin(); it!=lista[i].end(); ++it)
        std::cout << ' ' << *it;
    }
    for(int i =0;i<v;++i)lista[i].clear();
    */
    return true;
    }
    std::cout << "nie ma " << std::endl;
    return false;
}

bool CUndirectedGraph::DFSEuler(int n,int stack[],int * i){

    int p;


    while(!lista[n].empty()){

        p=lista[n].front();
        //std::cout << " " <<  n << std::endl;

        lista[n].pop_front();

        lista[p].remove(n);
        //std::cout << "Delete" <<  n << p << std::endl;
        //ShowIncidenceList();
        DFSEuler(p,stack,i);
        //std::cout << std::endl;

    }
    //std::cout << ": " <<  n<< " ";
    stack[(*i)--]=n;
return true;
}



bool CUndirectedGraph::DFSEulerNR(int l,int l2){

    std::stack<int> mystack;
    std::stack<int> result_stack;
    mystack.push(0);

    while(!mystack.empty()){
    int n= mystack.top();
    while(!lista[n].empty()){

        int p=lista[n].front();
        mystack.push(p);
        lista[n].pop_front();
        lista[p].remove(n);
        n=p;
      }
     if(lista[n].empty()){mystack.pop();result_stack.push(n);}
    }
return true;
}










bool CUndirectedGraph::DFSHamilton(int n,bool status[],CList* List,__int64  * Start,double * PCFreq){
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    if((li.QuadPart-*Start)/(*PCFreq) > 60){std::cout << "Out" << std::endl; return false;}//stop
        list_element * current = incidence_list[n]->GetHead();
        while(current!=NULL){
        //std::cout << " " <<  n << " ";
            List->AddtoListFirst(current->id);
            status[n]=true;
            if(status[current->id]==false){if(!DFSHamilton(current->id,status,List,Start,PCFreq))return false;}
            else if (current->id==0) {
                    //std::cout << "->";
                    int j =0;
                    for(int i =0;i<v;i++)if(status[i]==true)j++;
                    if(j==v){/*List->ShowList();*/return false;}

                    };
            status[n]=false;
            List->DeleteFirst();

            current = current->next;
        }
        return true;


}

bool CUndirectedGraph::SearchHamiltonCycle(int l1,int l2){

    //Counter
    __int64   Start;
    double  PCFreq;
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	std::cout << "QueryPerformanceFrequency failed!\n";
    PCFreq = double(li.QuadPart);
    QueryPerformanceCounter(&li);
    Start = li.QuadPart;


    bool *status = new bool[v];
    for (int i =0;i<v;i++)status[i] =false;
     CList * List = new CList;
    List->AddtoListFirst(0);
    DFSHamilton(0,status,List,&Start,&PCFreq);

    delete List;
    delete[] status;
    return true;

}

bool CUndirectedGraph::CreateConnectedGraph(){
    //std::cout << v << " " << e << std::endl;
    int n =v;

    int * a = new int[n];
    int * b = new int[n];
    int * ef = new int[e];
    int * es = new int[e];


    bool ** am = new  bool * [n];
    for (int i = 0; i < n; ++i) {
        am[i]= new bool[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            am[i][j]=false;
        }
    }

    for (int i = 0; i < n; ++i) {
        b[i]=i;
    }
    int fn = rand() % n;
    a[0]=b[fn];
    std::swap(b[fn],b[n-1]);



    for (int i = 1; i < n; ++i) {
        if(i>e)break;
        int l = rand() % i ;
        int l2 = rand() % (n-i);
        am[a[l]][b[l2]]=true;
        am[b[l2]][a[l]]=true;
        //std::cout << a[l] << " " << b[l2] << std::endl;
        ef[i-1]=a[l];
        es[i-1]=b[l2];

        a[i]=b[l2];
        std::swap(b[n-i-1],b[l2]);

    }

    delete[] a;
    delete[] b;

    int l = n-1;


    for(int i =0;i<n-1;i++){
        if(l>=e)break;
        for(int j =i+1;j<n;j++){
                if(l>=e)break;
                if(am[i][j]==true || am[j][i]==true)continue;
                //std::cout << i << " " << j << std::endl;
                ef[l]=i;
                es[l]=j;
                l++;
            }

    }

    for(int i = 0; i < n; i++)
                delete[] am[i];

    delete[] am;



    int * tmmp =  new int[e];
    for(int i=0;i<e;i++)tmmp[i]=i;
    std::random_shuffle(tmmp,tmmp+e);


    edges = new SEdge[e];

    int li=0;
    for(int i =0;i<e;i++){

            edges[i].start_vertex=ef[tmmp[i]];
            edges[i].end_vertex=es[tmmp[i]];

            //std::cout << ++li << " " << ef[tmmp[i]] << " " << es[tmmp[i]] << std::endl;
    }


    delete[] tmmp;



    delete[] ef;
    delete[] es;




}


