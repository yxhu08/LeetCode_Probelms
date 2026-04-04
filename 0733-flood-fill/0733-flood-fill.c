/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

// DFS function
void dfs(int** image, int m, int n, int r, int c, int original, int newColor) {
    
    // Boundary check
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    // If color doesn't match original → stop
    if (image[r][c] != original)
        return;

    // Fill color
    image[r][c] = newColor;

    // Explore 4 directions
    dfs(image, m, n, r + 1, c, original, newColor);
    dfs(image, m, n, r - 1, c, original, newColor);
    dfs(image, m, n, r, c + 1, original, newColor);
    dfs(image, m, n, r, c - 1, original, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    
    int m = imageSize;
    int n = imageColSize[0];

    int original = image[sr][sc];

    // Important check
    if (original == color) {
        *returnSize = m;
        *returnColumnSizes = imageColSize;
        return image;
    }

    // Call DFS
    dfs(image, m, n, sr, sc, original, color);

    // Return result
    *returnSize = m;
    *returnColumnSizes = imageColSize;

    return image;
}