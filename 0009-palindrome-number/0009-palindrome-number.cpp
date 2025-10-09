class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers can never be palindromes
        if (x < 0) return false;

        int original = x;  // store original number
        long long reversed = 0;

        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x = x / 10;
        }

        return (reversed == original);
    }
};
