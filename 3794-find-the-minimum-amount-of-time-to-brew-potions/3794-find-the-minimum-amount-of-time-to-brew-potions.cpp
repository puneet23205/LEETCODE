#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        if (n == 0 || m == 0) return 0;

        long long accumulatedStart = 0; // start_{j} = sum of deltas up to j-1

        // compute minimal gaps (deltas) between consecutive potions
        for (int j = 0; j < m - 1; ++j) {
            long long cumCurr = 0;   // S_i(j)
            long long cumNextPrev = 0; // S_{i-1}(j+1)
            long long delta = LLONG_MIN;
            for (int i = 0; i < n; ++i) {
                cumCurr += (long long)skill[i] * mana[j];
                // cumNextPrev is sum up to i-1 for next potion (0 for i==0)
                delta = max(delta, cumCurr - cumNextPrev);
                // update cumNextPrev for next iteration (becomes sum up to i)
                cumNextPrev += (long long)skill[i] * mana[j + 1];
            }
            accumulatedStart += delta;
        }

        // finish time = start of last potion + its total processing across all wizards
        long long lastJobTotal = 0;
        for (int i = 0; i < n; ++i) lastJobTotal += (long long)skill[i] * mana[m - 1];

        return accumulatedStart + lastJobTotal;
    }
};

