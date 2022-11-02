//
//
//  assignment 4
//
//  Created by Brandon Kamplain.
//
//  The efficiency between your HeapSort and the STL sort algorithm was kind of surprising to see. The std::sort algorithm was ~5 times faster than yours was, but while testing the std::sort_heap algorithm, I found that it was a tiny bit slower than yours (582 seconds) and also compared to the std::sort algorithm. My quick sort algorithm using vectors however averaged about 391 microseconds, which is better than I thought. I thought quick sort would be slower than the heap sort, but I guess I am proven wrong. The std::sort is still however the reigning champion over the two.

#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include "infixToPostfix.h"
#include "HeapSort.h"
#include "QuickSort.h"
using namespace std;
using namespace chrono;

static int SIZE = 2000000000;

void task1()
{
    infixToPostfix  InfixExp;
    string infix;
    
    cout << "Enter an Infix expression followed by a semicolon:\n";
    getline(cin, infix);
    InfixExp.getInfix(infix);
    InfixExp.showInfix();
    InfixExp.showPostfix();
    cout << endl;
}
void task2()
{
    //  Professor's Code: 508 microseconds || 508221 nanoseconds
    //  STL Container:  379 microseconds || 379509 nanoseconds
    //  STL Algorithm (std::sort):  107 microseconds || 107501 nanoseconds
    
    default_random_engine gen;
    uniform_int_distribution<int> dist(100, 99999);
    //int size = 20000;
    vector<int> arr(SIZE);

    for (int i = 0; i < SIZE; i++)
        arr[i] = dist(gen);
    
    int n = arr.size();//sizeof(arr) / sizeof(arr[0]);
    
    //cout << "Heap Sort: \n";
    
    // record first timestamp
    auto start = high_resolution_clock::now();
    //heapSort(arr, n);
    sort(arr.begin(), arr.end());
    
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
    duration_hr.count() << " hours, or\n" <<
    duration_mins.count() << " minutes, or\n" <<
    duration_sec.count() << " seconds, or \n" <<
    duration_mis.count() << " milliseconds, or \n"<<
    duration_ms.count() << " microseconds, or \n"<<
    duration_ns.count() << " nanoseconds only!"<<endl;
    
    //cout << "\nSorted array is: \n\t";
    //printArray(arr, n);
    
    /*cout << "\nSTL Sort: \n";
    
    start = high_resolution_clock::now();
    //heapSort(arr, n);
    sort(arr.begin(), arr.end());
    
    // record second timestamp
    stop = high_resolution_clock::now();
    // calculate execution time
    duration_ns = duration_cast<nanoseconds>(stop - start);
    duration_ms = duration_cast<microseconds>(stop - start);
    duration_mis = duration_cast<milliseconds>(stop - start);
    duration_sec = duration_cast<seconds>(stop - start);
    duration_mins = duration_cast<minutes>(stop - start);
    duration_hr = duration_cast<hours>(stop - start);
    
    cout << endl << "\nTotal time elapsed: \n" <<
    duration_hr.count() << " hours, or\n" <<
    duration_mins.count() << " minutes, or\n" <<
    duration_sec.count() << " seconds, or \n" <<
    duration_mis.count() << " milliseconds, or \n"<<
    duration_ms.count() << " microseconds, or \n"<<
    duration_ns.count() << " nanoseconds only!"<<endl;*/
    
    //cout << "\nSorted array is: \n\t";
    //printArray(arr, n);
    
}

void task3()
{
    default_random_engine gen;
    uniform_int_distribution<int> dist(100, 99999);
    vector<int> arr(SIZE);

    for (int i = 0; i < SIZE; i++)
        arr[i] = dist(gen);
    
    int n = arr.size();
    
    //cout << "\nUnsorted array is: \n\t";
    //printArray(arr, n);
    
    // record first timestamp
    auto start = high_resolution_clock::now();
    // ~391 microseconds average.
    Quicksort(arr, 0, n - 1);
    
    // record second timestamp
    auto stop = high_resolution_clock::now();
    
    //cout << "\nSorted array is: \n\t";
    //printArray(arr, n);
    
    // calculate execution time
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
}

char Menu()
{
    char Option[20];
    cout << "*** Assignment 4 ***\n\n";
    cout << "1. Infix to Postfix (using stack)\n";
    cout << "2. New Heap Sort using STL Container and STL Algorithm\n";
    cout << "3. Bonus Task\n";
    cout << "0. Exit from the program\n";
    cout << "Enter your choice (0..3): ";
    cin.getline(Option,20);
    cout<<endl;
    return Option[0];
}

int main(int argc, const char * argv[])
{
    //task1();
    
    char Choice;
    while(1){
        Choice = Menu();
        switch(Choice){
            case '1': task1(); break;
            case '2': task2(); break;
            case '3': task3(); break;
            case '0': break;
            default: cout << "Invalid choice!\n\n";
        }
        if (Choice=='0') break;
    }
    cout << "Exiting Assignment 4, have a great rest of your day!\n\n";
    
    return 0;
}
