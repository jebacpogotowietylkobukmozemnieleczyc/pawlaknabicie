#ifndef _N 500000
#define _N 500000
#endif

#ifndef BST_H
#define BST_H
#include <iostream>

typedef struct BSTNode{
    int id;
    std::string name;
    std::string surname;
    BSTNode* up;
    BSTNode* left;
    BSTNode* right;
} BSTNode;


typedef struct BSTarray{
    int id;
    std::string name;
    std::string surname;
 }BSTarray;



void AddtoBST(BSTNode* &head,int id,std::string name,std::string surname);
BSTNode* SearchBST(BSTNode* current,int id);
BSTNode* SearchBSTS(BSTNode* current,int id);
void DeletefromBST(BSTNode* p);

void ShowBST(BSTNode* current,int n);

int Height(BSTNode * v);
void inorder(BSTNode * v,BSTarray t[]);
BSTNode* Balance(BSTNode * v,int k);
BSTNode*  CreateBalance(BSTNode * n,BSTarray t[],int start,int end);

void DeleteAllBST(BSTNode * toDelete);


void Preorder(BSTNode * current);
void Inorder(BSTNode * current);
void Postorder(BSTNode * current);

#endif
