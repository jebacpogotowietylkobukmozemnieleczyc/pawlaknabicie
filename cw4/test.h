#ifndef TEST_H
#define TEST_H
#include "graph.h"
#include <sstream>
typedef bool (CGraph::*PMethodinAction)(int,int);
typedef void (CGraph::*PMethodbeforeAction)();


template < class T >
std::string to_string( T t )
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}




typedef struct SMethod{
    std::string name;
    PMethodbeforeAction methodbeforeaction;
    PMethodinAction methodinaction;
} SMethod;




typedef struct SFilename{
    std::string open;
    std::string save;
} SFilename;





typedef struct Count{

    int start;
    int step;
    int end;
} Count;

typedef struct STestProperties{
    std::string name;
    Count* counter;
    SFilename* filename;
    EShow show;
    EResult result;
    bool repeat;
    bool directed;
    int types;
    float * rate;
    SMethod * method;
} STestProperties;

class CTest{
  private:
    std::string name;
    Count * counter;
    SFilename * filename;
    EResult result;
    EShow show;
    bool repeat;



    double PCFreq = 0.0;
    __int64 CounterStart = 0;

    CGraph * graph;
    bool directed;
    int types;
    float * rate;
    SMethod* method;




  public:
    CTest(STestProperties* test_properties);
    //~CTest(){};

    void StartCounter();
    double GetCounter();

    int* CreateRandomArray(int size);

    void Testing();



};


#endif

