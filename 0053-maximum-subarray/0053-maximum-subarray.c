
 int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int currentSum = nums[0]; 

    for (int i = 1; i < numsSize; i++) {
        
        currentSum = (nums[i] > currentSum + nums[i]) ? nums[i] : currentSum + nums[i];

        maxSum = (currentSum > maxSum) ? currentSum : maxSum;
    }

    return maxSum;
}
