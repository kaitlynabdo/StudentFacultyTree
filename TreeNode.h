#include <iostream>
#ifndef TREENODE_H
#define TREENODE_H

using namespace std;

template <class T>
class TreeNode{

public:
    TreeNode();
    TreeNode(T n); // k = key
    ~TreeNode();

    T key;
    TreeNode *left;
    TreeNode *right;
};

template <class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){
    key = k;
    left = NULL;
    right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

#endif
