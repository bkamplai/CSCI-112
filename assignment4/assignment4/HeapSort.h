//
//  HeapSort.h
//  HeapSort
//
//  Created by Antoun, Sherine on 4/21/22.
//  Copyright © 2022 Antoun, Sherine. All rights reserved.
//  Modified by Brandon Kamplain.

#ifndef HeapSort_h
#define HeapSort_h

#include <stdio.h>
#include <vector>
using namespace std;
//make/remake heap
void heapify(vector<int>, int, int);

//heap sort
void heapSort(vector<int>, int);

// Print an array
void printArray(vector<int>, int );

#endif /* HeapSort_hpp */
