/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int row = matrixSize;
    int col = *matrixColSize;
    *returnSize = col;
    *returnColumnSizes = (int*)malloc(col * sizeof(int));
    int** transposed = (int**)malloc(col * sizeof(int*));
    for (int i = 0; i < col; i++) {
        (*returnColumnSizes)[i] = row;
        transposed[i] = (int*)malloc(row * sizeof(int));
        for (int j = 0; j < row; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}