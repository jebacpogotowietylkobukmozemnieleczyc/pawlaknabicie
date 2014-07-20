#ifndef LIST_H
#define LIST_H
#include <iostream>





typedef struct list_element {
    int id;
    list_element* next;
} list_element;

class CList{
    private:
    list_element* head;

    public:
    CList():head(NULL){};
    ~CList();
    void AddtoList(int);
    void DeleteElement(list_element* toDelete);
    void DeleteALL();
    void ShowList();
    list_element* Search(int);
    list_element* GetHead() {return head;};

};


#endif
