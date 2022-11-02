//
//  main.cpp
//  HeapSort
//
//  Created by Antoun, Sherine on 4/21/22.
//  Copyright © 2022 Antoun, Sherine. All rights reserved.
//

#include <random>
#include <iostream>
#include <chrono> // timing
#include "HeapSort.h"
using namespace std;
using namespace chrono;


// Driver code
int main(int argc, const char* argv[])
{
    default_random_engine gen;
    uniform_int_distribution<int> dist(100, 99999);
    int arr[9000];
    for (int i = 0; i < 9000; i++)
        arr[i] = dist(gen);
    
    int n = sizeof(arr) / sizeof(arr[0]);
    // record first timestamp
    auto start = high_resolution_clock::now();
    heapSort(arr, n);
    
    // record second timestamp
    auto stop = high_resolution_clock::now();
    // calculate execution time
    auto duration_ns = duration_cast<nanoseconds>(stop - start);
    auto duration_ms = duration_cast<microseconds>(stop - start);
    auto duration_mis = duration_cast<milliseconds>(stop - start);
    auto duration_sec = duration_cast<seconds>(stop - start);
    auto duration_mins = duration_cast<minutes>(stop - start);
    auto duration_hr = duration_cast<hours>(stop - start);

    cout << endl << "\nTotal time elapsed: \n" <<
        duration_mins.count() << " minutes, or\n" <<
        duration_sec.count() << " seconds, or \n" <<
        duration_mis.count() << " milliseconds, or \n"<<
        duration_ms.count() << " microseconds, or \n"<<
        duration_ns.count() << " nanoseconds only!"<<endl;

    cout << "Sorted array is: \n\t";
    printArray(arr, n);
}
