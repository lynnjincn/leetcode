#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTF printf

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    PRINTF("\n[%3d]obstacleGridSize=%d, obstacleGridColSize=%d", __LINE__, obstacleGridSize, obstacleGridColSize[0]);
    int n = obstacleGridSize;
    int m = obstacleGridColSize[0];
    long** dp;
    int i, j;

    if ((m == 0) || (n == 0) || (obstacleGrid[n - 1][m - 1] == 1)) {
        return 0;
    }

    dp = (long**)malloc(sizeof(long*) * n);
    if (dp == NULL) {
        return 0;
    } else {
        for (i = 0; i < n; i++) {
            dp[i] = (long*)malloc(sizeof(long) * m);
            if (dp[i] == NULL) {
                return 0;
            } else {
                memset(dp[i], 0, sizeof(long) * m);
            }
        }
    }

    dp[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
    for (j = 1; j < m; j++) {
        if (obstacleGrid[0][j] != 1) {
            dp[0][j] = dp[0][j - 1];
        } else {
            dp[0][j] = 0;
        }
    }

    for (i = 1; i < n; i++) {
        if (obstacleGrid[i][0] != 1) {
            dp[i][0] = dp[i - 1][0];
        } else {
            dp[i][0] = 0;
        }
    }

    PRINTF("\n[%3d]init dp:");
    for (i = 0; i < n; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < m; j++) {
            PRINTF(" %2d ", dp[i][j]);
        }
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) {
            if ((obstacleGrid[i - 1][j] == 1) && (obstacleGrid[i][j - 1] == 1)) {
                dp[i][j] = 0;
            } else if (obstacleGrid[i - 1][j] == 1) {
                dp[i][j] = dp[i][j - 1];
            } else if (obstacleGrid[i][j - 1] == 1) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }

    PRINTF("\n[%3d]calculated dp:", __LINE__);
    for (i = 0; i < n; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < m; j++) {
            PRINTF(" %02d ", dp[i][j]);
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    system("pause");
    return 0;
}