#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int numSquares(int n)
{
    int max_sqr = (int)sqrt(n);
    int i, j;
    int *sqr_map;
    int *dp;

    sqr_map = (int *)malloc(sizeof(int) * max_sqr);
    for (i = 1; i <= max_sqr; i++) {
        sqr_map[i - 1] = i * i;
        PRINTF("\n[%3d]sqr_map[%d]=%d", __LINE__, i - 1, sqr_map[i - 1]);
    }

    dp = (int *)malloc(sizeof(int) * (n + 1));
    for (i = 0; i <= n; i++) {
        dp[i] = 0x7fffffff;
    }

    dp[0] = 0;

    for (i = 1; i <= n; i++) {
        for (j = 0; j < max_sqr; j++) {
            if (i < sqr_map[j]) {
                break;
            }

            PRINTF("\n[%3d]dp[i]=%d, dp[i - sqr_map[j]]=%d", __LINE__, dp[i], dp[i - sqr_map[j]] + 1);
            dp[i] = MIN(dp[i], dp[i - sqr_map[j]] + 1);
        }

        PRINTF("\n[%3d]dp[%d]=%d", __LINE__, i, dp[i]);
    }

    return dp[n];
}

int main()
{
    int input = 0;
    printf("input a num:\n");
    scanf("%d", &input);

    printf("\n[%3d]result=%d", __LINE__, numSquares(input));

    system("pause");
    return 0;
}