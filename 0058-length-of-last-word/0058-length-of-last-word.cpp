class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;

        // Step 1: Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Step 2: Count characters of the last word
        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length; // Step 3: Return the count
    }
};
