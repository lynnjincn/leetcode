#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProfit(int *prices, int pricesSize)
{
    int **dp;
    int d;

    if ((prices == NULL) || (pricesSize <= 1)) {
        return 0;
    } else if (pricesSize == 2) {
        return MAX(0, prices[1] - prices[0]);
    }

    dp = (int **)malloc(sizeof(int *) * pricesSize);
    if (dp == NULL) {
        return 0;
    } else {
        for (d = 0; d < pricesSize; d++) {
            dp[d] = (int *)malloc(sizeof(int) * 2);
            if (dp[d] == NULL) {
                return 0;
            }

            memset(dp[d], 0, sizeof(int) * 2);
        }
    }

    dp[0][0] = 0;
    dp[0][1] = 0 - prices[0];

    dp[1][0] = MAX(0, prices[1] - prices[0]);
    dp[1][1] = MAX(dp[0][1], -prices[1]);

    for (d = 2; d < pricesSize; d++) {
        dp[d][0] = MAX(dp[d - 1][0], dp[d - 1][1] + prices[d]);
        dp[d][1] = MAX(dp[d - 1][1], dp[d - 2][0] - prices[d]);
    }

    return dp[pricesSize - 1][0];
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