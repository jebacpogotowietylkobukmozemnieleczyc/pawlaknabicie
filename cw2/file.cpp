#include "list.h"


void AddtoList(list*head,int id,std::string name,std::string surname){
    list* previous = head;
    list* current = new list;
    current->id =id;
    current->name = name;
    current->surname = surname;

    if(previous == NULL){

        current->next==NULL;
        previous = current;
        head =previous;

    }
    else{
        current->next = previous->next;
        previous->next= current;
    }
}
