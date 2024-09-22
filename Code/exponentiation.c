#include "headerFile.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long ExponentiationLineTime(long baseOfDegree, long exponent) {
    if (exponent == 0) {
        return 1;
    }
    return baseOfDegree * ExponentiationLineTime(baseOfDegree, exponent - 1);
}

long ExponentiationLogTime(long baseOfDegree, long exponent) {
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

bool TestInputCorrectness(const char *endptrBaseOfDegree, const char *endptrExponent, const long baseOfDegree) {
    if (baseOfDegree < 0) {
        printf("The base of a degree cannot be negative\n");
        return 1;
    }
    if (*endptrBaseOfDegree != '\0' || *endptrExponent != '\0') {
        printf("Input error\n");
        return 1;
    }
    return 0;
}

bool TestForCorrectnessOfCalculation(const double resultExponentiationLogTime, const double resultExponentiationLineTime) {
    if (resultExponentiationLineTime <= 0 || resultExponentiationLogTime <= 0) {
        printf("Values entered are too large");
        return 1;
    }
    return 0;
}

void ExponentiationTask() {
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

    if (TestInputCorrectness(endptrBaseOfDegree, endptrExponent, baseOfDegree)) {
        return;
    }
    if (exponent < 0) {
        exponent *= -1;
        double resultExponentiationLogTime = 1 / (double)ExponentiationLogTime(baseOfDegree, exponent);
        double resultExponentiationLineTime = 1 / (double)ExponentiationLineTime(baseOfDegree, exponent);
        if (TestForCorrectnessOfCalculation(resultExponentiationLogTime, resultExponentiationLineTime)) {
            return;
        }
        printf("Result for logarithm: %f\n", resultExponentiationLogTime);
        printf("Result for line: %f\n", resultExponentiationLineTime);
    } else {
        long resultExponentiationLogTime = ExponentiationLogTime(baseOfDegree, exponent);
        long resultExponentiationLineTime = ExponentiationLineTime(baseOfDegree, exponent);
        if (TestForCorrectnessOfCalculation((double)resultExponentiationLogTime, (double)resultExponentiationLineTime)) {
            return;
        }
        printf("Result for logarithm: %ld\n", resultExponentiationLogTime);
        printf("Result for line: %ld\n", resultExponentiationLineTime);
    }
}