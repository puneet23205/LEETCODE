
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1; 
    
    
    for (int i = digitsSize - 1; i >= 0; i--) {
        digits[i] += carry; 
        if (digits[i] == 10) { 
            digits[i] = 0;
            carry = 1;
        } else { 
            carry = 0;
            break;
        }
    }


    if (carry == 1) {
        *returnSize = digitsSize + 1;
        int* result = (int*)malloc(*returnSize * sizeof(int));
        result[0] = 1;
        for (int i = 1; i < *returnSize; i++) {
            result[i] = 0;
        }
        return result;
    }

    
    *returnSize = digitsSize;
    return digits;
}
