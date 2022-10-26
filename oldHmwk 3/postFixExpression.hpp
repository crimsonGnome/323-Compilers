#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>
 
 #ifndef POST_FIX_EXPRESSION_H
 #define POST_FIX_EXPRESSION_H

 class PostFixExpression {
    private:
     int sum_;                                    // Result of evaluated expression
     std::vector<std::string> list_;              // Stores input while words are converted
                                                  // to numeral values and operators

     void SumStack();
     void ReplaceStrings();
    public:
     // Constructors 
     PostFixExpression(std::string constructor);

     // modifiers
     void ReadStack();                            // Used only to read stacky (in main)
                                                  // immediately after input

     // Getters 
     int Sum();
 };
 #endif

 