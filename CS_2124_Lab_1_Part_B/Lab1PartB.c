//Author:  Elisha Lucile C. Ong  & Varun Prasad
//Assignment Number: Lab1 Part B
//File Name: ElishaOngL1.zip
//Course/Section: CS 2124 Section 0C1
//Date: 9/17/2021
//Instructor: Bernard Ku

#include <stdio.h>
int Luhns_Algorithm_Iterative(int numArr[]);
int luhnsRecursive(int numArr2[]);    /*for printf, scanf definitions*/


int k = 10;                         /*global iteration variable*/
int sum = 0;                        /*global sum definition*/

int main(int argc, char *argv[])
{
    int accountNum[11];            //array for the 11-digit account number
    int i, recursiveResult, iterativeResult;                 //i for iteration var, result for the result of the recursive function
    
    for(i = 0; i < 11; i++)       //gets the input from the user
    {
        scanf("%d",&accountNum[i]);
    }
    recursiveResult = luhnsRecursive(accountNum);     //calls the function 
    iterativeResult =  Luhns_Algorithm_Iterative(accountNum);
    
    printf("%d\n", recursiveResult);                   //prints result   
    printf("The sum of the account number is %d\n", iterativeResult);       
    if (iterativeResult % 10 == 0)
    {
        printf(". Since the sum is able to be modulo by 10, it's a valid account number.\n");
    }
    else {                               // if the sum is not able to be divisble by 10 (in elligeble account number.)
        printf(". Since the sum is not able to be modulo by 10, it's not a valid account number.\n");
    }
    
    return 0;
}

//We used the Luhn's algorithm to check random account numbers 

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

int luhnsRecursive(int numArr2[11])
{
    int a,b,product;           //a = placeholder for first digit, b = placeholder for second digit
    
    if (k < 0)                //returns the total once k reaches below 0
    {
        return sum;
    } 
    else if (k >= 0)         //checks if k >= 0
    {
        if (k % 2 != 0)               //checks if k is NOT even. since the array has 11 elements, every other element 
        {                                //iteration will be odd.
            product = numArr2[k] * 2;   //multiplies the element by 2 and splits it into two digits
            a = product / 10;         //if the product is less than 0, a will be 0 because of integer division ex: 4 / 10 = 0;
            b = product % 10;         //if the product is greater than 9, a will be the first digit, b will be the second
            sum += (a+b);             //this will add them together
            k--;                    //subtracts the iteration variable
        }
        else                //if k is even it will just add the element and sum together
        {
            sum += numArr2[k];
            k--;
        }
        luhnsRecursive(numArr2);    //calls the function again
    }
    
}