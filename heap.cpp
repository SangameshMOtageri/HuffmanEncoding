#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include "heapinf.hpp"

using namespace std;
vector<struct node*> ndarr;

struct node{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
    int index;
};
struct node* newNode(int data){
    struct node *temp = new node;
    temp->val = data;
    temp->right = temp->left = temp->parent = NULL;
    return temp;
}
void pushtoarray(vector<struct node*> &ndarr, int val, int index){
    unsigned int pos = ndarr.size();
    struct node *temp = newNode(val);
    if(pos == 0){
        ndarr.push_back(temp);
        return;
    }
    float f = (float(pos)-1)/2;
    pos = floor(f);
    if(f > floor(f))
        ndarr[pos]->right = temp;
    else
        ndarr[pos]->left = temp;
    temp->parent = ndarr[pos];
    /*This is to note the position of the index of the 'twig'*/
    temp->index = index;
    ndarr.push_back(temp);
    return;
}
void heapifyinsert(int pos){
    if(pos > 0){
        struct node *temp = ndarr[pos];
        int data = temp->val;
        int index = temp->index;
        int ppos = floor((pos-1)/2);
        if(data < temp->parent->val){
            ndarr[pos]->val = ndarr[ppos]->val;
            ndarr[pos]->index = ndarr[ppos]->index;
            ndarr[ppos]->val = data;
            ndarr[ppos]->index = index;
            heapifyinsert(ppos);
        }
    }
}
void heapifydelete(int pos){
    int val, index;
    int min = pos;
    if(ndarr[pos]->right == NULL && ndarr[pos]->left == NULL){
        return;
    }
    if(ndarr[pos]->left != NULL)
        min = 2*pos + 1;
    if(ndarr[pos]->right != NULL)
        min = (ndarr[min]->val > ndarr[2*pos + 2]->val)?(2*pos + 2):min;
    if(ndarr[pos]->val > ndarr[min]->val){
        val = ndarr[pos]->val;
        index = ndarr[pos]->index;
        ndarr[pos]->val = ndarr[min]->val;
        ndarr[pos]->index = ndarr[min]->index;
        ndarr[min]->val = val;
        ndarr[min]->index = index;
        heapifydelete(min);
    }
}
int heapmainfunc(int val, int index, string cmd){
    int top_heap_index = 0, local_p = 0;
    if(cmd.compare("insert") == 0){
        pushtoarray(ndarr, val, index);
        heapifyinsert(ndarr.size() - 1);
    }else if((cmd.compare("delete")==0) || (cmd.compare("get")==0)){
        if(ndarr.size() <= 0)
            return -1;
        /*Get the top of the heap, this will have the lowest value. Once we get this, we must see
        to it that the index is also removed.*/
        top_heap_index = ndarr[0]->index;
        local_p = ceil(ndarr.size()/2 - 1);
        /*Now set the index, val of the top of the heap to the last entry in the heap tree.*/
        ndarr[0]->val = ndarr[ndarr.size() - 1]->val;
        ndarr[0]->index = ndarr[ndarr.size() - 1]->index;
        /*Since we removed the last entry in heap tree, update the parent of the last entry*/
        if(ndarr[local_p]->right != NULL)
            ndarr[local_p]->right = NULL;
        else
            ndarr[local_p]->left = NULL;
        /*Remove the last entry from the vector as this has already been readjusted to top of heap*/
        ndarr.pop_back();
        heapifydelete(0);
        return top_heap_index;
    }
    return 0;
}