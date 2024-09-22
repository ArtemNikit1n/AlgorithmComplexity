#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "headerFile.h"

void StartingTask(char taskNumber) {
    if (taskNumber == '1') {
        HalfQsortTask();
    }
    if (taskNumber == '2') {
        BubbleAndCountingTask();
    }
    if (taskNumber == '3') {
        ExponentiationTask();
    }
    if (taskNumber == '4') {
        printf("Not ready");
    }
}

bool TestInputCorrectnessForMain(const char *taskNumber) {
    size_t lengthTaskNumber = strlen(taskNumber);
    if (*taskNumber == '0') {
        return 1;
    }
    if (strlen(taskNumber) > 1) {
        return 1;
    }
    return 0;
}

int main() {
    char taskNumber = '0';
    printf("Enter the task number from 1 to 4:\n");
    scanf("%[1234]", &taskNumber);

    if (TestInputCorrectnessForMain(&taskNumber)) {
        printf("Input error");
        return 1;
    }

    StartingTask(taskNumber);
    return 0;
}
