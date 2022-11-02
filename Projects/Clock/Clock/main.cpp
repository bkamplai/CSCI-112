//
//  main.cpp
//  Clock
//
//  Created by Brandon Kamplain on 1/26/22.
//

#include <iostream>
#include "clockType.h"

using namespace std;

int main() {

    clockType myClock(9, 30, 45);
    clockType yourCLock(12,45,18);
    clockType tempClock(6, 10, 59);
    
    cout << "Myclock ------ time is: ";
    myClock.printTime();
    cout << endl;
    
    return 0;
}
