// LeetCode: class Solution { public: int maxDistinctElements(vector<int>& nums, int k) { ... } };
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long occupied = LLONG_MIN / 4; // very small sentinel
        int ans = 0;
        for (int num : nums) {
            // if there exists some value > occupied and <= num+k
            if (occupied < (long long)num + k) {
                long long take = max(occupied + 1, (long long)num - k);
                occupied = take;
                ++ans;
            }
        }
        return ans;
    }
};

