#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string.h>
#include<fstream>
#include<math.h>
#include <windows.h>

#define __RANGE 100000
#define __REPETITION 2
#define __QUICK_RM FALSE
#define __QUICK_MR  FALSE

using namespace std;
//t

struct Count{

    int start;
    int step;
    int end;
};





void Random(int a[],int size){

     for(int i =0;i<size;i++)
        a[i]=rand()%__RANGE;
}

void Constant(int a[],int size){
    for(int i =0;i<size;i++)
        a[i]=__RANGE/2;

}
void Ascending(int a[],int size) {
    for(int i =0;i<size;i++)
        a[i]=i;
    }
void Descending(int a[],int size) {
    for(int i =0;i<size;i++)
        a[i]=size-i-1;
    }

void AsDescending(int a[],int size) {
    int current = -1;
    for(int i =0;i<size/2;i++){
        current+=2;
        a[i]=current;
    }
    current++;
    for(int i = size/2;i<size;i++){
        current-=2;
        a[i]=current;
    }

}

void DesAscending(int a[],int size) {
    int current = size+1;
    for(int i =0;i<size/2;i++){
        current-=2;
        a[i]=current;
    }
    current--;
    for(int i = size/2;i<size;i++){
        current+=2;
        a[i]=current;
    }

}










//Quick sort
/*
void nQuickSort(int a[],int start,int end){

    int i=(start+end)/2;
    int pivot=a[i];
    int j =end;

    for(i=start;i<=j;i++){

        if(a[i]>=pivot){

        while (a[j]>pivot)
            --j;


        if(i<=j){
            int tmp = a[i];
            a[i]=a[j];
            a[j]=tmp;
            j--;
        }
        }
    }

    if(start<j) QuickSort(a,start,j);
    if(i<end) QuickSort(a,i,end);


}

*/


void QuickSort(int* a, int start, int end) {
    int i =(start+end)/2;
    int pivot = a[i];
    int j = end;
    i = start;
    while(i<=j){
        for (i;a[i]<pivot ;++i);
        for (j;a[j]>pivot ;--j );
        if (i > j)continue;
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        ++i;
        --j;
    }
    if(start<j)QuickSort(a,start,j);
    if(i<end)QuickSort(a,i,end);
}




//Merge sort


void MergeSort(int a[],int na[],int start,int end){

    int medium = (start+end+1)/2;
    if(medium - start>1)MergeSort(a,na,start,medium-1);
    if(end-medium>0)MergeSort(a,na,medium,end);

    int rabbit = start;
    int elephant = medium;
    for(int i=start;i<=end;i++)
        na[i] = ((rabbit==medium) || ((elephant<=end) && (a[rabbit]> a[elephant]))) ? a[elephant++] : a[rabbit++];
    for(int i=start;i<=end;i++)a[i]=na[i];
}


//heap sort

void Heapify(int a[],int i, int size){
    int l=i*2+1;

    int max = i;
    if(l<size && a[l] > a[i])
        max = l;
        l++;
    if(l<size && a[l] > a[max])
        max = l;

    if(max!=i){
        int tmp=a[i];
        a[i]=a[max];
        a[max]=tmp;

    Heapify(a,max,size);
    }
}

void BuildHeap(int a[],int size){
    for(int i=(size-2)/2;i>=0;i--)
        Heapify(a,i,size);

}


void HeapSort(int a[],int size){
    BuildHeap(a,size);
    for (int i= size-1;i>=1;i--){
        int tmp = a[i];
        a[i]=a[0];
        a[0]=tmp;

        Heapify(a,0,i);
    }
}




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
    return double(li.QuadPart-CounterStart)/PCFreq;
}









int main()
{

    srand((int)time(NULL));


    const int pp  =10;
    int  ppp[pp];
    DesAscending(ppp,pp);
    for(int i = 0; i<pp;++i)std::cout << ppp[i] << " ";


     const int n =11;
     int test[n] = {82,30,11,0,5,0,2,7,4,3,11};
     int test2[n] = {82,30,11,0,5,0,2,7,4,3,11};

     std::cout << "QuickSort" << std::endl;
     QuickSort(test,0,n-1);
     for(int i = 0; i<n;++i)std::cout << test[i] << " ";
     std::cout << std::endl;


     std::cout << "HeapSort" << std::endl;
     HeapSort(test2,n);
     for(int i = 0; i<n;++i)std::cout << test2[i] << " ";
     std::cout << std::endl;

    const int m  =100;
    int  initial[m];

    std::cout <<  "Random: " << std::endl;
    Random(initial,m);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";
    std::cout << std::endl << "Sort: " << std::endl;
    QuickSort(initial,0,m-1);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";

    std::cout << std::endl << std::endl;

    std::cout <<  "Stale : " << std::endl;
    Constant(initial,m);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";
    std::cout << std::endl << "Sort: " << std::endl;
    QuickSort(initial,0,m-1);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";

    std::cout << std::endl << std::endl;

    std::cout <<  "Rosna : " << std::endl;
    Ascending(initial,m);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";
    std::cout << std::endl << "Sort: " << std::endl;
    QuickSort(initial,0,m-1);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";

    std::cout << std::endl << std::endl;

    std::cout <<  "Male : " << std::endl;
    Descending(initial,m);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";
    std::cout << std::endl << "Sort: " << std::endl;
    QuickSort(initial,0,m-1);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";

    std::cout << std::endl << std::endl;

    std::cout <<  "RM : " << std::endl;
    AsDescending(initial,m);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";
    std::cout << std::endl << "Sort: " << std::endl;
    QuickSort(initial,0,m-1);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";


    std::cout << std::endl << std::endl;

    std::cout <<  "MR : " << std::endl;
    DesAscending(initial,m);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";
    std::cout << std::endl << "Sort: " << std::endl;
    QuickSort(initial,0,m-1);
    for(int i = 0; i<m;++i)std::cout << initial[i] << " ";


    std::cout << std::endl << std::endl;

    const int t1  =99999;
    int  q1[t1];

    AsDescending(q1,t1);
    StartCounter();
    QuickSort(q1,0,t1-1);
    std::cout <<  "RM 99.999: " << GetCounter() <<std::endl;

    const int t2  =100000;
    int  q2[t2];

    AsDescending(q2,t2);
    StartCounter();
    QuickSort(q2,0,t2-1);
    std::cout <<  "RM 100.000: " << GetCounter() <<std::endl;

    const int t3  =100001;
    int  q3[t3];

    AsDescending(q3,t3);
    StartCounter();
    QuickSort(q3,0,t3-1);
    std::cout <<  "RM 100.001: " << GetCounter() <<std::endl;


     std::cout << std::endl << std::endl;



    DesAscending(q2,t2);
    StartCounter();
    QuickSort(q2,0,t2-1);
    std::cout <<  "MR 100.000: " << GetCounter() <<std::endl;




    DesAscending(q1,t1);
    StartCounter();
    QuickSort(q1,0,t1-1);
    std::cout <<  "MR 99.999: " << GetCounter() <<std::endl;




    DesAscending(q3,t3);
    StartCounter();
    QuickSort(q3,0,t3-1);
    std::cout <<  "MR 100.001: " << GetCounter() <<std::endl;


/*




    bool show =false;
    bool QueryPerformanceCounter=true;
    int * initial;
    int * result;
    int * na ;
    int time_result[4][6];

    clock_t startTime;
    clock_t endTime;
    clock_t clockTicksTaken;

    ofstream file;


    const string name_sort[3] = {"Heap sort","Merge sort","Quick sort"};
    const string type[6]={"Losowe","Stale","Rosnace","Malejace","Rosnaco-malejaca","Malejaco-rosnaca"};

    const Count counter = {

        1000000,
        500000,
        8000000,

    };

    file.open("result.txt");
    file << " " << "Heapsort(L)" << " " << "Mergesort(L)" << " " << "Quicksort(L)"
    << " " << "Heapsort(S)" << " " << "Mergesort(S)" << " " << "Quicksort(S)"
    << " " << "-" << " " << "Heapsort(R)" << " " << "Mergesort(R)" << " " << "Quicksort(R)"
    << " " << "Heapsort(M)" << " " << "Mergesort(M)" << " " << "Quicksort(M)"
    << " " << "-" << " " << "Heapsort(RM)" << " " << "Mergesort(RM)" << " ";
    if(__QUICK_RM==TRUE) file << "Quicksort(RM)";
    file << " " << "Heapsort(MR)" << " " << "Mergesort(MR)" << " ";
    if(__QUICK_MR==TRUE)file << "Quicksort(MR)";
    file    << endl;

    for(int n = counter.start;n<=counter.end;n+=counter.step)
    {
        initial = new int[n];
        cout << "Number of objects: " << n << endl << endl;


        int tt =0;
        for(int t=0;t<6;t++){

            //Blokada typów
            if(t==9)continue;

            cout << "Typ: " << type[t] << endl << endl;


            if(tt%2==0)file << n << " ";
            tt++;
            switch(t)
                {
                case 0:
                    Random(initial,n);
                    break;

                case 1:
                    Constant(initial,n);
                    break;

                case 2:
                    Ascending(initial,n);
                    break;


                case 3:
                    Descending(initial,n);
                    break;

                case 4:
                    AsDescending(initial,n);
                    break;

                case 5:
                    DesAscending(initial,n);
                    break;

            }


            for(int f=0;f<3;f++)
            {


                //Blokada sortowania
                if(__QUICK_RM==FALSE && f==2 && t==4)continue;
                if(__QUICK_MR==FALSE && f==2 && t==5)continue;

                result = new int[n];
                memcpy(result,initial,sizeof(int)*n);

                //test
                if(show==true)
                {
                    for(int i =0;i<n;i++)
                    {
                        cout << result[i] << " ";
                        file << result[i] << " ";
                    }
                    cout << endl;
                    file <<endl <<endl;
                }
                //end

                double timeInSeconds;
                if(QueryPerformanceCounter)StartCounter();
                else startTime = clock();

                switch(f)
                {
                case 0:
                   HeapSort(result,n);
                   break;

                case 1:
                    na = new int[n];
                    MergeSort(result,na,0,n-1);
                    delete[] na;
                    break;

                case 2:
                    QuickSort(result,0,n-1);
                    break;


                }



                if(QueryPerformanceCounter)timeInSeconds = GetCounter() ;
                else{
                     endTime = clock();
                    clockTicksTaken = endTime - startTime;
                    timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
                }


                time_result[f][t]= timeInSeconds * 1000;
                cout << name_sort[f]<< ": " << time_result[f][t] << endl;
                file <<   time_result[f][t] << " ";


                //test2
                if(show==true)
                {
                    cout << "Sorted: " << n << endl;

                    for(int i =0;i<n;i++)
                    {
                        cout << result[i] << " ";
                        file << result[i] << " ";
                    }
                    cout << endl << endl;
                    file <<endl <<endl;
                }
                //end

            delete[] result;
            }
            cout << endl ;

        }


    cout << endl;
    file << endl ;
    delete[] initial;
    }
    file.close();


    */
    cout << "The end!" << endl;
    return 0;
}
