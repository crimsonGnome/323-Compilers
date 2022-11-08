// --------------------------------------------------------------------
//    Group names   :Joseph Eggers, Maxwell Trotter
//    Assigment     : No.1
//    Due Date      : 11/7/22
// Purpose: this program reads an expression in postfix form, evaluates the expression
// and dispalys its value 
// --------------------------------------------------------------------

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using std::cout, std::endl, std::vector, std::string, std::stack, std::to_string;



int identifierToIndex(char column){
    int identity;
    switch(column){
        case 'i':
          identity = 0;
          break;
        case '+':
          identity = 1;
          break;
        case '-':
          identity = 2;
          break;
        case '*':
          identity = 3;
          break;
        case '/':
          identity = 4;
          break;
        case '(':
          identity = 5;
          break;
        case ')':
          identity = 6;
          break;
        case '$':
          identity = 7;
          break;
        case 'E':
          identity = 8;
          break;
        case 'T':
          identity = 9;
          break;
        case 'F':
          identity = 10;
          break;
        default:
          return -1;
          break;
    }
    return identity;
}

std::pair<int, char> cardinality(char R){
    std::pair<int, char>  identity;
    switch(R){
        case '1':
          identity.first = 3;
          identity.second = 'E';
          break;
        case '2':
          identity.first = 3;
          identity.second = 'E';
          break;
        case '3':
          identity.first = 1;
          identity.second = 'E';
          break;
        case '4':
          identity.first = 3;
          identity.second = 'T';
          break;
        case '5':
          identity.first = 3;
          identity.second = 'T';
          break;
        case '6':
          identity.first = 1;
          identity.second = 'T';
          break;
        case '7':
          identity.first = 3;
          identity.second = 'F';
          break;
        case '8':
          identity.first = 1;
          identity.second = 'F';
          break;
        default:
          identity.first = -1;
          identity.second = 'R';
          break;
    }
    return identity;
}



bool trace(string input,vector<vector<string>> parsingTable){
    stack<string> theStack;
    bool RFlag = false;
    char rFlagStored;
    unsigned int i = 0;
    
    // push initial condition
    theStack.push("0");
    while( i < input.size()){
        cout << theStack.top() << " theStack.top() \n";
        int row = std::stoi(theStack.top());
        theStack.pop();
        
        // Choose column Identifer
        char columnIdentifier = input[i];

        if (RFlag){
            RFlag = false;
            columnIdentifier = rFlagStored;
        }

        // convert char to column index;
        int column = identifierToIndex(columnIdentifier);
        
        

        string result = parsingTable[row][column];
        cout << "row/column [" << row << "," << column << "] result "<< result << endl;
        // Reject if got an empty state
        if(result == "") return false;
        // Read state
        if(result[0] == 'S'){
            theStack.push(to_string(row));
            theStack.push(to_string(columnIdentifier));
            string temp = result.substr(1, result.size());
            theStack.push(temp);
            ++i;
            continue;
        } else if(result[0] == 'R'){
            theStack.push(to_string(row));
            std::pair<int, char> cardinalityResult = cardinality(result[1]);
            // setting popped Items 
            int popItems = cardinalityResult.first * 2;
            while(popItems > 0){
                theStack.pop();
                --popItems;
            }
            rFlagStored = cardinalityResult.second;
            RFlag = true;
            continue;

        } else if (result[0] == 'A'){
            return true;
        } else {
            // TODO: same code as abovve if it works I will combine the steps
            theStack.push(to_string(row));
            theStack.push(to_string(columnIdentifier));
            theStack.push(result);
            continue;
        }

        
    }
}

int main(){
  string input1 = "(i+i)*i$";
  string input2 = "(i*)$";
  vector<vector<string>> parsingTable{{"S5","","","","","S4","","","1","2","3"},
                                      {"","S6","S7","","","","","ACC","","",""},
                                      {"","R3","R3","S8","S9","","R3","R3","","",""},
                                      {"","R6","R6","R6","R6","","R6","R6","","",""},
                                      {"S5","","","","","S4","","","10","2","3"},
                                      {"","R8","R8","R8","R8","","R8","R8","","",""},
                                      {"S5","","","","","S4","","","","11","3"},
                                      {"S5","","","","","S4","","","","12","3"},
                                      {"S5","","","","","S4","","","","","13"},
                                      {"S5","","","","","S4","","","","","14"}, 
                                      {"","S6","S7","","","","S15","","","",""}, 
                                      {"","R1","R1","S8","S9","","R1","R1","","",""},
                                      {"","R2","R2","S8","S9","","R2","R2","","",""},
                                      {"","R4","R4","R4","R4","","R4","R4","","",""},
                                      {"","R5","R5","R5","R5","","R5","R5","","",""},
                                      {"","R7","R7","R7","R7","","R7","R7","","",""},
                                    };

  bool input1Trace = trace(input1, parsingTable);
  if(input1Trace){
    cout << endl << input1 << " VALID" << endl;
  } else {
    cout << endl << input1 << " REJECTED" << endl;
  }

  bool input2Trace = trace(input2, parsingTable);
  if(input2Trace){
    cout << endl << input2 << " VALID" << endl;
  } else {
    cout << endl << input2 << " REJECTED" << endl;
  }

  return 0;
}