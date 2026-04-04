#include <stdio.h>
#include <stdlib.h>

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int** image, int rows, int cols, int r, int c, int oldColor, int newColor) {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        return;

    if (image[r][c] != oldColor)
        return;

    image[r][c] = newColor;

    for (int i = 0; i < 4; i++) {
        dfs(image, rows, cols, r + dx[i], c + dy[i], oldColor, newColor);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {

    int oldColor = image[sr][sc];

    if (oldColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    dfs(image, imageSize, imageColSize[0], sr, sc, oldColor, color);

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}