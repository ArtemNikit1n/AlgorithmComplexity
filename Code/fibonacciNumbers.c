#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headerFile.h"
#include "time.h"

long long fibonacciRecursively(int fibonacciIndex) {
    if (fibonacciIndex == 0 || fibonacciIndex == 1) {
        return 1;
    }
    if (fibonacciIndex < 0) {
        return 0;
    }
    return fibonacciRecursively(fibonacciIndex - 1) + fibonacciRecursively(fibonacciIndex - 2);
}

void fibonaccIteratively(long long fibonacciNumbers[], int fibonacciIndex) {
    for (int i = 2; i <= fibonacciIndex; ++i) {
        fibonacciNumbers[i] = fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2];
    }
}

bool testFibonacciInputCorrectness(const int fibonacciIndex, const char *endptrFibonacciIndex) {
    return (fibonacciIndex < 0 || *endptrFibonacciIndex != '\0') ? true : false;
}

void fibonacciNumbersTask() {
    char strFibonacciIndex[10];
    char *endptrFibonacciIndex;
    long long fibonacciNumbers[100] = {0};
    fibonacciNumbers[1] = 1;
    int fibonacciIndex = -1;

    printf("Enter how many times you want to calculate the fibonacci number:\n");
    scanf("%s", strFibonacciIndex);
    fibonacciIndex = (int)strtol(strFibonacciIndex, &endptrFibonacciIndex, 10);
    if (testFibonacciInputCorrectness(fibonacciIndex, endptrFibonacciIndex)) {
        printf("Input error\n");
        return;
    }

    clock_t startFibonaccIteratively = clock();
    fibonaccIteratively(fibonacciNumbers, fibonacciIndex);
    clock_t stopFibonaccIteratively = clock();
    double timeSpentFibonaccIteratively = (double)(stopFibonaccIteratively - startFibonaccIteratively) / CLOCKS_PER_SEC;

    printf("\nIterative algorithm: %lld\n Time spent: %f seconds\n", fibonacciNumbers[fibonacciIndex - 1], timeSpentFibonaccIteratively);

    clock_t startFibonacciRecursively = clock();
    printf("Recursive algorithm: %lld\n", fibonacciRecursively(fibonacciIndex - 2));
    clock_t stopFibonacciRecursively = clock();
    double timeSpentFibonacciRecursively = (double)(stopFibonacciRecursively - startFibonacciRecursively) / CLOCKS_PER_SEC;
    printf("Time spent: %f seconds\n", timeSpentFibonacciRecursively);
}