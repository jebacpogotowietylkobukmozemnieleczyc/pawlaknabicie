#include "bst.h"
#include <stdlib.h>

void AddtoBST(BSTNode* &head,int id,std::string name,std::string surname){

    BSTNode* new_element = new BSTNode;
    new_element->id = id;
    new_element->name = name;
    new_element->surname =surname;
    new_element->left = NULL;
    new_element->right = NULL;

    BSTNode* current = head;


    if(current==NULL) head=new_element;
    else{
        while(true){
            if(id<current->id){
                if(current->left==NULL){
                    current->left=new_element;
                    break;
                }
                else current = current->left;
            }
            else{
                if(current->right == NULL){
                    current->right = new_element;
                    break;
                }
                else current = current->right;
            }
        }
    }
    new_element->up = current;
    return ;
}


BSTNode * SearchBST(BSTNode* current,int id){
    while(current!=NULL && current->id!=id)
        if(id<current->id)current = current->left;
        else current = current->right;
    return current;
}


BSTNode * SearchBSTS(BSTNode* current,int id){
    while(current!=NULL && current->id!=id){
        std::cout << current->id << std::endl;
        if(id<current->id)current = current->left;
        else current = current->right;
    }
    return current;
}


void DeletefromBST(BSTNode* p){

    BSTNode* toDelete = p;
    if(toDelete!=NULL){
        if(toDelete->right!=NULL){

            toDelete=toDelete->right;

            while(toDelete->left!=NULL)toDelete=toDelete->left;


            p->id = toDelete->id;
            p->name = toDelete->name;
            p->surname = toDelete->surname;

            if(toDelete->right==NULL){
                if(toDelete->up->right==toDelete)toDelete->up->right = NULL;
                else toDelete->up->left = NULL;
                delete toDelete;
                return;
            }
            else DeletefromBST(toDelete);

        }
        else if(toDelete->left!=NULL){
            toDelete=toDelete->left;
            while(toDelete->right!=NULL)toDelete=toDelete->right;

            p->id = toDelete->id;
            p->name = toDelete->name;
            p->surname = toDelete->surname;

            if(toDelete->left==NULL){
                if(toDelete->up->right==toDelete)toDelete->up->right = NULL;
                else toDelete->up->left = NULL;

                delete toDelete;
                return;
            }
            else DeletefromBST(toDelete);

        }
        else{


        if(toDelete->up!=NULL){
        if(toDelete->up->right==toDelete)toDelete->up->right = NULL;
        else toDelete->up->left = NULL;
        }

        delete toDelete;
        }
    }
}

void ShowBST(BSTNode* current,int n){
    if(current->right!=NULL)ShowBST(current->right,n+2);
    for(int i=0;i<n;i++)std::cout << ".";
    std::cout << current->id << std::endl;
    if(current->left!=NULL)ShowBST(current->left,n+2);
}



//Height

int Height(BSTNode * v)
{
    static int max =0;

  if(v)
  {

    if(v->left==NULL && v->right==NULL){
        BSTNode * p = v;
        int l =0;

        while(p->up!=NULL){

                l++;
                p=p->up;
        }
        if(l>max)max=l;
    }



    Height(v->left);
    Height(v->right);

  }
  return max;
}



//Inorder

void inorder(BSTNode * v,BSTarray t[], int* i)
{

  if(v)
  {

    inorder(v->left,t,i);


    t[(*i)].id = v->id;
    t[(*i)].name = v->name;
    t[(*i)].surname = v->surname;
    (*i)++;

    inorder(v->right,t,i);

  }
}

//Balance

BSTNode* Balance(BSTNode * v,int k)
{
    BSTarray* t = new BSTarray[k];
    int ti = 0;
    int *i = &ti;
    inorder(v,t,i);


    DeleteAllBST(v);
    BSTNode* newBST = NULL;

    newBST= CreateBalance(newBST,t,0,k-1);
    delete[] t;
    return newBST;

}

BSTNode* CreateBalance(BSTNode * v,BSTarray t[],int start,int end)
{

    static int test = 0;

    int average=(start+end)/2;


        AddtoBST(v,t[average].id,t[average].name,t[average].surname);
    test++;


    if(start<=average-1)v = CreateBalance(v,t,start,average-1);
    if(average+1<=end)v = CreateBalance(v,t,average+1,end);

    return v;

}


//Delete_All

void DeleteAllBST(BSTNode * toDelete)
{
  if(toDelete!=NULL)
  {
    DeleteAllBST(toDelete->left);
    DeleteAllBST(toDelete->right);
    delete toDelete;
  }
}






void Preorder(BSTNode * current)
{
    if(current!=NULL){
        std::cout << current->id << " " ;
        Preorder(current->left);
        Preorder(current->right);
    }
}

void Inorder(BSTNode * current)
{
    if(current!=NULL){

        Inorder(current->left);
        std::cout << current->id << " " ;
        Inorder(current->right);
    }
}

void Postorder(BSTNode * current)
{
    if(current!=NULL){

        Postorder(current->left);
        Postorder(current->right);
        std::cout << current->id << " " ;
    }
}





