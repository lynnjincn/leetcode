#include <stdio.h>
#include <stdlib.h>

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minPathSum(int **grid, int gridSize, int *gridColSize)
{
    if (gridColSize == NULL) {
        return 0;
    }

    int column = gridSize;     //行
    int row = gridColSize[0];  // 列
    int i, j;
    long **dp;

    PRINTF("\n[%3d]column=%d, row=%d", __LINE__, column, row);

    if ((column == 0) && (row == 0)) {
        return 0;
    }

    PRINTF("\n[%3d]grid:", __LINE__);
    for (i = 0; i < column; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < row; j++) {
            PRINTF(" %3d ", grid[i][j]);
        }
    }

    dp = (long **)malloc((sizeof(long *) * column));
    if (dp == NULL) {
        return 0;
    } else {
        for (i = 0; i < gridSize; i++) {
            dp[i] = (long *)malloc(sizeof(long) * row);
            if (dp[i] == NULL) {
                return 0;
            } else {
                memset(dp[i], 0, sizeof(long *) * row);
            }
        }
    }

    dp[0][0] = grid[0][0];
    for (i = 1; i < column; i++) {
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    }

    for (j = 1; j < row; j++) {
        dp[0][j] = grid[0][j] + dp[0][j - 1];
    }

    PRINTF("\n[%3d]init dp:", __LINE__);
    for (i = 0; i < column; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < row; j++) {
            PRINTF(" %3d ", (int)dp[i][j]);
        }
    }

    for (i = 1; i < column; i++) {
        for (j = 1; j < row; j++) {
            PRINTF("\n[%3d]grid[%d][%d]=%d", __LINE__, i, j, grid[i][j]);
            dp[i][j] = MIN(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    PRINTF("\n[%3d]calculated dp:", __LINE__);
    for (i = 0; i < column; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < row; j++) {
            PRINTF(" %3d ", dp[i][j]);
        }
    }

    return dp[column - 1][row - 1];
}

int main()
{
    int **two_dimensional_array;
    int column = 0;
    int row = 0;
    int i, j;

    printf("\ninput column:");
    scanf("%d", &column);
    printf("\ninput row:");
    scanf("%d", &row);

    two_dimensional_array = (long **)malloc((sizeof(long *) * column));
    if (two_dimensional_array == NULL) {
        return 0;
    } else {
        for (i = 0; i < column; i++) {
            two_dimensional_array[i] = (long *)malloc(sizeof(long) * row);
            if (two_dimensional_array[i] == NULL) {
                return 0;
            } else {
                memset(two_dimensional_array[i], 0, sizeof(long *) * row);
            }
        }
    }

    for (i = 0; i < column; i++) {
        for (j = 0; j < row; j++) {
            printf("\ninput column[%d][%d]]:", i, j);
            scanf("%d", &two_dimensional_array[i][j]);
        }
    }

    printf("\n[%3d]result=%d", __LINE__, minPathSum(two_dimensional_array, column, &row));

    system("pause");
    return 0;
}