// Author: Varun Prasad
// Assignment Number: Lab 1 Part B
// File Name: VarunPrasadLab1.zip
// Course/Section: CS 2124 Section 0C1
// Date: 09/16/2021
// Instructor: Bernard Ku

#include <stdio.h>
int Luhns_Algorithm_Iterative(int numArr[]); // function prototype

int main() {

// variable declaration
    int AccountNum[11], res; // array declaration and result declaration

    printf("Hello, today we will be running a recursive version of Luhn's algorithm\n");
    printf("I will be prompting you to enter your 11 digit account number one number at a time.\n");
    printf("--------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 11; i++) {
        scanf("%d", &AccountNum[i]); // getting each account number as an element array within AccountNum[]
    }

    printf("Your account number is: ");

    for (int j = 0; j < 11; j++) {
        printf("%d", AccountNum[j]); // displaying the AccountNum[] array back to the User
    }

    printf(". Now to do Luhn's Algorithm recursively\n");
    res = Luhns_Algorithm_Iterative (AccountNum); // calling on luhn's algorithm to convert the account number

    printf("The sum of the account number is %d", res); // displaying the sum of all the account numbers
    if (res % 10 == 0) { // if the sum is able to be divisble by 10 (eligible account)
        printf(". Since the sum is able to be modulo by 10, it's a valid account number.\n");
    }

    else { // if the sum is not able to be divisble by 10 (in elligeble account number.)
        printf(". Since the sum is not able to be modulo by 10, it's not a valid account number.\n");
    }

    printf("--------------------------------------------------------------------------------------------------\n");

    return 0;
}

int Luhns_Algorithm_Iterative (int AccountNum[11]) {

    // variable declaration
    int sum = 0, a, b, product;

    // go through each element in the AccountNum array
    for (int z = 10; z >= 0; z--) { // parse from element 10 to element 0 one index at a time (total 11)

        if (z % 2 == 0) { // if the index is even, simply add that element to the sum var
            sum += AccountNum[z];
        }

        else { // if the index is odd (every other number: index 9, 7, 5, 3, 1)
            product = AccountNum[z] * 2; // take the element and multiply it by 2, store it in the product variable

            if (product > 9) { // if the value of that element is greater than one digit

                a = product / 10; // integer division to divide the product by 10, this results in
                b = product % 10; // modulo to find the remainder of the product by modulo 10
                sum += (a + b); // add the results of the integer divsision and modulo to get the new element, then add it to the sum var

            }

            else { // if the element is a single digit, add it to the sum var
                sum += product;
            }

        }

    }

    return sum; // returns the total sum of the Account Number once every index is parsed within AccountNum array
}

