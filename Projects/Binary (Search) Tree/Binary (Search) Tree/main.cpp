//
//  main.cpp
//  Binary (Search) Tree
//
//  Created by Brandon Kamplain on 4/7/22.
//

#include <iostream>
using namespace std;

template <class T>
class BinaryTree
{
public:
    BinaryTree(); //constructor
    ~BinaryTree(); //destructor
    void Insert(const T&);
    bool Locate(const T&, T&);
    bool Delete(const T&, T&);
    int TreeDataCmp(const T&, const T&);
private:
    struct node;
    typedef node *nodePtr;
    struct node
    {
        T data;
        nodePtr left, right;
    };
    nodePtr root;
    nodePtr FindNode(const T&, nodePtr);
    void InsertNode(const T&, nodePtr&);
    void InorderTraverse(nodePtr);
    T Visit();
};

int main()
{
    BinaryTree<int> BST;
    BST.Insert(1);
    BST.Insert(5);
    BST.Insert(3);
    
    return 0;
}

template <class T>
BinaryTree<T>::BinaryTree()
{
    root = 0;
}

template <class T>
typename BinaryTree<T>::nodePtr BinaryTree<T>::FindNode(const T& data,
BinaryTree<T>::nodePtr root)
{
    int Result = TreeDataCmp(data,root->data);
    if (Result == 0)
        return root;
    if (Result < 0 && root->left != 0)
        return FindNode(data,root->left);
    else if (Result > 0 && root->right != 0)
        return FindNode(data,root->right);
    return 0;
}

template <class T>
bool BinaryTree<T>::Locate(const T& data, T& founddata)
{
    nodePtr foundNode = FindNode(data, root);
    if (foundNode != 0)
    {
        founddata = foundNode->data;
        return true;
    }
    else
        return false;
}

template <class T>
void BinaryTree<T>::InsertNode(const T& data, BinaryTree<T>::nodePtr& root)
{
    if (root == 0)
    {
        root = new node;
        root->data = data;
        root->left = 0;
        root->right = 0;
    }
    else if (TreeDataCmp(data, root->data) <= 0)
        InsertNode(data, root->left);
    else
        InsertNode(data, root->right);
}

template <class T>
void BinaryTree<T>::Insert(const T&)
{
    InsertNode();
}

template <class T>
void BinaryTree<T>::InorderTraverse(nodePtr curr)
{
    if (curr != 0)
    {
        InorderTraverse(curr->left);
        Visit(curr);
        InorderTraverse(curr->right);
    }
}
