#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        int empty = 0;

        while (numBottles > 0) {
            // Drink all full bottles
            ans += numBottles;
            empty += numBottles;
            numBottles = 0;

            // Exchange empty bottles
            if (empty >= numExchange) {
                empty -= numExchange;  // use empty bottles to get 1 full
                numBottles = 1;        // got one full bottle
                numExchange++;         // increase exchange cost
            } else {
                break;  // can’t exchange anymore
            }
        }
        return ans;
    }
};
