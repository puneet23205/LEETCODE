# LeetCode: class Solution:
#              def maxDistinctElements(self, nums: List[int], k: int) -> int:
from typing import List
import math

class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        occupied = -10**30
        ans = 0
        for num in nums:
            if occupied < num + k:
                take = max(occupied + 1, num - k)
                occupied = take
                ans += 1
        return ans
