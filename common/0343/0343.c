#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int integerBreak(int n)
{
    int *dp;
    int i, j, half;

    if ((n == 1) || (n == 2)) {
        return 1;
    } else if (n == 3) {
        return 2;
    }

    dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (i = 4; i <= n; i++) {
        half = (i + 1) / 2;
        PRINTF("\n[%3d]half=%d", __LINE__, half);
        for (j = half; j < i; j++) {
            PRINTF("\n[%3d]j=%d, i=%d", __LINE__, j, i);
            PRINTF("\n[%3d]dp[j]=%d, dp[i - j]=%d", __LINE__, dp[j], dp[i - j]);
            dp[i] = MAX(dp[i], dp[j] * dp[i - j]);
            dp[i] = MAX(dp[i], j * (i - j));
        }

        PRINTF("\n[%3d]dp[%d]=%d", __LINE__, i, dp[i]);
    }

    return dp[n];
}

int main()
{
    int input = 0;
    scanf("%d", &input);

    printf("\n[%3d]result=%d", __LINE__, integerBreak(input));

    system("pause");
    return 0;
}