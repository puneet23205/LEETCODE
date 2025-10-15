class Solution:
    def maxIncreasingSubarrays(self, nums):
        n = len(nums)
        inc = [1] * n

        # Step 1: Compute increasing sequence lengths ending at each position
        for i in range(1, n):
            if nums[i] > nums[i-1]:
                inc[i] = inc[i-1] + 1
        
        # Step 2: Traverse from right and track adjacent subarrays
        res = 0
        dec = [1] * n
        for i in range(n-2, -1, -1):
            if nums[i] < nums[i+1]:
                dec[i] = dec[i+1] + 1

        for i in range(n-1):
            res = max(res, min(inc[i], dec[i+1]))
        
        return res
