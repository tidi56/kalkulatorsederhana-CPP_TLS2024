/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <limits> // For numeric_limits

// Function prototypes
void displayMenu();
void performCalculation(char operation);

int main() {
    char operation;
    bool keepRunning = true;

    while (keepRunning) {
        displayMenu();
        std::cout << "Enter operation (+, -, *, /) or q to quit: ";
        std::cin >> operation;

        // Handle quitting
        if (operation == 'q' || operation == 'Q') {
            keepRunning = false;
            std::cout << "Exiting calculator. Goodbye!" << std::endl;
        } else if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
            performCalculation(operation);
        } else {
            std::cout << "Invalid operation. Please try again." << std::endl;
        }
    }

    return 0;
}

void displayMenu() {
    std::cout << "\nSimple Calculator" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Available operations:" << std::endl;
    std::cout << "+ : Addition" << std::endl;
    std::cout << "- : Subtraction" << std::endl;
    std::cout << "* : Multiplication" << std::endl;
    std::cout << "/ : Division" << std::endl;
    std::cout << "q : Quit" << std::endl;
}

void performCalculation(char operation) {
    double num1, num2;

    // Input validation
    std::cout << "Enter first number: ";
    while (!(std::cin >> num1)) {
        std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter a numeric value: ";
    }

    std::cout << "Enter second number: ";
    while (!(std::cin >> num2)) {
        std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter a numeric value: ";
    }

    double result;
    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation." << std::endl;
            break;
    }
}