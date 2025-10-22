#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, long long k, long long numOperations) {
        unordered_map<long long,int> freq;
        for (int v: nums) freq[v]++;

        map<long long,long long> events;
        for (int v: nums) {
            long long L = (long long)v - k;
            long long R = (long long)v + k;
            events[L] += 1;
            events[R + 1] -= 1;
        }

        vector<long long> pos;
        vector<long long> pref;
        long long cur = 0;
        for (auto &it: events) {
            pos.push_back(it.first);
            cur += it.second;
            pref.push_back(cur);
        }

        long long max_cover = 0;
        for (auto x: pref) max_cover = max(max_cover, x);

        long long ans = min(max_cover, numOperations);

        for (auto &p: freq) {
            long long v = p.first;
            int cntEq = p.second;
            auto it = upper_bound(pos.begin(), pos.end(), v);
            long long cover = 0;
            if (it != pos.begin()) {
                int idx = (int)(it - pos.begin() - 1);
                cover = pref[idx];
            }
            long long cand = min(cover, (long long)cntEq + numOperations);
            ans = max(ans, cand);
        }

        return (int)ans;
    }
};
