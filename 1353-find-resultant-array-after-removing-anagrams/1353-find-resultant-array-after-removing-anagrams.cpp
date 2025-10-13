#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prevSorted = "";

        for (string word : words) {
            string sorted = word;
            sort(sorted.begin(), sorted.end());

            if (sorted != prevSorted) {
                result.push_back(word);
                prevSorted = sorted;
            }
        }
        return result;
    }
};
