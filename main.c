#include <stdio.h>
#include "headerFile.h"

//int Fib(int n, int *errorCode)
//{
//    // **
//
//
//
//    // 1
//
//    int *tmp = (int*) calloc(n, sizeof(int));
//    for (size_t i = 2; i < n; ++i) {
//        tmp[i] = tmp[i - 1] + tmp[i - 2];
//    }
//
//    // 2
//
//    if (n == 0 || n == 1) {
//        *errorCode = 0;
//        return 1;
//    }
//    if (n < 0) {
//        *errorCode = 1;
//        return 0;
//    }
//    return Fib(n - 1) + Fib(n - 2);
//}

int main(void) {
//    printf("%d", Fib(3));
    int a = 4;
    int b = 5;
    int c;

    c = a + b;
    printf("%d", Sum(3, 5));
}
