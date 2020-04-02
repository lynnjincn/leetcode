#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf

int climbStairs(int n)
{
    int *dp;
    int i;

    PRINTF("\n[%3d]n=%d", __LINE__, n);

    if (n <= 2) {
        return n;
    }

    dp = (int *)malloc(sizeof(int) * (n + 1));
    if (dp == NULL) {
        PRINTF("\n[%3d]n=%d", __LINE__, n);
        return 0;
    } else {
        memset(dp, 0, sizeof(int) * (n + 1));
    }

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (i = 3; i < n + 1; i++) {
        PRINTF("\n[%3d]dp[i-1]=%d, dp[i-2]=%d", __LINE__, dp[i - 1], dp[i - 2]);
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (i = 0; i < n + 1; i++) {
        PRINTF("\n[%3d]dp[%d]=%d", __LINE__, i, dp[i]);
    }

    return dp[n];
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