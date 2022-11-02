//
//  sort.h
//  week10
//
//  Created by Brandon Kamplain on 4/8/22.
//

#ifndef sort_h
#define sort_h
#include <iostream>
using namespace std;

static int n, nlast, cCount, nfirst;
static int *value;

void swap(int&, int&);
int reportSwaps();
bool Compare(int, int);
int howMany();

void Partition(int[], int, int, int&);
void quickSort(int[], int, int);

#endif /* sort_h */
