class Solution {
public:
    int findMin(vector<int>& nums) {
         int low = 0;
        int high = nums.size() - 1;
        int ans = nums[0];

        while (low <= high) {
            // Case: subarray already sorted
            if (nums[low] < nums[high]) {
                ans = nums[low];
                break;
            }

            int mid = (low + high) / 2;
            ans = min(ans, nums[mid]);

            // Left half sorted, move right
            if (nums[low] <= nums[mid]) {
                low = mid + 1;
            }
            // Right half unsorted, move left
            else {
                high = mid;
            }
        }

        return ans;
    }
};