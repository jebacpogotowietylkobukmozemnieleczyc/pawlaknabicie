#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string.h>
#include<fstream>
#include<math.h>
#include <windows.h>

#define __RANGE 100000
#define __REPETITION 1
#define __BUBBLE FALSE
//t
using namespace std;


struct Count{

    int start;
    int step;
    int end;
};



//BubbleSort

void BubbleSort(int a[], int size)
{
	for (int i = 0; i<size-1; i++)
        {
		for (int j=0; j<size-1-i; j++)
		{
			if (a[j] > a[j+1])
			{
				int tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
    }
}




//ShellSort





void ShellSort(int a[],int size){

    int gap;
    for(gap = 1; gap < size; gap = 3 * gap + 1);
    gap /= 9;
    if(!gap) gap++;

    while(gap)
    {


        for(int i = gap; i < size; i++) {
            int value = a[i];
            int j;
            for (j = i - gap; j >= 0 && a[j] > value; j -= gap) {
                a[j + gap] = a[j];
            }
        a[j + gap] = value;
        }
     gap /= 3;
    }
}

//Hesp sort

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


//Counting sort



void CountingSort(int a[],int size){

    int ca[__RANGE];
    int * na = new int[size];

    for(int i=0;i<__RANGE;i++)
        ca[i]=0;

    for(int i=0;i<size;i++)
        ca[a[i]]++;

    for(int i=0;i<__RANGE-1;i++)
        ca[i+1]+=ca[i];

    for(int i=size-1;i>=0;i--)
        na[--ca[a[i]]]=a[i];


    memcpy(a,na,sizeof(int)*size);
    delete[] na;

}

//QueryPerformanceCounter


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

    bool show =false;
    bool QueryPerformanceCounter=true;

    int * initial;
    int * result;
    int time_result[4][__REPETITION];

    clock_t startTime;
    clock_t endTime;
    clock_t clockTicksTaken;

    ofstream file;


    const string name_sort[4] = {"Bubblesort","Shellsort","Heapsort", "Countingsort"};

    const Count counter = {

        500000,
        500000,
        7500000,

    };

    file.open("result.txt");

    if(__BUBBLE==TRUE)file << " " << name_sort[0];
    file << " " << name_sort[1] << " " << name_sort[2] << " " << name_sort[3] << endl;
    for(int n = counter.start;n<=counter.end;n+=counter.step)
    {
        initial = new int[n];
        cout << "Number of objects: " << n << endl << endl;

        for(int r=0;r<__REPETITION;r++){

            cout << "Test: " << r +1 << endl << endl;


            for(int i =0;i<n;i++)
            {
                initial[i]=rand()%__RANGE;
            }


            for(int f=0;f<4;f++)
            {
                if(__BUBBLE==FALSE && f==0)continue;
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
                    BubbleSort(result,n);
                    break;

                case 1:
                    ShellSort(result,n);
                    break;

                case 2:
                    HeapSort(result,n);
                    break;

                case 3:
                    CountingSort(result,n);
                    break;
                }

                if(QueryPerformanceCounter)timeInSeconds = GetCounter();
                else{
                     endTime = clock();
                    clockTicksTaken = endTime - startTime;
                    timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
                }



                cout << name_sort[f]<< ": " << timeInSeconds << endl;
                time_result[f][r]= timeInSeconds *1000;

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

        file << n << " ";
        cout << "Average" << endl;
        for(int f=0;f<4;f++)
        {
            if(__BUBBLE==FALSE && f==0)continue;

            double sum = 0;
            for(int r=0;r<__REPETITION;r++)
            {
                sum +=time_result[f][r];

            }
            sum/=__REPETITION;
            cout << name_sort[f]<< ": " << sum << endl;
            file <<  sum << " " ;
        }
        file << endl;
    cout << endl;
    delete[] initial;
    }
    file.close();
    cout << "The end!" << endl;
    return 0;
}
