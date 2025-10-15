import java.util.*;

class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int n = nums.size();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = nums.get(i);

        int[] inc = new int[n];
        int[] dec = new int[n];
        Arrays.fill(inc, 1);
        Arrays.fill(dec, 1);

        // increasing sequence lengths
        for (int i = 1; i < n; i++)
            if (arr[i] > arr[i - 1])
                inc[i] = inc[i - 1] + 1;

        // decreasing from right
        for (int i = n - 2; i >= 0; i--)
            if (arr[i] < arr[i + 1])
                dec[i] = dec[i + 1] + 1;

        int res = 0;
        for (int i = 0; i < n - 1; i++)
            res = Math.max(res, Math.min(inc[i], dec[i + 1]));

        return res;
    }
}
