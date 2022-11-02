//
//  main.cpp
//  newString
//
//  Created by Brandon Kamplain on 2/22/22.
//

#include <iostream>
#include "newString.h"

using namespace std;

int main()
{
    newString str1 = "Sunny";
    const newString str2("Warm");
    newString str3, str4;
    
    cout << "Test 1 " << str1 << "  " << str2 << "  ***" << str3 << "  ###." << endl;
    
    cout << "Goodbye world!" << endl;
    
    return 0;
}
