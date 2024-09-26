#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
#include <time.h>
#include <assert.h>

void swap(int *first, int *second)
{
    if (*first == *second) {
        return;
    }
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
}

void realizationHalfQsort(int array[], int arrayLength) {
    int firstElement = array[0];
    for (int i = 1; i < arrayLength; ++i) {
        if (firstElement > array[i]) {
            swap(&array[i - 1], &array[i]);
        } else {
            if (array[i] == array[arrayLength - 1]) {
                --arrayLength;
                --i;
                continue;
            }
            swap(&array[i], &array[arrayLength - 1]);
            --arrayLength;
            --i;
        }
    }
}

bool testCorrectSortingTask1(const int array[], int firstElement, int arrayLength) {
    int i = 0;
    int indexFirstElement = -1;
    while (array[i] < arrayLength) {
        if (array[i] == firstElement) {
            indexFirstElement == i;
            break;
        }
        ++i;
    }

    for (int j = 0; j < arrayLength; ++j) {
        if (j < indexFirstElement && array[j] > firstElement) {
            return true;
        }
        if (j > indexFirstElement && array[j] < firstElement) {
            return true;
        }
    }
    return false;
}

void halfQsortTask() {
    srand(time(NULL));
    int arrayLength = 0;
    int arrayRand[100];

    printf("Enter the number of elements in the array (<100):\n");
    scanf("%d", &arrayLength);
    assert(arrayLength < 100 && arrayLength > 0);

    int firstElement = arrayRand[0];

    printf("Initial array:\n");
    for (int i = 0; i < arrayLength; ++i) {
        arrayRand[i] = rand();
        printf("%d ", arrayRand[i]);
    }

    realizationHalfQsort(arrayRand, arrayLength);

    if (testCorrectSortingTask1(arrayRand, firstElement, arrayLength)) {
        printf("Program error");
        return;
    }

    printf("\nResult:\n");
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d ", arrayRand[i]);
    }
}