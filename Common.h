#ifndef COMMON_H
#define COMMON_H

#define MAX(A, B) (A > B ? A : B)
#define MIN(A, B) (A < B ? A : B)
#define ArraySize(A) (sizeof(A) / sizeof(A[0]))

void checkNullPointer(void * list);

#endif // COMMON_H
