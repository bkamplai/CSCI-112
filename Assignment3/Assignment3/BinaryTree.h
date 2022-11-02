//
//  BinaryTree.h
//  Assignment3
//
//  Created by Brandon Kamplain on 4/11/22.
//

#ifndef BinaryTree_h
#define BinaryTree_h
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

template<class T> //T; datatype of the elemement of the nodes in the tree
struct nodeType
{
    T info; //data
    nodeType<T>* llink; //left subtree
    nodeType<T>* rlink; //right subtree
};

template<class T>
class BinaryTree
{
public:
    //assignment
    const BinaryTree<T>& operator =(const BinaryTree<T>& otherTree);
    
    //height - node and leaf counters
    bool isEmpty() const;
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeafCount() const;
    
    //traversals
    void inOrderTraversal(ofstream &ofs) const;
    void postOrderTraversal(ofstream &ofs) const;
    void preOrderTraversal(ofstream &ofs) const;
    
    //paramaterized traversals will actually do the work
    //paramater visit specifies the actual action taken at each node
    void inOrderTraversal(void(*visit)(T& item)) const;
    void postOrderTraversal(void(*visit)(T& item)) const;
    void preOrderTraversal(void(*visit)(T& item)) const;
    
    void destroyTree(); //deallocate space for each node
    
    BinaryTree();
    BinaryTree(const BinaryTree<T>& otherTree); //copy constructor
    ~BinaryTree();
    
protected:
    nodeType<T>* root;
    
private:
    void copyTree(nodeType<T>*& copiedTreeRoot, nodeType<T>* otherTreeRoot);
    void destroy(nodeType<T>*& p);
    
    void inOrder(nodeType<T>* p, ofstream &ofs) const;
    void postOrder(nodeType<T>* p, ofstream &ofs) const;
    void preOrder(nodeType<T>* p, ofstream &ofs) const;
    
    //paramaterized traversals will actually do the work
    //paramater visit specifies the actual action taken at each node
    void inOrder(nodeType<T>* p, void(*visit)(T& item)) const;
    void postOrder(nodeType<T>* p, void(*visit)(T& item)) const;
    void preOrder(nodeType<T>* p, void(*visit)(T& item)) const;
    
    int height(nodeType<T>* p) const;
    int nodeCount(nodeType<T>* p) const;
    void nodeCount(nodeType<T>* p, int& count) const;
    int leafCount(nodeType<T>* p) const;
    void leafCount(nodeType<T>* p, int& count) const;
};

template<class T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template<class T>
bool BinaryTree<T>::isEmpty() const
{
    return (root == nullptr);
}

template<class T>
int BinaryTree<T>::treeHeight() const
{
    return height(root);
}

template<class T>
int BinaryTree<T>::treeNodeCount() const
{
    return nodeCount(root);
}

template<class T>
int BinaryTree<T>::treeLeafCount() const
{
    return leafCount(root);
}

template<class T>
void BinaryTree<T>::copyTree(nodeType<T>*& copiedTreeRoot, nodeType<T>* otherTreeRoot)
{
    if(otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new nodeType<T>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copiedTreeRoot->llink = otherTreeRoot->llink;
        copiedTreeRoot->rlink = otherTreeRoot->rlink;
    }
}

template<class T>
void BinaryTree<T>::inOrder(nodeType<T>* p, ofstream &ofs) const
{
    if(p != nullptr)
    {
        inOrder(p->llink, ofs);
        ofs << p->info << " ";
        inOrder(p->rlink, ofs);
    }
}

template<class T>
void BinaryTree<T>::postOrder(nodeType<T>* p, ofstream &ofs) const
{
    if(p != nullptr)
    {
        postOrder(p->llink, ofs);
        postOrder(p->rlink, ofs);
        ofs << p->info << " ";
    }
}

template<class T>
void BinaryTree<T>::preOrder(nodeType<T>* p, ofstream &ofs) const
{
    if(p != nullptr)
    {
        ofs << p->info << " ";
        preOrder(p->llink, ofs);
        preOrder(p->rlink, ofs);
    }
}
template<class T>
const BinaryTree<T>& BinaryTree<T>::operator =(const BinaryTree<T>& otherTree)
{
    if(this != &otherTree)
    {
        if(root != nullptr)
        {
            destroy(root);
        }
        if(otherTree.root == nullptr)
        {
            root = nullptr;
        }
        else
        {
            copyTree(root, otherTree.root);
        }
    }
    return *this;
}

template<class T>
void BinaryTree<T>::destroy(nodeType<T>*& p)
{
    if(p != nullptr)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = nullptr;
    }
}

template<class T>
void BinaryTree<T>::destroyTree()
{
    destroy(root);
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& otherTree)
{
    if(otherTree.root == nullptr)
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    destroy(root);
}

template<class T>
int BinaryTree<T>::leafCount(nodeType<T> *p) const
{
    int count = 0;
    leafCount(p, count);
    return count;
}

template<class T>
void BinaryTree<T>::leafCount(nodeType<T>* p, int& count) const
{
    if(p != nullptr)
    {
        leafCount(p->llink, count);
        leafCount(p->rlink, count);
        if(p->llink == nullptr && p->rlink == nullptr)
            count++;
    }
}

template<class T>
int BinaryTree<T>::nodeCount(nodeType<T> *p) const
{
    int count = 0;
    nodeCount(p, count);
    return count;
}

template<class T>
void BinaryTree<T>::nodeCount(nodeType<T> *p, int &count) const
{
    if(p != nullptr)
    {
        count++;
        nodeCount(p->llink, count);
        nodeCount(p->rlink, count);
    }
}

template<class T>
void BinaryTree<T>::inOrderTraversal(void(*visit)(T& item)) const
{
    inOrder(root, *visit);
}

template<class T>
void BinaryTree<T>::inOrder(nodeType<T>* p, void(*visit)(T& item)) const
{
    if(p != nullptr)
    {
        inOrder(p->llink, *visit);
        (*visit)(p->info);
        inOrder(p->rlink, *visit);
    }
}

template<class T>
void BinaryTree<T>::postOrderTraversal(void(*visit)(T& item)) const
{
    postOrder(root, *visit);
}

template<class T>
void BinaryTree<T>::postOrder(nodeType<T>* p, void(*visit)(T& item)) const
{
    if(p != nullptr)
    {
        postOrder(p->llink, *visit);
        postOrder(p->rlink, *visit);
        (*visit)(p->info);
    }
}

template<class T>
void BinaryTree<T>::preOrderTraversal(void (*visit)(T& item)) const
{
    preOrder(root, *visit);
}

template<class T>
void BinaryTree<T>::preOrder(nodeType<T> *p, void (*visit)(T& item)) const
{
    if(p != nullptr)
    {
        (*visit)(p->info);
        preOrder(p->llink, *visit);
        preOrder(p->rlink, *visit);
    }
}

template<class T>
void BinaryTree<T>::inOrderTraversal(ofstream &ofs) const
{
    inOrder(root, ofs);
}

template<class T>
void BinaryTree<T>::postOrderTraversal(ofstream &ofs) const
{
    postOrder(root, ofs);
}

template<class T>
void BinaryTree<T>::preOrderTraversal(ofstream &ofs) const
{
    preOrder(root, ofs);
}

template<class T>
int BinaryTree<T>::height(nodeType<T> *p) const
{
    if(p == nullptr)
        return 0;
    else
    {
        int lHeight = height(p->llink);
        int rHeight = height(p->rlink);
        if(lHeight >= rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }
}
#endif /* BinaryTree_h */
