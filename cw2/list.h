
#ifndef LIST_H
#define LIST_H
#include <iostream>



typedef struct list {
    int id;
    std::string name;
    std::string surname;
    list* next;
} list;



void AddtoList(list* &head, int id,std::string name,std::string surname);
list* SearchList(list* head,int id);
void DeletefromList(list* &head,int id);
#endif
