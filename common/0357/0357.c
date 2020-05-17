#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int my_cal_func(int n)
{
    int i;
    int result = 1;
    for (i = 0; i < n; i++) {
        result = result * (9 - i);
    }

    PRINTF("\n[%3d]input=%d, result=%d", __LINE__, n, result);
    return result;
}

int countNumbersWithUniqueDigits(int n)
{
    int i;
    int dp[11] = {0};

    dp[0] = 0;
    dp[1] = 10;

    for (i = 2; i < 11; i++) {
        dp[i] = 9 * my_cal_func(i - 1) + dp[i - 1];
        PRINTF("\n[%3d]i=%d, dp[i]=%d", __LINE__, i, dp[i]);
    }

    return dp[MIN(n, 10)];
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