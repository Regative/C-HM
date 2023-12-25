#include <iostream>
#include <limits>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return (b != 0) ? (a / b) : (std::cout << "Error: Division by zero." << std::endl, 0); }

int main() {
    int (*operation)(int, int) = nullptr;
    char operationSymbol;
    int operand1, operand2;

    std::cout << "Enter an arithmetic operation (+, -, *, /) or a space to exit: ";

    while (true) {
        operationSymbol = getchar();

        if (operationSymbol == ' ') {
            break;
        }

        if (!(operationSymbol == '+' || operationSymbol == '-' || operationSymbol == '*' || operationSymbol == '/')) {
            std::cout << "Invalid operation." << std::endl;
            return 1;
        }

        std::cout << "Enter two integers: ";
        std::cin >> operand1 >> operand2;

        switch (operationSymbol) {
        case '+': operation = add; break;
        case '-': operation = subtract; break;
        case '*': operation = multiply; break;
        case '/': operation = divide; break;
        }

        std::cout << "Result: " << operation(operand1, operand2) << std::endl;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}