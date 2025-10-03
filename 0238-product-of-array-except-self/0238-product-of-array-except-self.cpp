class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
        vector<int> result(n, 1); // initialize with 1s

        int pre = 1, post = 1;

        // Left (prefix product)
        for (int i = 0; i < n; i++) {
            result[i] = pre;
            pre *= nums[i];
        }

        // Right (postfix product)
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= post;
            post *= nums[i];
        }

        return result;
    }
    
};