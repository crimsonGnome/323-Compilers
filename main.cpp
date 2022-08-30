// --------------------------------------------------------------------
//    Group names   :Joseph Eggers, Maxwell Trotter, 
//    Assigment     : No.1
//    Due Date      : 8/30/22
// Purpose: this program reads an expression in postfix form, evaluates the expression
// and dispalys its value 
// --------------------------------------------------------------------

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <stack>

using std::cin, std::cout, std::endl;

int postFixExpression(std::string postFix){
    int sum = 0;
    std::stack<int> numbers;
    for(int i = 0; i < postFix.size(); ++i){
      if(isdigit(postFix[i])){
          cout << " ran\n";
          int n = postFix[i] - '0';
          numbers.push(n// --------------------------------------------------------------------a\n";
      //Pop 2 stacked numbers; 
      int temp1 = numbers.top();
      numbers.pop();
      int temp2 = 0;
      temp2 = numbers.top();
      numbers.pop();
      switch (postFix[i]){
          case '+':
            sum = temp1 + temp2;
            break;
          case '-':
            sum = temp1 - temp2;
            break;
          case '*':
            sum = temp1 * temp2;
            break;
          default:
            sum = temp1 / temp2;
      }
      numbers.push(sum);

    }
    return 0;

}

int main(){
    char loopFlag = 'y';
    std::string input;
    int value = 0;
    while(loopFlag != 'n'){
        cout << "\nEnter a postfix expression with a $ at the end: ";
        cin >> input;
        cout << input;
        value = postFixExpression(input);
        cout << "\n   Value = " << value << endl
             << "CONTINUE(y/n)? ";
        cin >> loopFlag;
    }
    return 0;

}