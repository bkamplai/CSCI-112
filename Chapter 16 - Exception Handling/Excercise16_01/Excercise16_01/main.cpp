//
//  main.cpp
//  Excercise16_01
//  invalid_argument
//
//  Created by Brandon Kamplain on 4/4/22.
//

//  Instructions: LiveExample 6.18 gives the hex2Dec (const string& hexString) function that returns a decimal number from a hex string. Implement the hex2Dec function to throw an invalid_argument exception if the string is not a hex string. Write a test program that prompts the user to enter a hex number as a string and display the number in decimal. If the function throws an exception, display "Not a hex number". You need to write the code to catch the exception in the main function. Use the code from https://liangcpp.pearsoncmg.com/test/Exercise16_01.txt to complete your program. For a hint on this program, please see https://liangcpp.pearsoncmg.com/cpprevel2e.html. If you get a logic or runtime error, please refer to https://liangcpp.pearsoncmg.com/faq.html.

#include<iostream>
#include<stdexcept>
#include<string>
#include<cctype>
using namespace std;

int hex2Dec(const string& hexString);
int convertHexToDec(char ch);

int hex2Dec(const string& hexString)
{
  int value = 0;
  for (unsigned int i = 0; i < hexString.size(); i++)
     value = value * 16 + convertHexToDec(toupper(hexString[i]));
  return value;
}

// The function returns an int for a hex digit.
// Throws an invalid_argument("Not a hex number") if the hex character is invalid
int convertHexToDec(char ch)
{
    ch = toupper(ch);
    if(ch >= 'F')
        throw invalid_argument("Not a hex number");
    else if (ch >= 'A' && ch <= 'F')
        return 10 + ch - 'A';
    else
        return ch - '0';
}

int main()
{
  string hexString;
    
  try
  {
      cout << "Enter a hex number: ";
      cin >> hexString;
      cout << "The decimal value for the hexidecimal number " << hexString << " is " << hex2Dec(hexString) << endl;
  }
  catch(invalid_argument& ex)
  {
      cout << hexString << " is " << ex.what() << endl;
  }

  return 0;
}
