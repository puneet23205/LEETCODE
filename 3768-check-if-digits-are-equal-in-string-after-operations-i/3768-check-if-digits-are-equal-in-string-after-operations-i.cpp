class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string t = "";
            for (int i = 0; i < s.length() - 1; i++) {
                int x = (s[i] - '0' + s[i+1] - '0') % 10; // convert to int
                t += (x + '0');  // convert back to char
            }
            s = t; // update s after full transformation
        }
        return s[0] == s[1];
    }
};
