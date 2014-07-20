
#include "list.h"


void CList::AddtoList(int id){
    list_element* current = head;
    list_element* new_element = new list_element;

    new_element->id =id;
    new_element->next = NULL;

    if(current== NULL){
        head =new_element;
        return;
    }

    while(current->next != NULL )current=current->next;
    current->next = new_element;

}


void CList::AddtoListFirst(int id){

    list_element* new_element = new list_element;
    new_element->id =id;
    new_element->next = head;
    head = new_element;

}

list_element* CList::Search(int id){
    list_element* current =head;
    while(current != NULL && current->id!=id)current = current->next;
    return current;
}


void CList::ShowList(){
    list_element* current =head;
    while(current!=NULL){
            std::cout << current->id << " ";
            current = current->next;
    }
}

void CList::DeleteElement(list_element* toDelete){
    if(toDelete->next)
        DeleteElement(toDelete->next);
    delete toDelete;
}

void CList::DeleteFirst(){
    if(head){

        list_element * toDelete = head;
        head = head->next;
        delete toDelete;
    }
}


void CList::DeletefromList(int id){


    list_element * current = head;
//std::cout << id << " - " << current->id  << std::endl;

    if(current!= NULL){
    if( id==current->id){

        head =current->next;
        delete current;

        return;

    }

    while(current->next != NULL ){
            if(id == current->next->id)break;
            current=current->next;
    }
    if(current->next!=NULL){
        list_element * toDelete = current->next;
        current->next =current->next->next;

        delete toDelete;

    }
    return;
    }
}






CList::~CList(){if(head!=NULL){DeleteElement(head);head=NULL;}};
