//
//  main.cpp
//  Assignment3
//
//  Created by Brandon Kamplain on 4/11/22.
//

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
using namespace std;
using namespace chrono;



int main(int argc, const char * argv[])
{
    if (argc != 2)
    {
        cout << "Must include file name to output to.\n Ex: ./program <filename>\n";
        exit(1);
    }
    
    std::ofstream ofs;
    ofs.open (argv[1], std::ofstream::out | std::ofstream::app);
    
    //Last 4 digits of 700# is 0289
    srand(289);
    
    // record first timestamp
    auto start = high_resolution_clock::now();
    
    BinarySearchTree<long int> tree;
    BinarySearchTree<long int> tree2;
    
    if(tree.isEmpty() == 1)
        ofs << "Tree is empty before initial insertion\n";
    else
        ofs << "Tree isn't empty before initial insertion\n";
    
    for(int i=0; i<100000; i++)
        tree.insert(100 + rand() % ((100000000 + 1) - 100));
    
    if(tree.isEmpty() == 1)
        ofs << "Tree is empty after initial insertion\n";
    else
        ofs << "Tree isn't empty after initial insertion\n";
    
    long int num = (100 + rand() % ((100000000 + 1) - 100));
    
    ofs << "\nThe number of nodes in the tree before insertion is " << tree.treeNodeCount() << endl;
    
    tree.insert(num);
    if(tree.search(num) == 1)
        ofs << num << " inserted successfully\n";
    else
        ofs << num << "289 insertion failed\n";
    
    ofs << "\nThe number of nodes in the tree after insertion is " << tree.treeNodeCount() << endl;
    
    tree.deleteNode(num);
    ofs << num << " deleted successfully\n";
    
    ofs << "\nThe number of nodes in the tree after deletion is " << tree.treeNodeCount() << endl;
    
    ofs << "\nThe height of the tree is " << tree.treeHeight() << endl;
    
    ofs << "\nThe number of leaves in the tree is " << tree.treeLeafCount() << endl;
    
    ofs << "\nTree Inorder (sorted):\n";
    tree.inOrderTraversal(ofs);
    ofs << "\n\nPostorder:\n";
    tree.postOrderTraversal(ofs);
    ofs << "\n\nPreorder:\n";
    tree.preOrderTraversal(ofs);
    ofs << endl;
    
    tree.destroyTree();
    
    tree2 = tree;
    ofs << "\ntree copied into tree2 successfully.\n";
    
    
    
    // record second timestamp
    auto stop = high_resolution_clock::now();
    // calculate execution time
    auto duration_ns = duration_cast<nanoseconds>(stop - start);
    auto duration_ms = duration_cast<microseconds>(stop - start);
    auto duration_mis = duration_cast<milliseconds>(stop - start);
    auto duration_sec = duration_cast<seconds>(stop - start);
    auto duration_mins = duration_cast<minutes>(stop - start);
    auto duration_hr = duration_cast<hours>(stop - start);

    ofs << endl << "\nTotal time elapsed: \n" << duration_hr.count() << " hour(s), or\n" << duration_mins.count() << " minute(s), or\n" << duration_sec.count() << " second(s), or \n" << duration_mis.count() << " millisecond(s), or \n"<< duration_ms.count() << " microsecond(s), or \n"<< duration_ns.count() << " nanosecond(s)." << endl;

    ofs.close();
    
    return 0;
}
