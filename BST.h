#include <iostream>
#include "TreeNode.h"
#ifndef BST_H
#define BST_H
using namespace std;

template <class T>
class BST{
private:
    TreeNode<T> *root;

public:
    BST();
    ~BST();

    bool search (T value);
    void insert (T value);
    T searchObject(T value);

    //helper functions
    bool isEmpty();
    TreeNode<T>* getMin();
    TreeNode<T>* getMax();
    void printTree();
    void recPrint(TreeNode<T> *node);
    bool deleteNode(T value);
    TreeNode<T>* getSuccessor(TreeNode<T> *d);
};

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
BST<T>::~BST(){

}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if (node == NULL)
        return;
    recPrint(node->left);
    node->key.printInfo();
    recPrint(node->right);
}

template <class T>
void BST<T>::printTree(){
    recPrint(root);
}

template <class T>
TreeNode<T>* BST<T>::getMax(){
    TreeNode<T> *curr = root;
    if (root == NULL)
        return NULL;

    while(curr->right != NULL){
        curr = curr->right; //keep going down all the way to the right
    }
    return curr;
}

template <class T>
TreeNode<T>* BST<T>::getMin(){
    TreeNode<T> *current = root;
    if (root == NULL)
        return NULL;

    while(current->left != NULL){
        current = current->left; //keep going down all the way to the left
    }
    return current;
}

template <class T>
void BST<T>::insert(T value){
    TreeNode<T> *node = new TreeNode<T>(value);
    if(root == NULL){
        root = node;
    }
    else{ //tree is not empty
        TreeNode<T>* current = root;
        TreeNode<T>* parent = NULL;

        while(current != nullptr){
            parent = current;
            if(value == current->key) {
                break;
            }
            if(value < current->key){
                current = current->left;
                if (current == NULL){
                    parent->left = node;
                    break;
                }
            }
            else if (value > current->key){
                current = current->right;
                if (current == NULL){
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::search(T value){
    if(root == NULL){
        return false;
    }
    else{
        TreeNode<T> *current = root;
        while(current->key != value){
            if(value < current ->key){
                current = current->left;
            }
            else
                current = current->right;

            if (current == NULL)
                return false;
        }
        return true;
    }
}

template <class T>
T BST<T>::searchObject(T value){
    if(root == NULL){
        return T();
    }
    else{
        TreeNode<T> *current = root;
        while(current->key != value){
            if(value < current ->key){
                current = current->left;
            }
            else
                current = current->right;
        }
        return current->key;
    }
}

template <class T>
bool BST<T>::deleteNode(T value){
    if(root == NULL)
        return false;
    TreeNode<T> *parent = root;
    TreeNode<T> *current = root;
    bool isLeft = true;

    while(current->key != value){ // find node to delete
        parent = current;

        if (value < current->key){
            isLeft = true;
            current = current->left;
        }
        else{
            isLeft = false;
            current - current->right;
        }

        if(current == NULL){ // value DNE
            return false;
        }
    }
    //if we make it here we found the node to be deleted
    if(current->right == NULL && current->left == NULL){
        //node is a leaf w no children
        if(current == root)
            root = NULL;

        else if(isLeft)
            parent->left = NULL;

        else
            parent->right = NULL;

    }
    else if(current->right == NULL){ //left child only
        if (current == root)
            root = current->left;

        else if (isLeft)
            parent->left = current->left;

        else
            parent->right = current->left;

    }
    else if(current->left == NULL){ // right child only
        if (current == root)
            root = current->right;

        else if (isLeft)
            parent->left = current->right;

        else
            parent->right = current->right;

    }
    else{ //the node to be deleted has two children
        TreeNode<T> *successor = getSuccessor(current);
        if(current ==root){
            root = successor;
        }
        else if(isLeft){
            parent->left = successor;
        }
        else{
            parent->right = successor;
        }
        successor->left = current->left;
    }
    return true;
}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){ // d is the node to get deleted
    TreeNode<T> *current = d->right;
    TreeNode<T> *sp = d; //successor's parent
    TreeNode<T> *successor = d;

    while (current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }
    //we found successor
    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}


#endif
