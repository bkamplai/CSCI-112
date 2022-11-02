//
//  main.cpp
//  QuickSort
//
//  Created by Brandon Kamplain on 5/10/22.
//

#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include "QuickSort.h"
using namespace std;
using namespace chrono;

int main(int argc, const char * argv[])
{
    default_random_engine gen;
    uniform_int_distribution<int> dist(100, 99999);
    
    //int x[10];
    
    vector<int> x(10);
    
    int n = x.size();
    
    for (int i = 0; i < n; i++)
        x[i] = dist(gen);
    
    cout << "Array before quick sort: ";
    for(int i = 0; i < n; i++)
        cout << x[i] << " ";
    
    auto start = high_resolution_clock::now();
    Quicksort(x, 0, n - 1);
    auto stop = high_resolution_clock::now();
    
    cout << "\nArray after quick sort: ";
    for(int j = 0; j < n; j++)
        cout << x[j] << " ";
    
    auto duration_ns = duration_cast<nanoseconds>(stop - start);
    auto duration_ms = duration_cast<microseconds>(stop - start);
    auto duration_mis = duration_cast<milliseconds>(stop - start);
    auto duration_sec = duration_cast<seconds>(stop - start);
    auto duration_mins = duration_cast<minutes>(stop - start);
    auto duration_hr = duration_cast<hours>(stop - start);
    
    cout << endl << "\nTotal time elapsed: \n" <<
    duration_hr.count() << " hours, or\n" <<
    duration_mins.count() << " minutes, or\n" <<
    duration_sec.count() << " seconds, or \n" <<
    duration_mis.count() << " milliseconds, or \n"<<
    duration_ms.count() << " microseconds, or \n"<<
    duration_ns.count() << " nanoseconds only!"<<endl;
    
    return 0;
}
