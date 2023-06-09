#ifndef SDL4_CALCULATOR_H
#define SDL4_CALCULATOR_H
#include "Stack.h"
#include <string>
#include <sstream>
#include <cmath>


class Calculator {
private:
    Stack stack;
    bool isOperator(const std::string& token);
    int evaluateOperator(const std::string& op, int operand1, int operand2);
public:
    Calculator();
    int calculate(std::string expression);
};


#endif //SDL4_CALCULATOR_H
