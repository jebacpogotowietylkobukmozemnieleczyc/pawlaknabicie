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

     for(int t =0;t<types;t++)file <<  " " << rate[t];

     for(int n =counter->start;n<=counter->end;n+=counter->step){
        std::cout << std::endl << "Ilosc elementow: " << n << std::endl;
        file <<  std::endl << n << " ";
        for(int t =0; t<types;t++){
            std::string _str = to_string(n);
            std::string _file=filename->open;
            for(int i =0;i<_str.length();i++){

                    _file[_file.length()-5-i]=_str[_str.length()-1-i];
                    //std::cout << _file << std::endl;
            }



            std::string _file2="rates/rate0000.txt";
            std::ifstream  file_rate;
            for(int i =0;i<_str.length();i++){

                    _file2[_file2.length()-5-i]=_str[_str.length()-1-i];
                    //std::cout << _file << std::endl;
            }
            file_rate.open(_file2.c_str());
            if(file_rate!=NULL){
                for(int i =0;i<types;++i)file_rate >>rate[i];
                file_rate.close();
            }
            std::cout << _file << std::endl;

            if(directed==false)graph = new CUndirectedGraph(show,_file.c_str(),n,rate[t]);
            else graph = new CDirectedGraph(show,_file.c_str(),n,rate[t]);




            int e = graph->GetE();






                double timer =0;
                double sum =0;

                if((method[0].methodbeforeaction)!=NULL && graph->incidence_list==NULL){
                    (graph->*method[0].methodbeforeaction)();
                }
                //(graph->*method[t].methodbeforeaction)();
                int REP = e;
                if(repeat==false)REP =1;


                for(int i =0; i<REP;i++){





                    if(show==NOTHING){
                        StartCounter();
                        (graph->*method[0].methodinaction)(0,0);
                        timer = GetCounter();

                    }
                    else if(show==ERROR){
                        StartCounter();
                        if(!(graph->*method[0].methodinaction)(0,0))std::cout << "ERROR" << std::endl;
                        timer = GetCounter();
                    }
                    else{
                    //


                        StartCounter();
                        if((graph->*method[1].methodinaction)(0,0))std::cout << "Working properly..." << std::endl;
                        else std::cout << "ERROR" << std::endl;
                        timer = GetCounter();
                        std::cout << timer << std::endl;
                    }

                    sum+=timer;

                }

                if(result==AVERAGE)sum/=REP;
                std::cout << rate[t] << ": " <<sum << std::endl;
                file << sum << " ";



            delete graph;
        }
    }
    file.close();
}





void CTest::StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}





double CTest::GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}




int* CTest::CreateRandomArray(int size)
{
    int *a  = new int[size];
    for(int i =0;i<size;i++)a[i]=i;
    std::random_shuffle(a,a+size);
    return a;
}




