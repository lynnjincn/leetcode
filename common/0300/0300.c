#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (0)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int lengthOfLIS(int *nums, int numsSize)
{
    int *dp;
    int result, i, j;

    if (numsSize <= 1) {
        return numsSize;
    }

    dp = (int *)malloc(sizeof(int) * numsSize);
    memset(dp, 0, sizeof(int) * numsSize);

    dp[0] = 1;
    result = 1;

    for (i = 1; i < numsSize; i++) {
        dp[i] = 1;

        for (j = 0; j <= i - 1; j++) {
            PRINTF("\n[%3d]i=%d, j=%d", __LINE__, i, j);
            if (nums[i] > nums[j]) {
                dp[i] = MAX(dp[i], dp[j] + 1);
            }
        }

        result = MAX(result, dp[i]);
        PRINTF("\n[%3d]update result=%d", __LINE__, result);
    }

    return result;
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

    int *input;
    int input_size = 0;
    int i;

    printf("input size:");
    scanf("%d", &input_size);
    input = (int *)malloc(sizeof(int) * input_size);

    printf("input num:");
    for (i = 0; i < input_size; i++) {
        scanf("%d", &input[i]);
    }

    printf("\n[%3d]result=%d", __LINE__, lengthOfLIS(input, input_size));

    system("pause");
    return 0;
}