#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF  // printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int rob(int *nums, int numsSize)
{
    int **dp;
    int i;

    if ((numsSize == 0) || (nums == NULL)) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }

    dp = (int **)malloc(2 * sizeof(int *));
    dp[0] = (int *)malloc(numsSize * sizeof(int));
    dp[1] = (int *)malloc(numsSize * sizeof(int));

    dp[0][0] = 0;
    dp[1][0] = nums[0];

    for (i = 1; i < numsSize; i++) {
        dp[0][i] = MAX(dp[1][i - 1], dp[0][i - 1]);
        dp[1][i] = nums[i] + dp[0][i - 1];
    }

    for (i = 0; i < numsSize; i++) {
        PRINTF("%3d", dp[0][i]);
    }

    PRINTF("\n");

    for (i = 0; i < numsSize; i++) {
        PRINTF("%3d", dp[1][i]);
    }

    return MAX(dp[0][numsSize - 1], dp[1][numsSize - 1]);
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