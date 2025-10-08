#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        
        unordered_map<string, vector<string>> ansMap;
        vector<int> count(26, 0);
        
        for (string s : strs) {
            fill(count.begin(), count.end(), 0);
            
            for (char c : s) {
                count[c - 'a']++;
            }
            
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += "#" + to_string(count[i]);
            }
            
            ansMap[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& it : ansMap) {
            result.push_back(it.second);
        }
        return result;
    }
};
