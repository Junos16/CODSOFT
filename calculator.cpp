#include <iostream>

int main() {
    bool exit = false;
    
    while(true) {
        if (exit) break;

        float operand1, operand2;
        char operation;
        
        std::cout << "Input operand 1: ";
        std::cin >> operand1;

        std::cout << "Input operand 2: ";
        std::cin >> operand2;
        
        std::cout << "Operation to perform: ";
        std::cin >> operation;

        switch(operation) {
            case('+'):
                std::cout << "Sum of both operands is: " << operand1 + operand2 << std::endl;
                break;

            case('-'):
                std::cout << "Difference of both operands is: " << operand1 - operand2 << std::endl;
                break;

            case('*'):
                std::cout << "Product of both operands is: " << operand1 * operand2 << std::endl;
                break;

            case('/'):
                try {
                    if (operand2 == 0) std::cout << "Quotient of both operands is: " << operand1 / operand2 << std::endl;
                    else throw(operand2);
                }
                catch(int oper) {
                    std::cout << "Error: Division by 0" << std::endl;
                }
                break;
                
            default:
                std::cout << "Exiting..." << std::endl;
                exit = true;
        }
    }

    return 0;
}