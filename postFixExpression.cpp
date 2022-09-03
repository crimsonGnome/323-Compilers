#include "postFixExpression.hpp"

#include <stack>
#include <stdio.h>
#include <ctype.h>

PostFixExpression::PostFixExpression(std::string constructor){
    
    int substringCount = 0;
    for(int i = 0; i < constructor.size(); ++i ){
        if(constructor[i] != ' '){
            ++substringCount;
            continue;
        } else {
            std::string sub = constructor.substr(i - substringCount, substringCount);
            substringCount = 0;
            list_.push_back(sub);
        }
    }
    // runs if for some reason last term doesnt have white space between (should not happen)
    // -1 stringCount to get the last variable 
    std::string sub = constructor.substr(constructor.size() - substringCount, substringCount -1);
    list_.push_back(sub);
    // Call Replace Strings Function 
    ReplaceStrings();
}


void PostFixExpression::ReplaceStrings(){
    for(int i = 0; i < list_.size(); ++i){
        std::string temp;
        if(!isalpha(list_[i][0])) continue;
        std::cout << "Enter the value of " << list_[i] << ": ";
        std::cin >> temp;
        list_[i] = temp;
    }
}

void PostFixExpression::SumStack(){
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
      int temp1 = numbers.top();
      numbers.pop();
      int temp2 = 0;
      temp2 = numbers.top();
      numbers.pop();
      switch (list_[i][0]){
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
      // push new sum onto stack
      numbers.push(sum);

    }
    sum_ = sum;
       
};

int PostFixExpression::Sum(){
    SumStack();
    return sum_;
}

void PostFixExpression::ReadStack(){
    for(int i = 0; i < list_.size(); ++i){
        std::cout << list_[i] << std::endl;
    }
}