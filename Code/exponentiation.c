#include "headerFile.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long exponentiationLineTime(long baseOfDegree, long exponent) {
    if (exponent == 0) {
        return 1;
    }
    return baseOfDegree * exponentiationLineTime(baseOfDegree, exponent - 1);
}

long exponentiationLogTime(long baseOfDegree, long exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent % 2 == 1) {
        return exponentiationLineTime(baseOfDegree, exponent - 1) * baseOfDegree;
    } else {
        long forSquare = exponentiationLogTime(baseOfDegree, exponent / 2);
        return forSquare * forSquare;
    }
}

bool testInputCorrectness(const char *endptrBaseOfDegree, const char *endptrExponent, const long baseOfDegree) {
    if (baseOfDegree < 0) {
        printf("The base of a degree cannot be negative\n");
        return true;
    }
    if (*endptrBaseOfDegree != '\0' || *endptrExponent != '\0') {
        printf("Input error\n");
        return true;
    }
    return false;
}

bool testForCorrectnessOfCalculation(const double resultExponentiationLogTime, const double resultExponentiationLineTime) {
    return (resultExponentiationLineTime <= 0 || resultExponentiationLogTime <= 0) ? true : false;
}

void exponentiationTask() {
    char strBaseOfDegree[40];
    char strExponent[40];
    char *endptrBaseOfDegree;
    char *endptrExponent;

    long exponent = -1;
    long baseOfDegree = -1;

    printf("Enter the base of the degree: ");
    scanf("%s", strBaseOfDegree);
    baseOfDegree = strtol(strBaseOfDegree, &endptrBaseOfDegree, 10);

    printf("Enter the exponent: ");
    scanf("%s", strExponent);
    exponent = strtol(strExponent, &endptrExponent, 10);

    if (testInputCorrectness(endptrBaseOfDegree, endptrExponent, baseOfDegree)) {
        return;
    }
    if (exponent < 0) {
        exponent *= -1;
        double resultExponentiationLogTime = 1 / (double) exponentiationLogTime(baseOfDegree, exponent);
        double resultExponentiationLineTime = 1 / (double) exponentiationLineTime(baseOfDegree, exponent);
        if (testForCorrectnessOfCalculation(resultExponentiationLogTime, resultExponentiationLineTime)) {
            printf("Values entered are too large");
            return;
        }
        printf("Result for logarithm: %f\n", resultExponentiationLogTime);
        printf("Result for line: %f\n", resultExponentiationLineTime);
    } else {
        long resultExponentiationLogTime = exponentiationLogTime(baseOfDegree, exponent);
        long resultExponentiationLineTime = exponentiationLineTime(baseOfDegree, exponent);
        if (testForCorrectnessOfCalculation((double) resultExponentiationLogTime, (double) resultExponentiationLineTime)) {
            printf("Values entered are too large");
            return;
        }
        printf("Result for logarithm: %ld\n", resultExponentiationLogTime);
        printf("Result for line: %ld\n", resultExponentiationLineTime);
    }
}