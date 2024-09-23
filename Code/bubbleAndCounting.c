#include <stdio.h>
#include <stdlib.h>
#include "headerFile.h"
#include "time.h"
#include <stdbool.h>

#define RANGE_OF_VALUES 100

void FillingAnArray(int array[], size_t arrayLength) {
    srand(time(NULL));
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = rand() % 100;
    }
}

void BubbleSort(int array[], size_t arrayLength) {
    while (arrayLength > 1) {
        for (int i = 0; i < arrayLength - 1; ++i) {
            if (array[i] > array[i + 1]) {
                Swap(&array[i + 1], &array[i]);
            }
        }
        --arrayLength;
    }
}

void CountingSort(int array[], size_t arrayLength) {
    int j = 0;
    int arrayToCount[RANGE_OF_VALUES] = {0};
    for (int i = 0; i < arrayLength; ++i) {
        ++arrayToCount[array[i]];
    }
    for (int i = 0; i < RANGE_OF_VALUES; ++i) {
        if (arrayToCount[i] != 0) {
            while (arrayToCount[i] != 0) {
                array[j] = i;
                ++j;
                --arrayToCount[i];
            }
        }
    }
}

bool TestCorrectSortingTask2(const int array[], size_t arrayLength) {
    for (int i = 0; i < arrayLength - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return 1;
        }
    }
    return 0;
}

bool TestForCorrectMemoryAllocation(const int array[]) {
    if (array == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }
    return 0;
}

void BubbleAndCountingTask() {
    size_t arrayLength = 10000;

    int *arrayForBubble = (int *)malloc(arrayLength * sizeof(int));
    if (TestForCorrectMemoryAllocation(arrayForBubble)) {
        return;
    }

    FillingAnArray(arrayForBubble, arrayLength);

    clock_t startBubbleSort = clock();
    BubbleSort(arrayForBubble, arrayLength);
    clock_t endBubbleSort = clock();

    if (TestCorrectSortingTask2(arrayForBubble, arrayLength)) {
        printf("Program error");
        return;
    }
    double timeSpentBubbleSorting = (double)(endBubbleSort - startBubbleSort) / CLOCKS_PER_SEC;

    free(arrayForBubble);
    int *arrayForCounting = malloc(arrayLength * sizeof(int));
    if (TestForCorrectMemoryAllocation(arrayForCounting)) {
        return;
    }

    FillingAnArray(arrayForCounting, arrayLength);

    clock_t startCountingSort = clock();
    CountingSort(arrayForCounting, arrayLength);
    clock_t endCountingSort = clock();
    double timeSpentCountingSort = (double)(endCountingSort - startCountingSort) / CLOCKS_PER_SEC;

    free(arrayForCounting);
    printf("Time taken for bubble sorting: %f seconds", timeSpentBubbleSorting);
    printf("\nTime taken for counting sorting: %f seconds\n", timeSpentCountingSort);
}