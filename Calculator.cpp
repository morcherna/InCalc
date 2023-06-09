#include "Calculator.h"
Calculator::Calculator(){

};
bool Calculator::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/" ;
}

int Calculator::evaluateOperator(const std::string& op, int operand1, int operand2) {// указывает на передачу аргумента по ссылке
    if (op == "+") {
        return operand1 + operand2;
    } else if (op == "-") {
        return operand1 - operand2;
    } else if (op == "*") {
        return operand1 * operand2;
    } else if (op == "/") {
        if (operand2 == 0) {
            throw std::runtime_error("Division by zero");
        }
        return operand1 / operand2;
    } else {
        throw std::runtime_error("Invalid operator");
    }
}
int Calculator::calculate(std::string expression) {
    std::istringstream iss(expression);//позволяет производить ввод из строки
    std::string token;//временная переменная для хранения текущего токена при разбиении строки
    while (iss >> token) {//оператор >> используется для извлечения значения из потока iss и присваивания его переменной token
        if (isdigit(token[0])) {//проверяется, является ли первый символ токена цифрой
            stack.push(std::stoi(token));//токен преобразуется в интовое значение и пушится в стэк
        } else if (isOperator(token)) {// определяется операция
            if (stack.size() < 2) {//проверяется достаточно ли чисел
                throw std::runtime_error("Invalid expression");
            }

            int operand2 = stack.top();
            stack.pop();

            int operand1 = stack.top();
            stack.pop();

            int result = evaluateOperator(token, operand1, operand2);//считаем
            stack.push(result);
        } else {
            throw std::runtime_error("Invalid token in expression");
        }
    }

    if (stack.size() != 1) {// в конце вычисоений проверяем одно ли число осталось, если нет то ошибка
        throw std::runtime_error("Invalid expression");
    }

    return stack.top();//выдаем результат
}
