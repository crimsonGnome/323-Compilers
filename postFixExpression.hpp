#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>
 
 #ifndef POST_FIX_EXPRESSION_H
 #define POST_FIX_EXPRESSION_H

 class PostFixExpression {
    private:
     int sum_;
     std::vector<std::string> list_;

     void SumStack();
     void ReplaceStrings();
    public:
     // Constructors 
     PostFixExpression(std::string constructor);

     // modifiers
     void ReadStack();

     // Getters 
     int Sum();       
 };
 #endif

 