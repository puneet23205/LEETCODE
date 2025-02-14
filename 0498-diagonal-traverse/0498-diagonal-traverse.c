/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    int total = matSize * (*matColSize);
    *returnSize = total;
    int* result = (int*)malloc(total * sizeof(int));
    int r = 0, c = 0, dir = 1;
    
    for (int i = 0; i < total; i++) {
        result[i] = mat[r][c];
        if (dir == 1) {
            if (c == *matColSize - 1) {
                r++; dir = -1;
            } else if (r == 0) {
                c++; dir = -1;
            } else {
                r--; c++;
            }
        } else {
            if (r == matSize - 1) {
                c++; dir = 1;
            } else if (c == 0) {
                r++; dir = 1;
            } else {
                r++; c--;
            }
        }
    }
    return result;
}