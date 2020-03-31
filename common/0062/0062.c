#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTF printf

int uniquePaths(int m, int n) {
    int **dp;
    int i, j;

    PRINTF("[%3d]m=%d, n=%d", __LINE__, m, n);

    if ((m == 0) || (n == 0)) {
        return 0;
    }

    dp = (int **)malloc(sizeof(int *) * n);
    if (dp == NULL) {
        return 0;
    } else {
        for (i = 0; i < n; i++) {
            dp[i] = (int *)malloc(sizeof(int) * m);
            if (dp[i] == NULL) {
                return 0;
            } else {
                memset(dp[i], 0, sizeof(int) * m);
            }
        }
    }

    for (j = 1; j < m; j++) {
        dp[0][j] = 1;
    }

    for (i = 1; i < n; i++) {
        dp[i][0] = 1;
    }

    dp[0][0] = 1;

    PRINTF("\n[%3d]init dp:");
    for (i = 0; i < n; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < m; j++) {
            PRINTF(" %2d ", dp[i][j]);
        }
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];  // dp递归公式
        }
    }

    PRINTF("\n[%3d]calculated dp:");
    for (i = 0; i < n; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < m; j++) {
            PRINTF(" %2d ", dp[i][j]);
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    int m, n;

    printf("input value of m:");
    scanf("%d", &m);
    printf("input value of n:");
    scanf("%d", &n);

    printf("\n[%3d]Result=%d", __LINE__, uniquePaths(m, n));
    system("pause");
    return 0;
}