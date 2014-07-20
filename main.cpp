
#include <iostream>
#include <string>
#include <bitset>
#include <math.h>
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>
#include<windows.h>

#define SIZE 100
#define MAX 100


struct SElement{
    int size;
    int value;
};



struct SCount{

    int start;
    int step;
    int end;
};







//timer
double PCFreq = 0.0;
__int64 CounterStart = 0;




void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    std::cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart);

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq*1000;
}





int BruteForce(int n,SElement * element,int limit_size){
    int total_value = 0;
    int m =pow(2,n);

    for (int i = 1; i < m; ++i) {
           std::bitset<SIZE> bar (i);

           int sum_size= 0;
           int sum_value = 0;
           for (int j = 0; j < n; ++j) {
               if(bar[j]==1){

                   sum_size+=element[j].size;
                   sum_value+=element[j].value;
               }
           }
           if(sum_size <= limit_size && sum_value> total_value)total_value =sum_value;
           //std::cout << "Size: " << sum_size << " Value: " << sum_value << std::endl;
    }
    return total_value;
}


void QuickSort(SElement * element, int start, int end) {
    //std::cout << "Klimas to debil!2!! " << start << " " << end <<std::endl;
    int i =(start+end)/2;
    double pivot = ((element[i].value/(double)element[i].size));
    //std::cout << pivot << std::endl;
    int j = end;
    i = start;
    while(i<=j){
        //std::cout <<"Start" << i << " " << j <<  std::endl;
        for (; ((element[i].value/(double)element[i].size))>pivot && i < end ;++i);
        for (;((element[j].value/(double)element[j].size))<pivot && j>=0 ;--j);
       // std::cout <<"End" <<  i << " " << j <<  std::endl;
        if (i > j)continue;
        std::swap(element[i].value,element[j].value);
        std::swap(element[i].size,element[j].size);
        ++i;
        --j;
    }
    if(start<j)QuickSort(element,start,j);
    if(i<end)QuickSort(element,i,end);
}

int Heuristic(int n,SElement * element,int limit_size){


    QuickSort(element,0,n-1);
    int sum_size =0;
    int sum_value =0;
    for (int i = 0; i < n; ++i) {
        if(sum_size+element[i].size>limit_size)continue;
        sum_size +=element[i].size;
        sum_value +=element[i].value;
    }

    return sum_value;

}


int Dynamic(int n,SElement * element,int limit_size){

    std::vector < std::vector < int > > MyVector;
    for (int i = 0; i <= n; ++i) MyVector.push_back( std::vector < int >(limit_size+1,0) );

    for (int i = 1; i <= n; ++i) {
        for (int l = 1; l <= limit_size; ++l) {
            if(l<element[i-1].size)MyVector[i][l]=MyVector[i-1][l];
            else MyVector[i][l]=std::max(MyVector[i-1][l-element[i-1].size]+element[i-1].value,MyVector[i-1][l]);
        }
    }
    return MyVector[n][limit_size];
}

int main ()
{
    srand((int)time(NULL));

    std::ofstream file;

    /*
    int  n =10;


    SElement element[n];

   // element[0]={15,10};
   // element[1]={1,5};
   // element[2]={5,20};


    for (int i = 0; i < n; ++i) {
        element[i].size  =rand() % MAX +1;
        element[i].value  =rand() % MAX + 1;
    }

    int  limit_size = MAX * n * 0.25 ;

    for (int i = 0; i < n; ++i) {
        std::cout << element[i].size << " " << element[i].value << std::endl;
    }

    StartCounter();
    std::cout << "BruteForce: " <<  BruteForce(n,element,limit_size) << std::endl;
    std::cout << "timer " << GetCounter() << std::endl;
    std::cout << "Dynamic: " <<Dynamic(n,element,limit_size) <<std::endl;
    std::cout << "timer " << GetCounter() << std::endl;
    std::cout << "Heuristic: " <<Heuristic(n,element,limit_size) <<std::endl;
    std::cout << "timer " << GetCounter() << std::endl;
 */
    const SCount count = {

           10,
           1,
           25,

       };




    //Test Dynamic

    std::cout << "Test Dynamic" << std::endl;

        int  limit_size =13 ;
        const int m =5;
        std::cout << "Ilosc elementow: "  << m << " limit_size: " << limit_size << std::endl;
        SElement element[m];


       element[0].size  = 7;
       element[0].value = 3;
       element[1].size  = 4;
       element[1].value = 2;
       element[2].size  = 1;
       element[2].value = 3;
       element[3].size  = 9;
       element[3].value = 5;
       element[4].size  = 1;
       element[4].value = 2;

        std::cout << "Dynamic: " << Dynamic(m,element,limit_size) << std::endl;
        std::cout << "Heuristic: " << Heuristic(m,element,limit_size) << std::endl;
        std::cout << std::endl;
        std::cout << "Zmiana: " <<  std::endl;


        element[0].size  = 8;
        element[0].value = 3;
        element[1].size  = 4;
        element[1].value = 2;
        element[2].size  = 1;
        element[2].value = 1;
        element[3].size  = 9;
        element[3].value = 4;
        element[4].size  = 1;
        element[4].value = 1;

        std::cout << "Dynamic: " << Dynamic(m,element,limit_size) << std::endl;


        std::cout << "Heuristic: " << Heuristic(m,element,limit_size) << std::endl;
        std::cout << std::endl;
        std::cout << "Zmiana2: " <<  std::endl;

        element[0].size  = 8;
        element[0].value = 3;
        element[1].size  = 2;
        element[1].value = 1;
        element[2].size  = 2;
        element[2].value = 1;
        element[3].size  = 9;
        element[3].value = 4;
        element[4].size  = 2;
        element[4].value = 1;

        std::cout << "Dynamic: " << Dynamic(m,element,limit_size) << std::endl;


        std::cout << "Heuristic: " << Heuristic(m,element,limit_size) << std::endl;

    //Dynamic vs BruteForce timer
    file.open("DvBtimer.txt");
    std::cout << "//Dynamic vs BruteForce timer" << std::endl;
    file << " BruteForce Dynamic" << std::endl;
    for (int n = count.start; n <=count.end ; n+=count.step) {
        int  limit_size = MAX * n * 0.1 ;
        std::cout << "Ilosc elementow: "  << n << " limit_size: " << limit_size << std::endl;
        SElement element[n];


        for (int i = 0; i < n; ++i) {
            element[i].size  =rand() % MAX +1;
            element[i].value  =rand() % MAX + 1;
        }


        file << n << " ";

        StartCounter();
        BruteForce(n,element,limit_size);
        double timer = GetCounter();
        std::cout << "BruteForce: " << timer << std::endl;
        file << timer << " ";

        StartCounter();
        Dynamic(n,element,limit_size);
        timer = GetCounter();
        std::cout << "Dynamic: " << timer << std::endl;
        file << timer << std::endl;

    }
    file.close();
    std::cout << std::endl;






    //Heuristic vs Dynamic RESULT
    file.open("HvDResult.txt");
    std::cout << "Heuristic vs Dynamic RESULT" << std::endl;
    file << " Dynamic Heuristic" << std::endl;
    for (int n = count.start; n <=count.end ; n+=count.step) {
        int  limit_size = MAX * n * 0.1 ;
        std::cout << "Ilosc elementow: "  << n << " limit_size: " << limit_size << std::endl;
        SElement element[n];


        for (int i = 0; i < n; ++i) {
            element[i].size  =rand() % MAX +1;
            element[i].value  =rand() % MAX + 1;
        }

        file << n << " ";

        int result = Dynamic(n,element,limit_size);
        std::cout << "Dynamic: " << result <<std::endl;
        file << result << " ";


        result =Heuristic(n,element,limit_size);
        std::cout << "Heuristic: " << result <<std::endl;
        file << result << std::endl;


    }
    file.close();
    std::cout << std::endl;

    const SCount count3 = {

           100,
           50,
           1000,

       };

    //Heuristic vs Dynamic RESULT2
    file.open("HvDResult2.txt");
    std::cout << "Heuristic vs Dynamic RESULT2" << std::endl;
    file << " Dynamic Heuristic" << std::endl;
    for (int n = count3.start; n <=count3.end ; n+=count3.step) {
        int  limit_size = MAX * n * 0.1 ;
        std::cout << "Ilosc elementow: "  << n << " limit_size: " << limit_size << std::endl;
        SElement element[n];


        for (int i = 0; i < n; ++i) {
            element[i].size  =rand() % MAX +1;
            element[i].value  =rand() % MAX + 1;
        }

        file << n << " ";

        int result = Dynamic(n,element,limit_size);
        std::cout << "Dynamic: " << result <<std::endl;
        file << result << " ";


        result =Heuristic(n,element,limit_size);
        std::cout << "Heuristic: " << result <<std::endl;
        file << result << std::endl;


    }
    file.close();
    std::cout << std::endl;


    const SCount count2 = {

           1000,
           500,
           10000,

       };


    //Dynamic  timer
    file.open("Dynamic.txt");
    std::cout << "Dynamic timer" << std::endl;
    file << "b=100 b=n b=MAX*n*0.1" << std::endl;
    for (int n = count2.start; n <=count2.end ; n+=count2.step) {
        int  limit_size =  100 ;
        std::cout << "Ilosc elementow: "  << n << " limit_size: " << limit_size << std::endl;
        SElement element[n];


        for (int i = 0; i < n; ++i) {
            element[i].size  = rand() % MAX +1;
            element[i].value  = rand() % MAX + 1;
        }

        file << n << " ";


        StartCounter();
        Dynamic(n,element,limit_size);
        double timer = GetCounter();
        std::cout << "100: " << timer << std::endl;
        file << timer << " ";

        limit_size = n ;
        StartCounter();
        Dynamic(n,element,limit_size);
        timer = GetCounter();
        std::cout << "n: " << timer << std::endl;
        file << timer << " ";

        //stop
        if(n>4000){file <<  std::endl;continue;}
        limit_size = MAX * n * 0.1 ;
        StartCounter();
        Dynamic(n,element,limit_size);
        timer = GetCounter();
        std::cout << "MAX*n*0.1: " << timer << std::endl;
        file << timer << std::endl;

    }
    file.close();
    std::cout << std::endl;





    //Heuristic  timer
    file.open("Heuristic.txt");
    std::cout << "Heuristic timer" << std::endl;
    file << "b=100 b=n b=MAX*n*0.1" << std::endl;
    for (int n = count2.start; n <=count2.end ; n+=count2.step) {
        int  limit_size =  100 ;
        std::cout << "Ilosc elementow: "  << n << " limit_size: " << limit_size << std::endl;
        SElement element[n];


        for (int i = 0; i < n; ++i) {
            element[i].size  = rand() % MAX +1;
            element[i].value  = rand() % MAX + 1;
        }

        file << n << " ";


        StartCounter();
        Heuristic(n,element,limit_size);
        double timer = GetCounter();
        std::cout << "100: " << timer << std::endl;
        file << timer << " ";

        limit_size = n ;
        StartCounter();
        Heuristic(n,element,limit_size);
        timer = GetCounter();
        std::cout << "n: " << timer << std::endl;
        file << timer << " ";

        limit_size = MAX * n * 0.1 ;
        StartCounter();
        Heuristic(n,element,limit_size);
        timer = GetCounter();
        std::cout << "MAX*n*0.1: " << timer << std::endl;
        file << timer << std::endl;

    }
    file.close();
    std::cout << std::endl;





    /*
    double test[3] = {4,0.6,1.2};
    QuickSort(test,0,2);

    for (int i = 0; i < 3; ++i) {
        std::cout << test[i] << std::endl;
    }
    */
  return 0;
}
