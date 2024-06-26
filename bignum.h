#ifndef BIGNUM_H
#define BIGNUM_H

#include <limits.h>

#define MAX_BIGNUM_LENGTH 1000
// REFACTOR: REMOVE PREPROCESSORS
#define MAX_VALUE_OF_SHORT SHRT_MAX
#define MAX_VALUE_OF_INT INT_MAX
#define MAX_VALUE_OF_LONG LONG_MAX
#define MAX_VALUE_OF_LONG_LONG_INT LLONG_MAX
#define MAX_VALUE_OF_UNSIGNED_SHORT USHRT_MAX
#define MAX_VALUE_OF_UNSIGNED_INT UINT_MAX
#define MAX_VALUE_OF_UNSIGNED_LONG ULONG_MAX
#define MAX_VALUE_OF_UNSIGNED_LONG_LONG_INT ULLONG_MAX

typedef enum {
    positive = 0,
    negative = 1
} BIGNUM_SIGN;

typedef struct {
    // Integer will be in reverse for easier arithmetic
    int digits[MAX_BIGNUM_LENGTH];
    // Number of digits in integer
    // Bignum.length will cap out at around 18,446,744,073,709,551,615 (ref: C docs). Therefore the Bignum can only have a maximum of 18,446,744,073,709,551,615 digits.
    unsigned long long int length;
    // Sign will be 0 (positive) or 1 (negative), following the binary sign bit convention.
    BIGNUM_SIGN sign;
} Bignum;

int getLengthOfInteger(long long int num);
Bignum initBignum();
void setBignum(Bignum *numStruct, char numStr[], BIGNUM_SIGN sign);
void intToBignum(Bignum *numStruct, unsigned long long int integer, BIGNUM_SIGN sign);
long long int bignumToInt(Bignum *num);
int resetBignum(Bignum *num);

void copyBignum(Bignum *result, Bignum *num);
void printBignum(Bignum *num);
void printBignumCenter(Bignum *num, unsigned int requiredWidth);
void trimBignum(Bignum *num);

int isGreaterThanBignum(Bignum *num1, Bignum *num2);
int isLessThanBignum(Bignum *num1, Bignum *num2);
int isLessThanOrEqualToBignum(Bignum *num1, Bignum *num2);
int isEqualToBignum(Bignum *num1, Bignum *num2);
int isBignumZero(Bignum *num);
int incrementBignum(Bignum *num, unsigned long long int incrementValue);

void addBignum(Bignum *result, Bignum *num1, Bignum *num2);
void subtractBignum(Bignum *result, Bignum *num1, Bignum *num2);
int multiplyBignum(Bignum *result, Bignum *multiplicand, Bignum *multiplier);
int divideBignum(Bignum *result, Bignum *dividend, Bignum *divisor);
int moduloBignum(Bignum *result, Bignum *dividend, Bignum *divisor);

int halfBignum(Bignum *result, Bignum *num);
int generateRandomBignum(Bignum *result, unsigned long long int numOfDigits, BIGNUM_SIGN sign);

#endif /* BIGNUM_H */