#include <iostream>
#include <fstream>
#include "main.h"
#include "list.h"
#include "bst.h"

#include <windows.h>

#define LIST FALSE
#define BST TRUE
#define BBST TRUE


using namespace std;


Data data[_N];












int main()
{

     BSTNode * root = NULL;
     const int n =12;
     int test[n] = {17,22,11,2,4,7,3,28,9,10,35,92};
     for(int i = 0; i<n;++i)AddtoBST(root,test[i]," "," ");

    std::cout << "BST" << std::endl;
     Preorder(root);
     std::cout << std::endl;

     Inorder(root);
     std::cout << std::endl;

     Postorder(root);
     std::cout << std::endl;



    root = Balance(root,12);

    std::cout << "BBST" << std::endl;
    Preorder(root);
     std::cout << std::endl;

     Inorder(root);
     std::cout << std::endl;

     Postorder(root);
     std::cout << std::endl;





     DeleteAllBST(root);


/*
    list* head = NULL;
    ifstream file;

    file.open( "result.txt" );





bool show =FALSE;

 const Count cAddList = {

        3000,
        3000,
        45000,

    };

    for(int i = 0;i<_N;i++){
        int id;
        string name;
        string surname;
        file >> id >> name >> surname;

        data[i].id = id;
        data[i].name = name;
        data[i].surname = surname;
    }
file.close();

cout << "Plik wczytany." << endl;

if(LIST==TRUE){
ofstream result_list_add;
ofstream result_list_search;
ofstream result_list_delete;


result_list_add.open("result_list_add.txt");
result_list_search.open("result_list_search.txt");
result_list_delete.open("result_list_delete.txt");



for(int n =cAddList.start;n<=cAddList.end;n+=cAddList.step){

head=NULL;
 StartCounter();
    for(int i = 0;i<n;i++){
        AddtoList(head,data[i].id,data[i].name,data[i].surname);
}
double time = GetCounter();

result_list_add << n << " " <<  (int)time << endl;
cout << "Add: " << n << " " <<  time << endl;

    list* current =head;
     if(show){
     //show

    while(current!=NULL){
        cout << current->id <<  " " << current->name << " " << current->surname << endl;
        current = current->next;
    }
    }

    //delete all list

    int* a  = new int[n];
    int m = n;
    for(int i =0;i<n;i++){
        a[i]=data[i].id;
    }



    double sum = 0;
    for(int i = 0;i<n;i++){
        int s  =rand() % m;


        StartCounter();
        SearchList(head,a[i]);
        time = GetCounter();

        //int tmp = a[s];
        //a[s] = a[m-1];
        //a[m-1] = tmp;


        if(m>1)m--;

        sum+=time;

    }
    sum/=n;
    delete[] a;






result_list_search << n << " " <<  sum << endl;
cout << "Search: " << n << " " <<  sum << endl;

     a  = new int[n];
     m = n;
    for(int i =0;i<n;i++){
        a[i]=data[i].id;
    }



     sum = 0;
    for(int i = 0;i<n;i++){
        int s  =rand() % m;


        StartCounter();
        DeletefromList(head,a[s]);
        time = GetCounter();

        int tmp = a[s];
        a[s] = a[m-1];
        a[m-1] = tmp;


        if(m>1)m--;

        sum+=time;

    }

    delete[] a;



result_list_delete << n << " " <<  (int)sum << endl;
cout << "Delete: " << n << " " <<  sum << endl;







    current = head;
    while(current!=NULL){
        list* next = current->next;
        delete current;
        current = next;
    }
}



result_list_add.close();
result_list_search.close();
result_list_delete.close();



}
//BST
const Count cAddBST = {

        100000,
        25000,
        500000,

    };
if(BST==TRUE){




BSTNode* root = NULL;



ofstream result_BST_add;
ofstream result_BST_search;
ofstream result_BST_delete;


result_BST_add.open("result_BST_add.txt");
result_BST_search.open("result_BST_search.txt");
result_BST_delete.open("result_BST_delete.txt");



for(int n =cAddBST.start;n<=cAddBST.end;n+=cAddBST.step){

root=NULL;
 StartCounter();
    for(int i = 0;i<n;i++){
        AddtoBST(root,data[i].id,data[i].name,data[i].surname);
}
double time = GetCounter();

result_BST_add << n << " " <<  (int)time << endl;
cout << "BST Add: " << n << " " <<  time << endl;

if(show)ShowBST(root,1);









 int* a  = new int[n];
    int m = n;
    for(int i =0;i<n;i++){
        a[i]=data[i].id;
    }



    double sum = 0;
    for(int i = 0;i<n;i++){
        int s  =rand() % m;


        StartCounter();
        SearchBST(root,a[i]);
        time = GetCounter();

        //int tmp = a[s];
        //a[s] = a[m-1];
        //a[m-1] = tmp;


        if(m>1)m--;

        sum+=time;

    }
    sum/=n;
    delete[] a;






result_BST_search << n << " " <<  sum << endl;
cout << "BST Search: " << n << " " <<  sum << endl;



//Delete BST


  a  = new int[n];
     m = n;
    for(int i =0;i<n;i++){
        a[i]=data[i].id;
    }



     sum = 0;
    for(int i = 0;i<n;i++){
        int s  =rand() % m;


        StartCounter();
        BSTNode* wp = SearchBST(root,a[i]);
        DeletefromBST(wp);
        time = GetCounter();

        int tmp = a[s];
        a[s] = a[m-1];
        a[m-1] = tmp;


        if(m>1)m--;

        sum+=time;

    }

    delete[] a;



result_BST_delete << n << " " <<  (int)sum << endl;
cout << "BST Delete: " << n << " " <<  sum << endl;









}

result_BST_add.close();
result_BST_search.close();
result_BST_delete.close();






}
if(BBST==TRUE){

        BSTNode* root2 = NULL;

ofstream result_BBST_search;


result_BBST_search.open("result_BBST_search.txt");



for(int n =cAddBST.start;n<=cAddBST.end;n+=cAddBST.step){

root2=NULL;
 StartCounter();
    for(int i = 0;i<n;i++){
        AddtoBST(root2,data[i].id,data[i].name,data[i].surname);
}
double time = GetCounter();


cout << "BBST Add: " << n << " " <<  time << endl;

if(show)ShowBST(root2,1);
//cout << "Height: " << Height(root2) << endl;

 int* a  = new int[n];
    int m = n;
    for(int i =0;i<n;i++){
        a[i]=data[i].id;
    }


    BSTNode* newroot = NULL;

    newroot = Balance(root2,n);


if(show)ShowBST(newroot,1);

//cout << "Height: " << Height(newroot) << endl;



    double sum = 0;
    for(int i = 0;i<n;i++){
        int s  =rand() % m;


        StartCounter();
        SearchBST(newroot,a[i]);
        time = GetCounter();

        //int tmp = a[s];
        //a[s] = a[m-1];
        //a[m-1] = tmp;


        if(m>1)m--;

        sum+=time;

    }




sum/=n;



result_BBST_search << n << " " <<  sum << endl;
cout << "BBST Search: " << n << " " <<  sum << endl;





//SearchBSTS(newroot,99);
m = n;
sum = 0;
    for(int i = 0;i<n;i++){
        int s  =rand() % m;


        StartCounter();
        BSTNode* wp = SearchBST(newroot,a[s]);
        DeletefromBST(wp);
        time = GetCounter();

        int tmp = a[s];
        a[s] = a[m-1];
        a[m-1] = tmp;


        if(m>1)m--;

        sum+=time;

    }

    delete[] a;




cout << "BBST Delete: " << n << " " <<  sum << endl;









}

result_BBST_search.close();

}

*/
    cout << "Hello world!" <<   endl;
    return 0;
}
