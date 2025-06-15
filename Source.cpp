#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to print boxed outputrrrrrrrrrr
void print_boxed_result(const char* label, double result) {
    printf("\n==============================\n");
    printf("%-20s %.2lf\n", label, result);
    printf("==============================\n");
}

void print_boxed_message(const char* message) {
    printf("\n==============================\n");
    printf("%s\n", message);
    printf("==============================\n");
}

// Addition
void add() {
    double a, b;
    printf("\nEnter two numbers to add: ");
    scanf("%lf %lf", &a, &b);
    print_boxed_result("Result =", a + b);
}

// Subtraction
void subtract() {
    double a, b;
    printf("\nEnter two numbers to subtract: ");
    scanf("%lf %lf", &a, &b);
    print_boxed_result("Result =", a - b);
}

// Multiplication
void multiply() {
    double a, b;
    printf("\nEnter two numbers to multiply: ");
    scanf("%lf %lf", &a, &b);
    print_boxed_result("Result =", a * b);
}

// Division
void divide() {
    double numerator, denominator;
    printf("\nEnter dividend and divisor: ");
    scanf("%lf %lf", &numerator, &denominator);

    if (denominator == 0) {
        if (numerator == 0)
            print_boxed_message("Result: Undefined (0/0)");
        else if (numerator > 0)
            print_boxed_message("Result: +Infinity");
        else
            print_boxed_message("Result: -Infinity");
    }
    else {
        print_boxed_result("Result =", numerator / denominator);
    }
}

// Power
void power() {
    double base, exponent;
    printf("\nEnter base and exponent: ");
    scanf("%lf %lf", &base, &exponent);
    print_boxed_result("Result =", pow(base, exponent));
}

// Square root
void squareroot() {
    double num;
    printf("\nEnter a number: ");
    scanf("%lf", &num);

    if (num < 0)
        print_boxed_message("Error: Cannot take square root of a negative number!");
    else
        print_boxed_result("Result =", sqrt(num));
}

// Factorial
void factorial() {
    int num;
    unsigned long long fact = 1;
    printf("\nEnter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        print_boxed_message("Error: Factorial of negative number doesn't exist.");
        return;
    }

    for (int i = 1; i <= num; ++i)
        fact *= i;

    printf("\n==============================\n");
    printf("Factorial = %llu\n", fact);
    printf("==============================\n");
}

// Delete last operation (reset simulation)
void delete_last_op(double* result) {
    *result = 0;
    print_boxed_message("Last operation deleted. Value reset to 0.");
}

// Menu system
void calculator_menu() {
    char choice;
    double last_result = 0;
    char again;

    do {
        printf("\n====================================\n");
        printf("          BASIC CALCULATOR          \n");
        printf("====================================\n");
        printf("1.  Addition\n");
        printf("2.  Subtraction\n");
        printf("3.  Multiplication\n");
        printf("4.  Division\n");
        printf("5.  Power (x^y)\n");
        printf("6.  Square Root\n");
        printf("7.  Factorial\n");
        printf("8.  Delete Last Operation\n");
        printf("0.  Exit\n");
        printf("Enter your choice:");
        scanf(" %c", &choice);

        switch (choice) {
        case '1': add(); break;
        case '2': subtract(); break;
        case '3': multiply(); break;
        case '4': divide(); break;
        case '5': power(); break;
        case '6': squareroot(); break;
        case '7': factorial(); break;
        case '8': delete_last_op(&last_result); break;
        case '0':
            print_boxed_message("Exiting Calculator. Goodbye!");
            printf("\n==============================\n");
            printf("Thank you for using the calculator!\n");
            printf("==============================\n");
            return;
        default:
            print_boxed_message("Invalid Choice! Please try again.");
        }

        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("\n==============================\n");
    printf("Exiting calculator! Goodbye.\n");
    printf("==============================\n");
}

// Main function
int main() {
    calculator_menu();
    return 0;
}
