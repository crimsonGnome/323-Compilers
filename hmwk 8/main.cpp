// --------------------------------------------------------------------
//    Group names   :Joseph Eggers, Maxwell Trotter
//    Assigment     : No.1
//    Due Date      : 10/25/22
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

bool validLanguage(string list,vector<vector<string>> parsingTable ){
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
        //cout << "row " << row << " looking for " << list[i] << endl;
        if(list[i] == '$' && row == '$') return true;
        if(list[i] == row){
          //cout << "1st if statement that pops" <<currentStack.top();
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
        if(list[i] == '$' && temp[0] == '$') return true;
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
    currentStack.push('S');
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
          identy = 8;
          break;
        default:
          return false;
          break;

      }
      while(notMatched && !currentStack.empty()){
        char row = currentStack.top();
        currentStack.pop();
        //cout << "row " << row << " looking for " << list[i] << endl;
        if(list[i] == '$' && row == '$') return true;
        if(list[i] == row){
          //cout << "1st if statement that pops" <<currentStack.top();
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
            rowTable = 5;
            break;
          case 'F':
            rowTable = 6;
            break;
          default:
            return false;
            break;
        }
        string temp = parsingTable[rowTable][identy];
        if(list[i] == '$' && temp[0] == '$') return true;
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
    vector<vector<string>> parsingTable2{{"aW", "", "", "", "","","","",""},{"","=E", "", "", "", "","","",""},{"TQ", "", "", "", "","","TQ","",""},{"", "","+TQ", "-TQ", "", "","","null","null"},{"FR","", "", "", "", "","FR","",""},{"","", "null", "null", "*FR", "/FR","","null","null"},{"a","", "", "", "", "","(E)","",""}};
    string input1 = "(i+i)*i$";
    string input2 = "i*(i-i)$";
    string input3 = "i(i+i)$";
    bool input1answer = validLanguage(input1, parsingTable);
    
    //Block 1
    if(input1answer){
      cout << endl << input1 << " VALID" << endl;
    } else {
      cout << endl << input1 << " REJECTED" << endl;
    }
    bool input2answer = validLanguage(input2, parsingTable);
    

     if(input2answer){
      cout << endl << input2 << " VALID" << endl;
    } else {
      cout << endl << input2 << " REJECTED" << endl;
    }
    bool input3answer = validLanguage(input3, parsingTable);
     if(input3answer){
      cout << endl << input3 << " VALID" << endl;
    } else {
      cout << endl << input3 << " REJECTED" << endl;
    }
  

    // Block 2
    string input4 = "a=(a+a)*a$";
    string input5 = "a=a*(a-a)$";
    string input6 = "a=(a+a)a$";
    bool input4answer = validLanguage2(input4, parsingTable2);
    

    if(input4answer){
      cout << endl << input4 << " VALID" << endl;
    } else {
      cout << endl << input4 << " REJECTED" << endl;
    }
    bool input5answer = validLanguage2(input5, parsingTable2);
    
     if(input5answer){
      cout << endl << input5 << " VALID" << endl;
    } else {
      cout << endl << input5 << " REJECTED" << endl;
    }
    bool input6answer = validLanguage2(input6, parsingTable2);
     if(input6answer){
      cout << endl << input6 << " VALID" << endl;
    } else {
      cout << endl << input6 << " REJECTED" << endl;
    }

    return 0;

}