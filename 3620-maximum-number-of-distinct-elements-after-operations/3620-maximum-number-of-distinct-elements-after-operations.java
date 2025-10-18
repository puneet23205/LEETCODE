// LeetCode: class Solution { public int maxDistinctElements(int[] nums, int k) { ... } }
import java.util.*;
class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        Arrays.sort(nums);
        long occupied = Long.MIN_VALUE / 4L;
        int ans = 0;
        for (int num : nums) {
            if (occupied < (long)num + k) {
                long take = Math.max(occupied + 1, (long)num - k);
                occupied = take;
                ++ans;
            }
        }
        return ans;
    }
}

