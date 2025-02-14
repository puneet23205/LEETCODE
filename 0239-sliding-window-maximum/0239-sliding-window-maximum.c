
#include <stdlib.h>

// Function to find the maximum in each sliding window
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numsSize - k + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int));
    int front = 0, rear = -1;

    for (int i = 0; i < numsSize; i++) {
        // Remove indices of elements not in the current window
        while (front <= rear && deque[front] < i - k + 1) {
            front++;
        }

        // Remove indices of all elements smaller than the current element
        while (front <= rear && nums[deque[rear]] < nums[i]) {
            rear--;
        }

        // Add the current element's index to the deque
        deque[++rear] = i;

        // The element at the front of the deque is the largest in the current window
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[front]];
        }
    }

    free(deque);
    return result;
}



