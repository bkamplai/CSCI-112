//
//  main.cpp
//  week7
//
//  Created by Brandon Kamplain on 3/9/22.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;

void bubbleSort(int [], int);
void selectionSort(int [], int);
void insertionSort(int [], int);
void swap(int*, int*);
void printArray(int [], int);

int main()
{
    clock_t begin, end;
    
    begin = clock();
    
    int size = 74809;
    
    int *master = new int[size], *list1 = new int[size], *list2 = new int[size], *list3 = new int[size];
    
    //int master[size], list1[size], list2[size], list3[size];
    
    srand (time(NULL));
    
    for (int i = 0; i < size; i++)
        master[i] = rand() % size;
    
    for (int k = 0; k < size; k++)
        list3[k] = list2[k] = list1[k] = master[k];
    
    int n = size;
    bubbleSort(list1, n);
    cout <<"Sorted bubble array: \n";
    printArray(list1, n);
    
    selectionSort(list2, n);
    cout << "Sorted selection array: \n";
    printArray(list2, n);
    
    insertionSort(list3, n);
    cout << "Sorted insertion array: \n";
    printArray(list3, n);
    

    delete [] master;
    delete [] list1;
    delete [] list2;
    delete [] list3;
    
    end = clock();
    
    cout << "\nTime it took (in sec's) to sort numbers: " << (end-begin)/CLOCKS_PER_SEC << endl << endl;
    
    return 0;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
 
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
    cout << '\n';
}
