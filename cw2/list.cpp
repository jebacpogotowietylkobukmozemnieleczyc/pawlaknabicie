#include "list.h"


void AddtoList(list* &head,int id,std::string name,std::string surname){
    list* current = head;
    list* new_element = new list;

    new_element->id =id;
    new_element->name = name;
    new_element->surname = surname;


    if(current== NULL || id<current->id){

        new_element->next=current;
        head =new_element;
        return;

    }

    while(current->next != NULL ){
            if(id <= current->next->id)break;
            current=current->next;
    }

    new_element->next = current->next;
    current->next = new_element;



}




list* SearchList(list* head,int id){
    list* current =head;
    while(current != NULL && current->id!=id)current = current->next;
    return current;
}


void DeletefromList(list* & head,int id){
    list* current = head;

    if(current== NULL || id==current->id){
        head =current->next;
        delete current;

        return;

    }

    while(current->next != NULL ){
            if(id == current->next->id)break;
            current=current->next;
    }

    list* toDelete = current->next;
    current->next =current->next->next;

    delete toDelete;


    return;
}

