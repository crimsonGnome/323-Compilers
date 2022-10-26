// --------------------------------------------------------------------
//    Group names   :Joseph Eggers, Maxwell Trotter
//    Assigment     : No.1
//    Due Date      : 8/30/22
// Purpose: this program reads an expression in postfix form, evaluates the expression
// and dispalys its value 
// --------------------------------------------------------------------

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using std::cout, std::endl, std::vector, std::string, std::stack;

stack<char> readStack(stack<char> input){
    stack<char> copy = input;
    vector<char> reverseStack;
    stack<char> returnStack;
    while(!copy.empty()){
        reverseStack.push_back(copy.top());
        copy.pop();
    }
    cout << endl;
    for(auto i = reverseStack.rbegin(); i != reverseStack.rend(); ++i){
      cout << *i << " ";
      returnStack.push(*i);
    }
    return returnStack;
}

bool validLanguage1(string list,vector<vector<string>> parsingTable ){
    // Perform the mathematical evaluation of the expression by creating
    // the newly-processed stack of integers (named numbers)

    int sum = 0;
    std::stack<char> currentStack;
    currentStack.push('$');
    currentStack.push('E');
    // loop through string
    for(int i = 0; i < list.size(); ++i){
      bool notMatched = true;
      // if char is a digit 
      int identy = 0;
      int rowTable;
      switch(list[i]){
        case 'i':
          identy = 0;
          break;
        case '+':
          identy = 1;
          break;
        case '*':
          identy = 2;
          break;
        case '(':
          identy = 3;
          break;
        case ')':
          identy = 4;
          break;
        case '$':
          identy = 5;
          break;
        case '-':
          identy = 6;
          break;
        case '/':
          identy = 7;
          break;
        default:
          return false;
          break;

      }
      while(notMatched && !currentStack.empty()){
        char row = currentStack.top();
        currentStack.pop();
        cout << "row " << row << " looking for " << list[i] << endl;
        if(list[i] == '$' && row == '$') return true;
        if(list[i] == row){
          currentStack.pop();
          notMatched = false;
          break;
        }
        switch(row){
          case 'E':
            rowTable = 0;
            break;
          case 'Q':
            rowTable = 1;
            break;
          case 'T':
            rowTable = 2;
            break;
          case 'R':
            rowTable = 3;
            break;
          case 'F':
            rowTable = 4;
            break; 
          default:
            return false;
            break;
        }
        string temp = parsingTable[rowTable][identy];
        if(temp == "null") continue;
        if(temp == "") return false;
        for(int j = temp.size() -1; j >= 0; --j){
            currentStack.push(temp[j]);
        }
  
        char compareString = currentStack.top();
        if(compareString == list[i] ){
          currentStack.pop();
          notMatched = false;
          break;
        }
      }
      // need to print a stack
      currentStack =  readStack(currentStack);
    }
    cout << "ran true";
    return true;
    
};

bool validLanguage2(string list,vector<vector<string>> parsingTable ){
    // Perform the mathematical evaluation of the expression by creating
    // the newly-processed stack of integers (named numbers)

    int sum = 0;
    std::stack<char> currentStack;
    currentStack.push('$');
    currentStack.push('E');
    // loop through string
    for(int i = 0; i < list.size(); ++i){
      bool notMatched = true;
      // if char is a digit 
      int identy = 0;
      int rowTable;
      switch(list[i]){
        case 'a':
          identy = 0;
          break;
        case '=':
          identy = 1;
          break;
        case '+':
          identy = 2;
          break;
        case '-':
          identy = 3;
          break;
        case '*':
          identy = 4;
          break;
        case '/':
          identy = 5;
          break;
        case '(':
          identy = 6;
          break;
        case ')':
          identy = 7;
          break;
        case '$':
          identy = 7;
          break;
        default:
          return false;
          break;

      }
      while(notMatched && !currentStack.empty()){
        char row = currentStack.top();
        currentStack.pop();
        cout << "row " << row << " looking for " << list[i] << endl;
        if(list[i] == '$' && row == '$') return true;
        if(list[i] == row){
          currentStack.pop();
          notMatched = false;
          break;
        }
        switch(row){
          case 'S':
            rowTable = 0;
            break;
          case 'W':
            rowTable = 1;
            break;
          case 'E':
            rowTable = 2;
            break;
          case 'Q':
            rowTable = 3;
            break;
          case 'T':
            rowTable = 4;
            break;
          case 'R':
            rowTable = 4;
            break;
          case 'F':
            rowTable = 4;
            break;
          default:
            return false;
            break;
        }
        string temp = parsingTable[rowTable][identy];
        if(temp == "null") continue;
        if(temp == "") return false;
        for(int j = temp.size() -1; j >= 0; --j){
            currentStack.push(temp[j]);
        }
  
        char compareString = currentStack.top();
        if(compareString == list[i] ){
          currentStack.pop();
          notMatched = false;
          break;
        }
      }
      // need to print a stack
      currentStack =  readStack(currentStack);
    }
    cout << "ran true";
    return true;
    
};

int main(){
    vector<vector<string>> parsingTable{{"TQ", "", "", "TQ", "","","",""},{"", "+TQ", "", "", "null","null","-TQ",""},{"FR", "", "", "FR", "","","",""},{"", "null", "*FR", "", "null","null","null","FR"},{"i", "", "", "(E)", "","","",""}};
    vector<vector<string>> parsingTable2{{"aW", "", "", "", "","","","",""},{"","=E", "", "", "", "","","",""},{"TQ", "", "", "", "","","TQ","",""},{"", "","+TQ", "-TQ", "", "","","null","null"},{"FR","", "", "", "", "","FR","",""},{"","", "null", "null", "+FR", "/FR","","null","null"},{"a","", "", "", "", "","(E)","",""}};
    string input1 = "(i*i)*i$";
    string input2 = "i*(i-i)$";
    string input3 = "i(i+i)$";
    bool input1answer = validLanguage(input1, parsingTable);
    bool input2answer = validLanguage(input2, parsingTable);
    bool input3answer = validLanguage(input3, parsingTable);

    //Block 1
    if(input1answer){
      cout << input1 << " VALID" << endl;
    } else {
      cout << input1 << " REJECTED" << endl;
    }
        
     if(input2answer){
      cout << input2 << " VALID" << endl;
    } else {
      cout << input2 << " REJECTED" << endl;
    }
    
     if(input3answer){
      cout << input3 << " VALID" << endl;
    } else {
      cout << input3 << " REJECTED" << endl;
    }
  
    return 0;

}