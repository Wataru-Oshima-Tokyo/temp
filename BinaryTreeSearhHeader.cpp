//
//  BinaryTreeSearhHeader.cpp
//  BinaryTreeSearch
//
//  Created by Wataru Oshima on 2020/05/03.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include "BinaryTreeSearhHeader.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

template <class BSTT>
BinaryTreeSearchHeader<BSTT>::BinaryTreeSearchHeader()
{
    root = NULL;
}

template <class BSTT>
typename BinaryTreeSearchHeader<BSTT>::node*  BinaryTreeSearchHeader<BSTT>::createLeaf(BSTT key)
{
    node* n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::addLeaf(BSTT key)
{
    addLeafPrivate(key, root);
}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>:: addLeafPrivate(BSTT key, node* Ptr)
{
    if (root == NULL) {
        root = createLeaf(key);
    }
    else if (key < Ptr->key) {
        if (Ptr->left != NULL)
            addLeafPrivate(key, Ptr->left);
        else
            Ptr->left = createLeaf(key);
    }
    else if  (key > Ptr->key) {
           if (Ptr->right != NULL)
               addLeafPrivate(key, Ptr->right);
           else
               Ptr->right = createLeaf(key);
    } else {
        cout << "The key " << key << " has already been added to the tree" << endl;
    }
    
}
template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::printlnInOrder(){
    printlnInOrderPrivate(root);
}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::printlnInOrderPrivate(node* Ptr){
    if (root != NULL) {
        if (Ptr->left != NULL) {
            printlnInOrderPrivate(Ptr->left);
        }
        cout << Ptr->key << " ";
        if (Ptr->right != NULL) {
            printlnInOrderPrivate(Ptr->right);
        }
        
    }else {
        cout << "The tree is empty" << endl;
    }
}
template <class BSTT>
typename BinaryTreeSearchHeader<BSTT>::node* BinaryTreeSearchHeader<BSTT>::returnNode(BSTT key) {
    return returnNodePrivate(key, root);
}

template <class BSTT>
typename BinaryTreeSearchHeader<BSTT>::node* BinaryTreeSearchHeader<BSTT>::returnNodePrivate(BSTT key, node* Ptr) {
    
    if (Ptr != NULL) {
        if(Ptr->key == key) {
            return Ptr;
        }
        else {
            if (key < Ptr->key)
                return returnNodePrivate(key, Ptr->left);
            else
                return returnNodePrivate(key, Ptr->right);
        }
    } else
        return NULL;
}
template <class BSTT>
BSTT BinaryTreeSearchHeader<BSTT>::returnRootKey(){
    if (root !=NULL) {
        return root->key;
    }
    else
        return -1;
}
template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::printChildren(BSTT key){
    node* Ptr = returnNode(key);
    
    if (Ptr != NULL) {
        cout << "Parent node is " << Ptr->key << endl;
        Ptr->left == NULL ?
        cout << "Left child = NULL" << endl:
        cout << "Left child = " << Ptr->left->key << endl;
        
        Ptr->right == NULL ?
        cout << "Right child = NULL" << endl:
        cout << "Right child = " << Ptr->right->key << endl;
    } else
        cout << "The key " << key << " does not exist in the tree" << endl;
}

template <class BSTT>
BSTT BinaryTreeSearchHeader<BSTT>::findSmallest()
{
    return findSmallestPrivate(root);
}

template <class BSTT>
BSTT BinaryTreeSearchHeader<BSTT>::findSmallestPrivate(node* Ptr)
{

    if (root == NULL) {
        cout << "The tree is empty" << endl;
        return NULL;
    } else {
        if (Ptr->left != NULL) {
            return findSmallestPrivate(Ptr->left);
            }
        else
            return Ptr->key;
    }

}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::removeNode(BSTT key)
{
    removeNodePrivate(key, root);
}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::removeNodePrivate(BSTT key, node* parent)
{
    if (root != NULL) {
        if (root->key == key) {
            removeRootMatch();
        }
        else {
            if (key < parent->key && parent->left != NULL) {
                parent->left->key == key ?
                removeMatch(parent, parent->left, true):
                removeNodePrivate(key, parent->left);
            }
            else if (key > parent->key && parent->right != NULL) {
                parent->right->key == key ?
                removeMatch(parent, parent->right, false):
                removeNodePrivate(key, parent->right);
            }
            else
            {
                cout << "The key " << key << " was not found in the tree\n";
            }
        }
    } else {
        cout << "The tree is empty\n";
    }
}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::removeRootMatch()
{
    if (root != NULL) {
        node* delPtr = root;
        BSTT rootKey = root->key;
        BSTT smallestRightSubtree;
        
        //case 0 - no children
        if (root->left == NULL && root->right == NULL)
        {
            root = NULL;
            delete delPtr;
        }
        //case 1 - 1 child
        else if (root->left == NULL && root->right != NULL) {
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            cout << "The root node with key " << rootKey << " was deleted. " << "The new root contains key " << root->key << endl;
        }
        else if (root->left != NULL && root->right == NULL)
        {
        root = root->left;
            delPtr->left = NULL;
        delete delPtr;
        cout << "The root node with key " << rootKey << " was deleted. " << "The new root contains key " << root->key << endl;
            
        }
        // case 2 - 2 children
        
        else
        {
            smallestRightSubtree = findSmallestPrivate(root->right);
            removeNodePrivate(smallestRightSubtree, root);
            root->key = smallestRightSubtree;
            cout << "The root node with key " << rootKey << " was overwritten with key " <<  root->key << endl;
        }
        
        
    } else {
        cout << "The tree is empty\n";
    }
}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::removeMatch(node* parent, node* match, bool left)
{
    if (root != NULL) {
        node* delPtr;
        BSTT matchKey = match->key;
        BSTT smallestRightSubtree;
        
        //case 0 - no children
        if (match->left == NULL && match->right == NULL ) {
            delPtr = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }
        //case 1 - 1 child
        else if (match->left == NULL && match->right != NULL )
        {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }
        else if (match->left != NULL && match->right == NULL )
        {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed\n";
        }
        //case 2 - 2 children
        else
        {
            smallestRightSubtree =  findSmallestPrivate(match->right);
            removeNodePrivate(smallestRightSubtree, match);
            match->key = smallestRightSubtree;
        }
    } else {
        cout << "The tree is empty\n";
    }
}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::removeSubtree(node* Ptr)
{
    if (Ptr != NULL) {
        if (Ptr->left != NULL) {
            removeSubtree(Ptr->left);
        }
        if (Ptr->left != NULL) {
            removeSubtree(Ptr->right);
        }
//        cout << "Deleting the node containing key " << Ptr->key << endl;
        delete Ptr;
    }
}

template <class BSTT>
BinaryTreeSearchHeader<BSTT>::~BinaryTreeSearchHeader()
{
    removeSubtree(root);
}
template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::preOrder()
{
    preOrderPrivate(root);
}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::postOrder()
{
    postOrderPrivate(root);
}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::preOrderPrivate(node* Ptr)
{
    if (Ptr != NULL) {
        cout << Ptr->key << " ";
        preOrderPrivate(Ptr->left);
        preOrderPrivate(Ptr->right);
    }
    
}
template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::postOrderPrivate(node* Ptr)
{
    if (Ptr != NULL) {
        postOrderPrivate(Ptr->left);
        postOrderPrivate(Ptr->right);
        cout << Ptr->key << " ";
    }
}

template <class BSTT>
void BinaryTreeSearchHeader<BSTT>::randomNumberGenerator(BSTT list[], int length)
{
    int m = length*2;
    for (int i = 0; i<length; i++) {
        
        list[i] = rand()%m + 1;
    }
}

