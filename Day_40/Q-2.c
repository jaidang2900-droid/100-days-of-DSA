#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    
    int *result = (int*)calloc(temperaturesSize, sizeof(int));
    int *stack = (int*)malloc(sizeof(int) * temperaturesSize);
    int top = -1;

    *returnSize = temperaturesSize;

    for(int i = 0; i < temperaturesSize; i++)
    {
        while(top != -1 && temperatures[i] > temperatures[stack[top]])
        {
            int idx = stack[top--];
            result[idx] = i - idx;
        }

        stack[++top] = i;
    }

    free(stack);
    return result;
}