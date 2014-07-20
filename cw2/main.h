#ifndef MAIN_H
#define MAIN_H

//QueryPerformanceCounter

void StartCounter();
double GetCounter();




typedef struct Data{
    int id;
    std::string name;
    std::string surname;
} Data;



struct Count{

    int start;
    int step;
    int end;
};



#endif
