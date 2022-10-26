#include "postFixExpression.hpp"

#include <stack>                  // stack<int> numbers;
#include <stdio.h>
#include <ctype.h>

PostFixExpression::PostFixExpression(std::string constructor){
    // Take input string and add words to a vector container (named list) for processing
    int substringCount = 0;
    for(int i = 0; i < constructor.size(); ++i ){
        if(constructor[i] == '$'){
            std::string sub = constructor.substr(i- substringCount, substringCount);
            if(substringCount != 0) list_.push_back(sub);
            break;
        }
        else if(constructor[i] != ' '){
            ++substringCount;
            continue;
        } else {
            if(substringCount == 0) continue;
            std::string sub = constructor.substr(i - substringCount, substringCount);
            substringCount = 0;
            list_.push_back(sub);
        }
    }

    // Call Replace Strings Function (prcess all arguments)
    ReplaceStrings();
}


void PostFixExpression::ReplaceStrings(){
    // Convert all non-numeric entries in the list (unprocessed) into n
    // via prompt to user to supply a value

    for(int i = 0; i < list_.size(); ++i){
        std::string temp;
        if(!isalpha(list_[i][0])) continue;  // (if first character is anything
                                             // besides a letter)
        std::cout << "Enter the value of " << list_[i] << ": ";
        std::cin >> temp;
        list_[i] = temp;
        // (end of continue control block)
    }
}

void PostFixExpression::SumStack(){
    // Perform the mathematical evaluation of the expression by creating
    // the newly-processed stack of integers (named numbers)

    int sum = 0;
    std::stack<int> numbers;

    // loop through string
    for(int i = 0; i < list_.size(); ++i){
      // if char is a digit 
      if(isdigit(list_[i][0])){
          int n = std::stoi(list_[i]);
          numbers.push(n);
          continue;
      }
      // if char is the ending $
      if(list_[i][0] == '$'){
          break;
      }
      // char is a mathmatical symbol
      //Pop 2 stacked numbers; 
      int temp1 = numbers.top();  // (of the two operands, temp1 is the top-most in numbers)
      numbers.pop();
      int temp2 = numbers.top();  // (of the two operands, temp2 holds the bottom-most)
      numbers.pop();
      switch (list_[i][0]){
          case '+':
            sum = temp2 + temp1;
            break;
          case '-':
            sum = temp2 - temp1;
            break;
          case '*':
            sum = temp2 * temp1;
            break;
          default:
            sum = temp2 / temp1;
      }   // Expression 7 8 - should evaluate to 8 - 7 == 1
      // push new sum onto stack
      numbers.push(sum);

    }
    sum_ = sum;
       
};

int PostFixExpression::Sum(){
    // Calls the private helper evaluation function
    SumStack();
    return sum_;
}

void PostFixExpression::ReadStack(){
    // Prints the contents of main.cpp's PostFixExpression stack
    // (named stacky) after receiving the input expression
    for(int i = 0; i < list_.size(); ++i){
        std::cout << list_[i] << std::endl;
    }
}