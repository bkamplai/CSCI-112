//
//  main.cpp
//  mergeSort
//
//  Created by Brandon Kamplain on 4/4/22.
//

#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

// Function prototype
void arraycopy(int[], int, int[], int, int);
void merge(int[], int, int[], int, int[]);
void mergeSort(int[], int);

int main()
{
    clock_t begin, end;
    begin = clock();
    const int SIZE = 10000000; //Size of array, can be changed
    int *list = new int[SIZE]; //Dynamic array
    
    //Fills array with random integers
    srand (time(NULL));
    for (int i = 0; i < SIZE; i++)
        list[i] = rand() % SIZE;
    /*
    //Outputs unsorted array
    cout << "Unsorted: ";
    for (int i = 0; i < SIZE; i++)
        cout << list[i] << " ";
    */
    
    //Sorts array using specified method
    mergeSort(list, SIZE);
    
    //Outputs sorted array
    cout << "\nSorted: ";
    for (int i = 0; i < SIZE; i++)
        cout << list[i] << " ";
    
    //Deletes dynamic array (no memory leaks)
    delete [] list;
    end = clock();
    cout << "\nTime it took (in sec's) to sort integers: " << (end-begin)/CLOCKS_PER_SEC << endl;
    
    return 0;
}

// The function for sorting the numbers
void mergeSort(int list[], int arraySize)
{
    if (arraySize > 1)
    {
        // Merge sort the first half
        int* firstHalf = new int[arraySize / 2];
        arraycopy(list, 0, firstHalf, 0, arraySize / 2);
        mergeSort(firstHalf, arraySize / 2);
        
        // Merge sort the second half
        int secondHalfLength = arraySize - arraySize / 2;
        int* secondHalf = new int[secondHalfLength];
        arraycopy(list, arraySize / 2, secondHalf, 0, secondHalfLength);
        mergeSort(secondHalf, secondHalfLength);
        
        // Merge firstHalf with secondHalf
        merge(firstHalf, arraySize / 2, secondHalf, secondHalfLength,
              list);
        
        delete [] firstHalf;
        delete [] secondHalf;
    }
}

void merge(int list1[], int list1Size,
           int list2[], int list2Size, int temp[])
{
    int current1 = 0; // Current index in list1
    int current2 = 0; // Current index in list2
    int current3 = 0; // Current index in temp
    
    while (current1 < list1Size && current2 < list2Size)
    {
        if (list1[current1] < list2[current2])
            temp[current3++] = list1[current1++];
        else
            temp[current3++] = list2[current2++];
    }
    
    while (current1 < list1Size)
        temp[current3++] = list1[current1++];
    
    while (current2 < list2Size)
        temp[current3++] = list2[current2++];
}

void arraycopy(int source[], int sourceStartIndex, int target[], int targetStartIndex, int length)
{
    for (int i = 0; i < length; i++)
    {
        target[i + targetStartIndex] = source[i + sourceStartIndex];
    }
}
