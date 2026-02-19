#include <limits.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    
    int totalSum = 0;
    
    int maxSum = nums[0];
    int currMax = 0;
    
    int minSum = nums[0];
    int currMin = 0;
    
    for(int i = 0; i < numsSize; i++) {
        
        currMax = currMax + nums[i];
        if(currMax < nums[i])
            currMax = nums[i];
        
        if(currMax > maxSum)
            maxSum = currMax;
        
        
        currMin = currMin + nums[i];
        if(currMin > nums[i])
            currMin = nums[i];
        
        if(currMin < minSum)
            minSum = currMin;
        
        
        totalSum = totalSum + nums[i];
    }
    
    if(maxSum < 0)
        return maxSum;
    
    if(maxSum > (totalSum - minSum))
        return maxSum;
    else
        return (totalSum - minSum);
}
