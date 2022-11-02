//
//  QuickSort.h
//  QuickSort
//
//  Created by Brandon Kamplain on 5/10/22.
//

#ifndef QuickSort_h
#define QuickSort_h
#include <vector>
using namespace std;
void Partition(vector<int>&, int, int, int&);
void Quicksort(vector<int>&, int, int);
bool CompareData(int, int);
int HowMany();  //reports the total
void ExchangeData(int&, int&);
int ReportSwaps();
#endif /* QuickSort_h */
