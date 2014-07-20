#include <iostream>
#include<fstream>
#include "test.h"
#include<windows.h>
#include<algorithm>

CTest::CTest(STestProperties* test_properties)
: name(test_properties->name),counter(test_properties->counter),filename(test_properties->filename),show(test_properties->show),result(test_properties->result),repeat(test_properties->repeat),directed(test_properties->directed),rate(test_properties->rate),types(test_properties->types),method(test_properties->method){


};
/*
CTest::~CTest(){
    delete[] methodinaction;
};
*/






void CTest::Testing(){

    std::cout <<std::endl << name << std::endl;
    std::ofstream  file;
    file.open(filename->save.c_str());

     for(int t =0;t<types;t++)file <<  " " << method[t].name;
     for(int n =counter->start;n<=counter->end;n+=counter->step){


        if(directed==false)graph = new CUndirectedGraph(show,filename->open.c_str(),n,rate);
        else graph = new CDirectedGraph(show,filename->open.c_str(),n,rate);



        std::cout << std::endl << "Ilosc elementow: " << n << std::endl;
        file <<  std::endl << n << " ";
        int e = graph->GetE();

        int* a = CreateRandomArray(e);


        for(int t =0; t<types;t++){

            double timer =0;
            double sum =0;

            if((method[t].methodbeforeaction)!=NULL){
                    (graph->*method[t].methodbeforeaction)();
            }
            //(graph->*method[t].methodbeforeaction)();
            int REP = e;
            if(repeat==false)REP =1;


            for(int i =0; i<REP;i++){





                if(show==NOTHING){
                    StartCounter();
                    (graph->*method[t].methodinaction)(graph->GetEdges(a[i]).start_vertex,graph->GetEdges(a[i]).end_vertex);
                    timer = GetCounter();

                }
                else if(show==ERROR){
                    StartCounter();
                    if(!(graph->*method[t].methodinaction)(3,4))std::cout << "ERROR" << std::endl;
                    timer = GetCounter();
                }
                else{
                    //
                    printf("%d | %d \n",graph->GetEdges(a[i]).start_vertex,graph->GetEdges(a[i]).end_vertex);

                    StartCounter();
                    if((graph->*method[t].methodinaction)(graph->GetEdges(a[i]).start_vertex,graph->GetEdges(a[i]).end_vertex))std::cout << "Working properly..." << std::endl;
                    else std::cout << "ERROR" << std::endl;
                    timer = GetCounter();
                    std::cout << timer << std::endl;
                }

                sum+=timer;

            }

        if(result==AVERAGE)sum/=REP;
        std::cout << method[t].name << ": " <<sum << std::endl;
        file << sum << " ";
        }

        delete a;
        delete graph;
    }
    file.close();
}





void CTest::StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart);

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}





double CTest::GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq*1000;
}




int* CTest::CreateRandomArray(int size)
{
    int *a  = new int[size];
    for(int i =0;i<size;i++)a[i]=i;
    std::random_shuffle(a,a+size);
    return a;
}




