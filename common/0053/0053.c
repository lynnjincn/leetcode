#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define SOLUTION_1 1  //暴力法

#if SOLUTION_1

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINTF printf
int maxSubArray(int *nums, int numsSize)
{
    int **dp;
    int i, j;
    int max = -2147483647;
    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }

    PRINTF("\n[%3d]numsSize=%d", __LINE__, numsSize);

    dp = (int **)malloc(sizeof(int **) * numsSize);
    if (dp != NULL) {
        for (i = 0; i < numsSize; i++) {
            dp[i] = (int *)malloc(sizeof(int) * numsSize);
            if (dp[i] != NULL) {
                memset(dp[i], 0, sizeof(int) * numsSize);
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }

    for (i = 0; i < numsSize; i++) {
        for (j = i; j < numsSize; j++) {
            if (i == j) {
                dp[i][j] = nums[i];
            } else {
                dp[i][j] = dp[i][j - 1] + nums[j];
            }

            max = MAX(max, dp[i][j]);
        }
    }

    for (i = 0; i < numsSize; i++) {
        free(dp[i]);
    }

    free(dp);

    return max;
}
#endif

#define SOLUTION_2 1  // Kadane

#if SOLUTION_2
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int maxSubArray(int *nums, int numsSize)
{
    int n = numsSize;
    int currSum = nums[0], maxSum = nums[0];

    for (int i = 1; i < n; ++i) {
        currSum = MAX(nums[i], currSum + nums[i]);
        maxSum = MAX(maxSum, currSum);
    }
    return maxSum;
}
#endif

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