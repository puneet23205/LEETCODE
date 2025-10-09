#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1; // start with +1

        // Traverse digits from the end
        for (int i = n - 1; i >= 0; i--) {
            digits[i] += carry;

            if (digits[i] == 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
                break; // no more carry needed
            }
        }

        // If carry still left → need one more digit at front
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }

        return digits; // vector automatically carries its own size
    }
};
