#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int getMoneyAmount(int n)
{
    int **dp;
    int i, j, k;

    if (n <= 2) {
        return n - 1;
    }

    dp = (int **)malloc(sizeof(int *) * (n + 1));
    if (dp == NULL) {
        return 0;
    } else {
        memset(dp, 0, sizeof(int *) * (n + 1));
        for (i = 0; i < n + 1; i++) {
            dp[i] = (int *)malloc(sizeof(int) * (n + 1));
            if (dp[i] == NULL) {
                return 0;
            } else {
                memset(dp[i], 0, sizeof(int) * (n + 1));
                for (j = 0; j < n + 1; j++) {
                    dp[i][j] = 0x7fffffff;
                }
            }
        }
    }

    for (i = 0; i < n + 1; i++) {
        for (j = 0; j < n + 1; j++) {
            if (i == j) {
                dp[i][j] = 0;
            }
        }
    }

    PRINTF("\n[%3d]inited dp:", __LINE__);
    for (i = 0; i < n + 1; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < n + 1; j++) {
            if (dp[i][j] == 0x7fffffff) {
                PRINTF(" - ");
            } else {
                PRINTF("%3d", dp[i][j]);
            }
        }
    }

    for (int j = 2; j <= n; j++) {
        //按行来，从下往上
        for (int i = j - 1; i >= 1; i--) {
            //算除了两端的每一个分割点
            for (int k = i + 1; k <= j - 1; k++) {
                PRINTF("\n[%3d]i=%d, j=%d, k=%d", __LINE__, i, j, k);
                dp[i][j] = MIN(k + MAX(dp[i][k - 1], dp[k + 1][j]), dp[i][j]);
            }
            //算两端

            PRINTF("\n[%3d]i=%d, j=%d", __LINE__, i, j);
            dp[i][j] = MIN(dp[i][j], i + dp[i + 1][j]);
            dp[i][j] = MIN(dp[i][j], j + dp[i][j - 1]);
        }
    }

    return dp[1][n];
}

int main()
{
#if TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE
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
#endif

    system("pause");
    return 0;
}