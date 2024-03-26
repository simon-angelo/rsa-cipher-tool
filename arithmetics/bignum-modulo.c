#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "../bignum.h"

// Function to calculate modulo of an array of digits
int arrayModulo(int arr[], int size, int divisor) {
    int remainder = 0;

    // Iterate through the array from left to right
    for (int i = 0; i < size; i++) {
        
        // Calculate the current result including the next digit
        int currentResult = remainder * 10 + arr[i];
        printf("\nr: %d * %d + curr_val: %d = cur_r: %d", remainder, 10, arr[i], currentResult);
        // Update the remainder for the next iteration
        remainder = currentResult % divisor;
        printf("\ncur_r: %d %% %d = upd_r: %d\n\n", currentResult, divisor, remainder);
    }

    // The final remainder is the result of the modulo operation
    return remainder;
}

// NOTE: This function was copied from multiplyBignumShiftLeft() in ../bignum.c. Rename multiplyBignumShiftLeft() to bignumShiftLeft as it can be used in other bignum.c functions other than multiplyBignum().
int bignumShiftLeft(Bignum *result, Bignum *num, unsigned long long int shiftPlaces) {  
    if (shiftPlaces < 0) {
        printf("Shifting Bignum by negative value/s.\n");
        return -1;
    }

    unsigned long long int resultLength = shiftPlaces;

    memset(result->digits, 0, sizeof(int) * shiftPlaces);

    for (unsigned long int i = shiftPlaces, j = 0; j < num->length; i++, j++) {
        result->digits[i] = num->digits[j];
        
        resultLength++;
    }

    result->length = resultLength;
}

unsigned long long int modulo(unsigned long long int dividend, unsigned long long int divisor) {
    unsigned long long int multiplyResult = 0, count;

    unsigned long long int countLowerLimit = pow(10, getLengthOfInteger(dividend) - (getLengthOfInteger(divisor) + 1));
    unsigned long long int countUpperLimit = pow(10, getLengthOfInteger(dividend) - (getLengthOfInteger(divisor) - 1));
    
    
    while(1) {
        count = (countUpperLimit + countLowerLimit) / 2;

        printf("L: %llu | R: %llu | Mid: %llu", countLowerLimit, countUpperLimit, count);

        multiplyResult = divisor * count;
        printf("\ndivisor: %llu * count: %llu = %llu | dividend: %llu\n\n", divisor, count, multiplyResult, dividend);
        if (multiplyResult > dividend) {
            countUpperLimit = count;
        } else if (multiplyResult < dividend) {
            countLowerLimit = count;
        }

        if (
            ((dividend - multiplyResult) < dividend) && 
            (
                (dividend - multiplyResult) >= 0 && 
                (dividend - multiplyResult) < divisor
            )) {
            printf("\n\nLAST COUNT: %llu\n", count);
            break;
        }
    }

    return dividend - (count * divisor);
}

int bignumModulo(Bignum *dividend, int divisor) {
    int remainder = 0;

    // Iterate through the array from left to right
    for (int i = dividend->length - 1; i >= 0; i--) {
        
        // Calculate the current result including the next digit
        int currentResult = remainder * 10 + dividend->digits[i];
        printf("\nr: %d * %d + curr_val: %d = cur_r: %d", remainder, 10, dividend->digits[i], currentResult);
        // Update the remainder for the next iteration
        remainder = currentResult % divisor;
        printf("\ncur_r: %d %% %d = upd_r: %d\n\n", currentResult, divisor, remainder);
    }

    // The final remainder is the result of the modulo operation
    return remainder;
}

int main() {
    // Example: Number 256 represented as [2, 5, 6]
    int numberArray[] = {6,0,4,3,6,8,9,1};
    int divisor = 56;
    // int numberArray[] = {6,0,4,3,3,0,5,2,8,8,2,7,6,1,1,8,4,3};
    int arraySize = 4;

    Bignum bignumDividend = initBignum();
    Bignum bignumDivisor = initBignum();
    Bignum bignumResult = initBignum();

    setBignum(&bignumDividend, "60436891", positive);

    // printf("\n");
    // for(int i = 0; i < sizeof(numberArray)/sizeof(numberArray[0]); i++) {
    //     printf("%d", numberArray[i]);
    // }
    // printf(" modulo %d is:\n", divisor);

    // int moduloResult = arrayModulo(numberArray, arraySize, divisor);
    // int bignumModuloResult = bignumModulo(&bignumDividend, divisor);

    // Display the result
    // printf("Modulo result: %d\n", moduloResult);
    // printf("Bignum Modulo result: %d\n", bignumModuloResult);

    long long int x = LLONG_MAX;
    long long int y = 2;
    // int x = 111;
    // int y = 20;

    printf("\n\n%llu %% %llu = %llu\n\n", x, y, modulo(x, y));

    return 0;
}