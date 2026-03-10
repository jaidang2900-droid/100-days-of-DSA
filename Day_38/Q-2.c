#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    
    if(numsSize == 0){
        *returnSize = 0;
        return NULL;
    }

    int *result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    int *deque = (int*)malloc(sizeof(int) * numsSize);

    int front = 0, rear = -1;
    int idx = 0;

    for(int i = 0; i < numsSize; i++)
    {
        // Remove indices out of window
        if(front <= rear && deque[front] <= i - k)
            front++;

        // Remove smaller elements from rear
        while(front <= rear && nums[deque[rear]] < nums[i])
            rear--;

        // Add current index
        deque[++rear] = i;

        // Store result when window size is reached
        if(i >= k - 1)
            result[idx++] = nums[deque[front]];
    }

    *returnSize = numsSize - k + 1;

    free(deque);
    return result;
}