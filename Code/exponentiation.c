#include "headerFile.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long ExponentiationLineTime(int baseOfDegree, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return baseOfDegree * ExponentiationLineTime(baseOfDegree, exponent - 1);
}

long ExponentiationLogTime(int baseOfDegree, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent % 2 == 1) {
        return ExponentiationLineTime(baseOfDegree, exponent - 1) * baseOfDegree;
    } else {
        long forSquare = ExponentiationLogTime(baseOfDegree, exponent / 2);
        return forSquare * forSquare;
    }
}

bool TestInputCorrectness(const char strBaseOfDegree[50], const char strExponent[50]) {
//    if ()
//    if (baseOfDegree < 0) {
//        printf("Input error\n");
//        return 0;
//    }
    return 1;
}

void ExponentiationTask() {
    char inputString[100];
    char strBaseOfDegree[50];
    char strExponent[50];
    char *endptrExponent;
    char *endptrBaseOfDegree;
    int exponent = -1;
    int baseOfDegree = -1;

    do {
        printf("Enter the degree base (a) and the exponent (b) according to the example: a^b\n");

        if (TestInputCorrectness(strBaseOfDegree, strExponent)) {
            break;
        }
    } while (1);

    if (exponent < 0) {
        exponent *= -1;
        printf("Result for logarithm: %f\n", 1 / (double)ExponentiationLogTime(baseOfDegree, exponent));
        printf("Result for line: %f\n", 1 / (double)ExponentiationLineTime(baseOfDegree, exponent));
    } else {
        printf("Result for logarithm: %ld\n", ExponentiationLogTime(baseOfDegree, exponent));
        printf("Result for line: %ld\n", ExponentiationLineTime(baseOfDegree, exponent));
    }
}