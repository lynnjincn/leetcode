#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例
#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX_DEAL_NUM 2
#define STATE_KEEP 1
#define STATE_NOT_KEEP 0

int maxProfit(int *prices, int pricesSize)
{
    int ***dp;
    int d, k, s;

    dp = (int ***)malloc(sizeof(int **) * pricesSize);
    for (d = 0; d < pricesSize; d++) {
        dp[d] = (int **)malloc(sizeof(int *) * (MAX_DEAL_NUM + 1));

        for (s = 0; s < MAX_DEAL_NUM + 1; s++) {
            dp[d][s] = (int *)malloc(sizeof(int) * (STATE_KEEP + 1));
        }
    }

    dp[0][2][STATE_NOT_KEEP] = 0;
    dp[0][1][STATE_NOT_KEEP] = 0;
    dp[0][2][STATE_KEEP] = 0 - prices[0];
    dp[0][1][STATE_KEEP] = 0 - prices[0];

    for (d = 0; d < pricesSize; d++) {
        for (k = MAX_DEAL_NUM; k >= 1; k--) {
            if (d - 1 != -1) {
                dp[d][k][STATE_NOT_KEEP] = MAX(dp[d - 1][k][STATE_NOT_KEEP], dp[d - 1][k][STATE_KEEP] + prices[d]);
                PRINTF("\n[%3d]day:%d, deal:%d, not_keep=%d", __LINE__, d, k, dp[d][k][STATE_NOT_KEEP]);
                dp[d][k][STATE_KEEP] = MAX(dp[d - 1][k][STATE_KEEP], dp[d - 1][k - 1][STATE_NOT_KEEP] - prices[d]);
                PRINTF("\n[%3d]day:%d, deal:%d, keep=%d", __LINE__, d, k, dp[d][k][STATE_KEEP]);
            }
        }
    }

    return dp[pricesSize - 1][MAX_DEAL_NUM][STATE_NOT_KEEP];
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