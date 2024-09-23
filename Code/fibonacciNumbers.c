#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "headerFile.h"
#include "time.h"

long long FibonacciRecursively(int fibonacciIndex) {
    if (fibonacciIndex == 0 || fibonacciIndex == 1) {
        return 1;
    }
    if (fibonacciIndex < 0) {
        return 0;
    }
    return FibonacciRecursively(fibonacciIndex - 1) + FibonacciRecursively(fibonacciIndex - 2);
}

void FibonaccIteratively(long long fibonacciNumbers[], int fibonacciIndex) {
    for (int i = 2; i <= fibonacciIndex; ++i) {
        fibonacciNumbers[i] = fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2];
    }
}

bool TestFibonacciInputCorrectness(const int fibonacciIndex, const char *endptrFibonacciIndex) {
    if (fibonacciIndex < 0 || *endptrFibonacciIndex != '\0') {
        printf("Input error\n");
        return 0;
    }
    return 1;
}

void FibonacciNumbersTask() {
    char strFibonacciIndex[10];
    char *endptrFibonacciIndex;
    long long fibonacciNumbers[100] = {0};
    fibonacciNumbers[1] = 1;
    int fibonacciIndex = -1;

    printf("Enter how many times you want to calculate the fibonacci number:\n");
    scanf("%s", strFibonacciIndex);
    fibonacciIndex = (int)strtol(strFibonacciIndex, &endptrFibonacciIndex, 10);
    if (!TestFibonacciInputCorrectness(fibonacciIndex, endptrFibonacciIndex)) {
        return;
    }

    clock_t startFibonaccIteratively = clock();
    FibonaccIteratively(fibonacciNumbers, fibonacciIndex);
    clock_t stopFibonaccIteratively = clock();
    double timeSpentFibonaccIteratively = (double)(stopFibonaccIteratively - startFibonaccIteratively) / CLOCKS_PER_SEC;

    printf("\nIterative algorithm: %lld\n Time spent: %f seconds\n", fibonacciNumbers[fibonacciIndex - 1], timeSpentFibonaccIteratively);

    clock_t startFibonacciRecursively = clock();
    printf("Recursive algorithm: %lld\n", FibonacciRecursively(fibonacciIndex - 2));
    clock_t stopFibonacciRecursively = clock();
    double timeSpentFibonacciRecursively = (double)(stopFibonacciRecursively - startFibonacciRecursively) / CLOCKS_PER_SEC;
    printf("Time spent: %f seconds\n", timeSpentFibonacciRecursively);
}