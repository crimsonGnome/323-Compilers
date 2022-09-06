// --------------------------------------------------------------------
//    Group names   :Joseph Eggers, Maxwell Trotter, Mariah 
//    Assigment     : No.1
//    Due Date      : 8/30/22
// Purpose: this program reads an expression in postfix form, evaluates the expression
// and dispalys its value 
// --------------------------------------------------------------------

#include <iostream>
#include <string>
#include <stack>

#include "postFixExpression.hpp"

using std::cin, std::cout, std::endl;

int main(){
    char loopFlag = 'y';
    

    // loop while not n (no)
    while(loopFlag != 'n'){
        std::string input;
        cout << "\nEnter a postfix expression with a $ at the end:\n";
        getline(cin, input);
        cout << input << endl;
        
        PostFixExpression stacky(input);
        stacky.ReadStack();
        cout << "\n     Expression Value = " << stacky.Sum() << endl
             << "CONTINUE(y/n)? ";
        
        cin >> loopFlag;
        cin.ignore(256, '\n');
    }
    return 0;

}