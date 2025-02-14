int pivotIndex(int* nums, int numsSize) {
    int totalSum = 0, leftSum = 0;

    
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    
    for (int i = 0; i < numsSize; i++) {
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) {
            return i; 
        }
        leftSum += nums[i]; 
    }

    return -1;
}