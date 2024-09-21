#include <stdio.h>
#include "stdlib.h"
#include <stdbool.h>
#include <time.h>

void Swap(int *first, int *second)
{
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
}

void RealizationHalfQsort(int array[100], int arrayLength) {
    int firstElement = array[0];
    for (int i = 1; i < arrayLength; ++i) {
        if (firstElement > array[i]) {
            Swap(&array[i - 1], &array[i]);
        } else {
            Swap(&array[i], &array[arrayLength - 1]);
            --i;
            --arrayLength;
        }
    }
}

bool TestInputCorrectnessForHalfQsort(int arrayLength) {
    if (arrayLength > 0) {
        return 0;
    }
    return 1;
}

bool TestCorrectSorting(int array[100], int firstElement, int arrayLength) {
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
            return 1;
        }
        if (j > indexFirstElement && array[j] < firstElement) {
            return 1;
        }
    }
    return 0;
}

void HalfQsortTask() {
    srand(time(NULL));
    int arrayLength = 0;
    int arrayRand[100];

    printf("Enter the number of elements in the array (<100):\n");
    scanf("%d", &arrayLength);

    if (TestInputCorrectnessForHalfQsort(arrayLength)) {
        printf("Input error");
        return;
    }

    int firstElement = arrayRand[0];

    printf("Initial array:\n");
    for (int i = 0; i < arrayLength; ++i) {
        arrayRand[i] = rand() % 10;
        printf("%d ", arrayRand[i]);
    }
    arrayRand[0] = 1;

    RealizationHalfQsort(arrayRand, arrayLength);

    if (TestCorrectSorting(arrayRand, firstElement, arrayLength)) {
        printf("Program error");
        return;
    }

    printf("\nResult:\n");
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d ", arrayRand[i]);
    }
}