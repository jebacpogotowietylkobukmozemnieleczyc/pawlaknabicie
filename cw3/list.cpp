
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
CList::~CList(){if(head!=NULL){DeleteElement(head);head=NULL;}};
