//
//  QuickSort.cpp
//  QuickSort
//
//  Created by Brandon Kamplain on 5/10/22.
//

#include <stdio.h>
#include "QuickSort.h"
using namespace std;

static int NoComp = 0; // keeps track of comparisons
static int NoSwaps = 0;

void Partition(vector<int> &x, int left, int right, int &pivot)
{
    int lIndex, rIndex, pValue;
    
    pValue = x[left];
    lIndex = left;
    rIndex = right + 1;
    
    while(lIndex < rIndex)
    {
        lIndex++;
        
        while(CompareData(x[lIndex], pValue))   //Left Scan
            lIndex++;
        
        rIndex--;
        
        while(CompareData(pValue, x[rIndex]))   //Right Scan
            rIndex--;
        
        if(lIndex < rIndex)
            ExchangeData(x[lIndex], x[rIndex]);
    }
    
    pivot = rIndex;
    ExchangeData(x[left], x[rIndex]);
}

void Quicksort(vector<int> &x, int left, int right)
{
    int pivot;
    
    Partition(x, left, right, pivot);
    
    if (pivot - 1 > left)
        Quicksort(x, left, pivot - 1);
    if (right > pivot + 1)
        Quicksort(x, pivot + 1, right);
}

bool CompareData(int V1, int V2)
{
    NoComp++;
    return (V1 < V2);
}

int HowMany() // reports the total
{
    return NoComp;
}

void ExchangeData(int& V1, int& V2)
{
    int temp = V1;
    NoSwaps++;
    V1 = V2;
    V2 = temp;
}

int ReportSwaps()
{
    return NoSwaps;
}
