#include <iostream>
#include <cmath> // For advanced math functions
using namespace std;

int main() {
    double num1, num2;
    char operation;
    bool validOperation = true;
    char continueCalc;

    do {
        // Display instructions
        cout << "\nAdvanced Calculator\n";
        cout << "====================\n";
        cout << "Supported operations:\n";
        cout << "  +  : Addition\n";
        cout << "  -  : Subtraction\n";
        cout << "  *  : Multiplication\n";
        cout << "  /  : Division\n";
        cout << "  %  : Modulus (integers only)\n";
        cout << "  ^  : Power\n";
        cout << "  r  : Square root (first number only)\n";
        cout << "Enter your calculation in the format: number1 number2 operation\n";
        cout << "Example: 5 3 +\n\n";

        // Input numbers and operation
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number (or 0 if not needed for the operation): ";
        cin >> num2;
        cout << "Enter the operation (+, -, *, /, %, ^, r): ";
        cin >> operation;

        // Perform the calculation based on the operation
        switch (operation) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                }
                break;
            case '%':
                if (num2 != 0) {
                    cout << "Result: " << static_cast<int>(num1) % static_cast<int>(num2) << endl;
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                }
                break;
            case '^':
                cout << "Result: " << pow(num1, num2) << endl;
                break;
            case 'r':
                if (num1 >= 0) {
                    cout << "Result: " << sqrt(num1) << endl;
                } else {
                    cout << "Error: Square root of a negative number is not allowed.\n";
                }
                break;
            default:
                validOperation = false;
                cout << "Error: Invalid operation entered.\n";
                break;
        }

        // Exit message
        if (validOperation) {
            cout << "Thank you for using the advanced calculator!\n";
        } else {
            cout << "Please restart and try again with a valid operation.\n";
        }

        // Ask if the user wants to continue
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> continueCalc;

    } while (tolower(continueCalc) == 'y');

    cout << "Goodbye!\n";
    return 0;
}
