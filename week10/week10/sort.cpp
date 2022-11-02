//
//  sort.cpp
//  week10
//
//  Created by Brandon Kamplain on 4/6/22.
//

#include <iostream>
#include "sort.h"
using namespace std;

static int NoComp = 0; //keeps track of comparisons
static int NoSwaps = 0;

void swap(int& v1, int& v2)
{
    int temp = v1;
    
    NoSwaps++;
    v1 = v2;
    v2 = temp;
}

int reportSwaps()
{
    return NoSwaps;
}

bool Compare(int v1, int v2)
{
    NoComp++;
    return (v1 < v2);
}

int howMany() //reports total
{
    return NoComp;
}

void Partition(int arr[], int left, int right, int& pivot)
{
    int lIndex, rIndex, pValue;
    pValue = arr[left];
    lIndex = left;
    rIndex = right + 1;
    while (lIndex < rIndex)
    {
        lIndex++;
        while (Compare(arr[lIndex], pValue)) //Left scan
            lIndex++;
        rIndex--;
        while (Compare(pValue, arr[rIndex])) //Right scan
            rIndex--;
        if (lIndex < rIndex)
        {
            swap(arr[lIndex], arr[rIndex]);
        }
    }
    pivot = rIndex;
    swap(arr[left], arr[rIndex]);
}

void quickSort(int index[], int left, int right)
{
    int pivot;
    
    Partition(index, left, right, pivot);
    if (pivot-1 > left)
        quickSort(index, left, pivot-1);
    if (right > pivot+1)
        quickSort(index, pivot+1, right);
}
