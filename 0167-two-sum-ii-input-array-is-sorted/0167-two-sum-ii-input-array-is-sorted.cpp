class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
               int left = 0;
        int right = numbers.size() - 1;

        // Use two-pointer approach
        while (left <= right) {
            int sum = numbers[left] + numbers[right];

            if (sum > target) {
                right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                // Return 1-based indices as per problem requirement
                return {left + 1, right + 1};
            }
        }

        return {}; // return empty vector if no pair found
    }
};