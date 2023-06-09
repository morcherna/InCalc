#include "Calculator.h"
#include "InToPost.h"
int main() {
    Calculator calculator;
    std::string infixExpression;

    std::cout << "Enter the postfix expression: ";
    std::getline(std::cin, infixExpression);
    std::string postfixExpression = InToPost::inToPost(infixExpression);

    try {
        int result = calculator.calculate(postfixExpression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}