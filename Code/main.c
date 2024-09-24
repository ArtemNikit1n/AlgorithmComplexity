#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "headerFile.h"

void startingTask(char taskNumber) {
    if (taskNumber == '1') {
        halfQsortTask();
    }
    if (taskNumber == '2') {
        bubbleAndCountingTask();
    }
    if (taskNumber == '3') {
        exponentiationTask();
    }
    if (taskNumber == '4') {
        fibonacciNumbersTask();
    }
}

bool testInputCorrectnessForMain(const char *taskNumber) {
    size_t lengthTaskNumber = strlen(taskNumber);
    return (*taskNumber == '0') ? true : false;
    return (strlen(taskNumber) > 1) ? true : false;
}

int main() {
    char taskNumber = '0';
    printf("Enter the task number from 1 to 4:\n");
    scanf("%[0123456789]", &taskNumber);

    if (testInputCorrectnessForMain(&taskNumber)) {
        printf("Input error");
        return 1;
    }

    startingTask(taskNumber);
    return 0;
}
