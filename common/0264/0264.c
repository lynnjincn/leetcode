#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int nthUglyNumber(int n)
{
    int p2, p3, p5, i;
    int *dp;

    dp = (int *)malloc(sizeof(int) * (n + 1));
    p2 = 0;
    p3 = 0;
    p5 = 0;
    dp[0] = 1;

    for (i = 1; i < n; i++) {
        dp[i] = MIN((dp[p2]) * 2, MIN(dp[p3] * 3, dp[p5] * 5));

        PRINTF("\n[%3d]dp[%d]=%d", __LINE__, i, dp[i]);

        if (dp[p2] * 2 == dp[i]) {
            p2++;
        }

        if (dp[p3] * 3 == dp[i]) {
            p3++;
        }

        if (dp[p5] * 5 == dp[i]) {
            p5++;
        }

        PRINTF("\n[%3d]dp[%d]=%d", __LINE__, i, dp[i]);
        PRINTF("\n[%3d]p2=%d, p3=%d, p5=%d", __LINE__, p2, p3, p5);
    }

    return dp[n - 1];
}

int main()
{
    int input = 0;
    scanf("%d", &input);
    printf("\n[%3d]result=%d", __LINE__, nthUglyNumber(input));

    system("pause");
    return 0;
}