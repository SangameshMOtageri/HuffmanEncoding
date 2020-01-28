#include "pch.h"
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include "heapinf.hpp"

using namespace std;

struct namepair {
    char v;
    unsigned int f;
};
struct leaf {
    char ch;
    int val;
    struct leaf* left;
    struct leaf* right;
    struct leaf* parent;
};
struct leaf* newleaf() {
    struct leaf* temp = new leaf;
    temp->left = NULL;
    temp->right = NULL;
    temp->val = 0;
    temp->parent = NULL;
    temp->ch = '$';
    return temp;
}
void print_code_per_character(vector<struct leaf*> twig) {
    struct leaf* temp = twig[0];
    unsigned int i = 0;
    while (temp->ch != '$') {
        cout << "\n" << temp->ch << "::\t";
        while (temp->parent != NULL) {
            if (temp->parent->left == temp) {
                cout << "0";
            }
            else {
                cout << "1";
            }
            temp = temp->parent;
        }
        i++;
        temp = twig[i];
    }
}
char testvect(char a) {
    if (a == 'a')
        return 'b';
    return 'c';
}
#if 0
int huffman(char *t, unsigned int l) {
    int i;
    for (i = 0; i < l; i++) {
        cout << "haha\n";
    }
    return i;
}
#endif
#if 1
int huffman(char *input, unsigned int len) {
    
    vector<namepair> nodes;
    vector<struct leaf*> twig;
    struct namepair np;
    struct leaf* temp;
    unsigned int charfre[126] = { 0 };
    unsigned int i, j, l = 0;
    //transform(input.begin(), input.end(), input.begin(), ::tolower);
    j = len;
    for (i = 0; i < j; i++) {
        charfre[input[i]]++;
    }
    for (i = 0; i < 126; i++) {
        if (charfre[i] == 0)
            continue;
        np.v = (char)i;
        np.f = charfre[i];
        nodes.push_back(np);
        l++;
    }
    for (i = 0; i < l; i++) {
        twig.push_back(newleaf());
        twig[i]->val = nodes[i].f;
        twig[i]->ch = nodes[i].v;
        heapmainfunc(twig[i]->val, i, "insert");
        cout << twig[i]->val << " " << i << "\n";
    }
    while (1) {
        i = heapmainfunc(0, 0, "get");
        j = heapmainfunc(0, 0, "get");
        if (i == -1 || j == -1)
            break;
        temp = newleaf();
        temp->val = twig[i]->val + twig[j]->val;
        temp->left = twig[i];
        temp->right = twig[j];
        twig[i]->parent = twig[j]->parent = temp;
        twig.push_back(temp);
        heapmainfunc(temp->val, twig.size() - 1, "insert");
        l++;
    }
    print_code_per_character(twig);
    system("PAUSE");
    return 0;
}
#endif
