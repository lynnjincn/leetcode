#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (0)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxCoins(int *nums, int numsSize)
{
    int *array;
    int **dp;
    int i, j, temp;

    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    } else {
        array = (int *)malloc(sizeof(int) * (numsSize + 2));
        for (i = 0; i < numsSize; i++) {
            array[i + 1] = nums[i];
        }

        array[numsSize + 1] = 1;
        array[0] = 1;
    }

    PRINTF("\n[%3d]inited array:\n", __LINE__);
    for (i = 0; i < numsSize + 2; i++) {
        PRINTF("%3d ", array[i]);
    }

    dp = (int **)malloc(sizeof(int *) * (numsSize + 2));
    for (i = 0; i < numsSize + 2; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (numsSize + 2));
        memset(dp[i], 0, sizeof(int) * (numsSize + 2));
    }

    PRINTF("\n[%3d]inited dp:", __LINE__);
    for (i = 0; i < numsSize + 2; i++) {
        PRINTF("\n");
        for (j = 0; j < numsSize + 2; j++) {
            PRINTF("%3d ", dp[i][j]);
        }
    }

    for (i = numsSize - 1; i >= 0; i--) {
        PRINTF("\n[%3d][debug]i=%d", __LINE__, i);
        for (j = i + 2; j < numsSize + 2; j++) {
            PRINTF("\n\t[%3d][debug]j=%d", __LINE__, j);
            for (temp = i + 1; temp < j; temp++) {
                PRINTF("\n\t\t[%3d][debug]temp=%d, dp[i][j]=%d, dp[i][temp]=%d, dp[temp][j]=%d", __LINE__, temp, dp[i][j],
                       dp[i][temp], dp[temp][j]);
                PRINTF("\n\t\t[%3d]array[temp]=%d, array[temp + 1]=%d, array[temp - 1]=%d", __LINE__, array[temp], array[temp + 1],
                       array[temp - 1]);
                dp[i][j] = MAX(dp[i][j], dp[i][temp] + dp[temp][j] + array[temp] * array[i] * array[j]);
                PRINTF("\n\t\t[%3d]dp[i][j]=%d", __LINE__, dp[i][j]);
            }
        }
    }

    PRINTF("\n[%3d]calculated dp:", __LINE__);
    for (i = 0; i < numsSize + 2; i++) {
        PRINTF("\n");
        for (j = 0; j < numsSize + 2; j++) {
            PRINTF("%3d ", dp[i][j]);
        }
    }
    return dp[0][numsSize + 1];
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
    int array[] = {1, 5, 8};

    printf("\n[%3d]result=%d", __LINE__, maxCoins(array, sizeof(array) / sizeof(int)));

    system("pause");
    return 0;
}