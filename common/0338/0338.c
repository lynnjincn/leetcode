#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int num, int *returnSize)
{
    int *dp;
    int i, target;

    dp = (int *)malloc(sizeof(int) * (num + 1));
    *returnSize = num + 1;
    memset(dp, 0, sizeof(int) * (num + 1));

    dp[0] = 0;
    target = 1;
    for (i = 1; i <= num; i++) {
        if (i == target * 2) {
            PRINTF("\n[%3d]target=%d", __LINE__, i);
            target = i;
            dp[i] = 1;
        } else {
            PRINTF("\n[%3d]diff=%d, dp[diff]=%d", __LINE__, i - target, dp[i - target]);
            dp[i] = 1 + dp[i - target];
            PRINTF("\n[%3d]dp=%d", __LINE__, dp[i]);
        }
    }

    return dp;
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