class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {  // repeat until single digit remains
            int remSum = 0;
            while (num > 0) {
                remSum += num % 10;
                num /= 10;
            }
            num = remSum;  // assign the sum as new number
        }
        return num;
    }
};
