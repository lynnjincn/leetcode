#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProfit_k_inf(int *prices, int pricesSize)
{
    int dp_i_0 = 0, dp_i_1 = -2147483648;
    for (int i = 0; i < pricesSize; i++) {
        int temp = dp_i_0;
        dp_i_0 = MAX(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = MAX(dp_i_1, temp - prices[i]);
    }
    return dp_i_0;
}

int maxProfit(int k, int *prices, int pricesSize)
{
    int ***dp;
    int d, s, c;

    if ((k == 0) || (prices == NULL) || (pricesSize == 0)) {
        return 0;
    }

    if (k > pricesSize / 2) {
        return maxProfit_k_inf(prices, pricesSize);
    }

    dp = (int ***)malloc(sizeof(int **) * pricesSize);
    for (d = 0; d < pricesSize; d++) {
        dp[d] = (int **)malloc(sizeof(int *) * (k + 1));
        for (c = 0; c < k + 1; c++) {
            dp[d][c] = (int *)malloc(sizeof(int) * 2);
            memset(dp[d][c], 0, sizeof(int) * 2);
        }
    }

    for (d = 0; d < pricesSize; d++) {
        for (c = k; c > 0; c--) {
            if (d == 0) {
                dp[d][c][0] = 0;
                dp[d][c][1] = 0 - prices[d];
            } else {
                dp[d][c][0] = MAX(dp[d - 1][c][0], dp[d - 1][c][1] + prices[d]);
                dp[d][c][1] = MAX(dp[d - 1][c][1], dp[d - 1][c - 1][0] - prices[d]);
            }
        }
    }

    return dp[d - 1][k][0];
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