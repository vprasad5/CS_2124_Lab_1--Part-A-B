// Author: Varun Prasad
// Assignment Number: Lab 1 Part A
// File Name: VarunPrasadLab1.zip
// Course/Section: CS 2124 Section 0C1
// Date: 09/16/2021
// Instructor: Bernard Ku


#include <stdio.h>
double recursive_power(double base, int exponent); // function prototype

int main() {

// variable declarations
double num, res;
int exp;

    printf("Enter base: \n");
    scanf("%lf", &num);

    printf("Enter exponent: \n");
    scanf("%d", &exp);

res = recursive_power(num, exp); // calculating the num to the base within the recursive function

    printf("%g raised to %d = %g", num, exp, res);

}

double recursive_power(double base, int exponent) {

    // recursively finding the power of a number
    // if exponent is positive
    if (exponent != 0 && exponent > 0) {
        return (base * recursive_power(base, exponent - 1));
    }

    // if exponent is negative
    else if (exponent != 0 && exponent < 0) {
        return ((1 / base) * (recursive_power(base, exponent + 1)));
    }

    // if exponent = 0
    else {
        return 1;
    }

}