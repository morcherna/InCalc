#include "InToPost.h"

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}
bool isValidInfixExpression(const std::string& infix) {
    int openBrackets = 0;
    int closeBrackets = 0;
    bool lastWasOperator = false;

    for (char c : infix) {
        if (isspace(c))
            continue;

        if (isOperator(c)) {
            if(infix[0] == c)
                return false;
            if (lastWasOperator)
                return false;
            lastWasOperator = true;
        } else if (c == '(') {
            openBrackets++;
            lastWasOperator = false;
        } else if (c == ')') {
            closeBrackets++;
            lastWasOperator = false;
        } else {
            if (!isdigit(c))
                return false;
            lastWasOperator = false;
        }
    }

    return openBrackets == closeBrackets && !lastWasOperator;
}

std::string InToPost::inToPost(const std::string& infix) {
    if (!isValidInfixExpression(infix)) {
        return ""; 
    }
    std::string postfix;
    Stack operatorStack;
    Queue postfixQueue;

    for (char c : infix) {
        if (isspace(c))
            continue;

        if (isOperator(c)) {
            while (operatorStack.size()>0 && isOperator(operatorStack.top()) &&
                   getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfixQueue.enqueue(operatorStack.top());
                postfixQueue.enqueue(' ');
                operatorStack.pop();
            }
            operatorStack.push(c);
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (operatorStack.size()>0 && operatorStack.top() != '(') {
                postfixQueue.enqueue(operatorStack.top());
                postfixQueue.enqueue(' ');
                operatorStack.pop();
            }

            if (operatorStack.size()>0 && operatorStack.top() == '('){
                postfixQueue.enqueue(' ');
                operatorStack.pop(); 
            }

        } else {
            // Операнд (число)
            postfixQueue.enqueue(c);
            postfixQueue.enqueue(' ');
        }
    }

    while (operatorStack.size()>0) {
        postfixQueue.enqueue(operatorStack.top());
        postfixQueue.enqueue(' ');
        operatorStack.pop();
    }

    while (!postfixQueue.isEmpty()) {
        postfix += postfixQueue.dequeue();
    }

    return postfix;
}
