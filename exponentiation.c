#include "headerFile.h"
#include <stdbool.h>
#include <stdio.h>

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

bool TestInputCorrectness(const int baseOfDegree, const int exponent) {
    if (exponent < 0 || baseOfDegree < 0) {
        printf("Input error\n");
        return 0;
    }
    return 1;
}

void Exponentiation() {
    int baseOfDegree = -1;
    int exponent = -1;

    printf("Enter the degree base (a) and the exponent (b) according to the example: a^b\n");
    scanf("%d^%d", &baseOfDegree, &exponent);

    if (TestInputCorrectness(baseOfDegree, exponent)) {
        printf("Result for logarithm: %ld\n", ExponentiationLogTime(baseOfDegree, exponent));
        printf("Result for line: %ld\n", ExponentiationLineTime(baseOfDegree, exponent));
    }
}