//
//  infix2postfixStack.h
//  week8
//
//  Created by Brandon Kamplain on 4/20/22.
//

#ifndef infix2postfixStack_h
#define infix2postfixStack_h
#include <string>

using namespace std;

class infixToPostfix
{
public:
    void convertToPostfix();
    bool precedence(char opr1, char opr2);
    void getInfix(string);
    void showInfix();
    void showPostfix();
    infixToPostfix(string = "");
    
    string getInfx();
    string getPfx();
        
private:
    string  infx;
    string  pfx;
};

#endif /* infix2postfixStack_h */
