class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);  // default dry any lake as 1
        unordered_map<int, int> full;  // lake -> last day it was filled
        set<int> dryDays;  // stores indices of days when we can dry

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);  // available dry day
            } else {
                ans[i] = -1;  // raining day, cannot assign lake number

                if (full.find(rains[i]) != full.end()) {
                    // this lake was already full -> must find a dry day after it
                    int lastDay = full[rains[i]];
                    auto dryIt = dryDays.lower_bound(lastDay);
                    if (dryIt == dryDays.end()) {
                        return {}; // no valid dry day -> flood
                    }

                    ans[*dryIt] = rains[i];  // dry this lake on that dry day
                    dryDays.erase(dryIt);    // remove this dry day
                }

                full[rains[i]] = i;  // mark lake as full on this day
            }
        }

        return ans;
    }
};
