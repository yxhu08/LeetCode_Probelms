/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    
    int m = matrixSize;        // rows
    int n = matrixColSize[0];  // columns

    // Step 1: Allocate array of row pointers
    int** result = (int**)malloc(n * sizeof(int*));

    // Step 2: Allocate column size array
    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    // Step 3: Allocate each row
    for (int i = 0; i < n; i++) {
        result[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }

    // Step 4: Fill transpose
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    // Step 5: Return size
    *returnSize = n;

    return result;
}