class Solution {
public:
    int maxProduct(vector<int>& nums) {
         if (nums.empty()) return 0;

        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int tempMax = max({curr, curr * maxProd, curr * minProd});
            minProd = min({curr, curr * maxProd, curr * minProd});
            maxProd = tempMax;

            result = max(result, maxProd);
        }
        return result;
    }
    
};