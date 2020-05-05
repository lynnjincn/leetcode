#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF  // printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProduct(int *nums, int numsSize)
{
    int *dp_max = NULL;
    int *dp_min = NULL;
    int result, i;

    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    dp_max = (int *)malloc(sizeof(int) * (numsSize + 1));
    dp_min = (int *)malloc(sizeof(int) * (numsSize + 1));

    memset(dp_max, 0, sizeof(int) * (numsSize + 1));
    memset(dp_min, 0, sizeof(int) * (numsSize + 1));

    dp_max[0] = 1;
    dp_min[0] = 1;

    result = nums[0];
    for (i = 1; i < numsSize + 1; i++) {
        if (nums[i - 1] > 0) {
            dp_max[i] = MAX(nums[i - 1], nums[i - 1] * dp_max[i - 1]);
            dp_min[i] = MIN(nums[i - 1], nums[i - 1] * dp_min[i - 1]);
        } else {
            dp_max[i] = MAX(nums[i - 1], nums[i - 1] * dp_min[i - 1]);
            dp_min[i] = MIN(nums[i - 1], nums[i - 1] * dp_max[i - 1]);
        }

        result = MAX(result, dp_max[i]);
    }

    PRINTF("\n[%3d]input %5d", __LINE__, 0);
    for (i = 0; i < numsSize; i++) {
        PRINTF("%5d", nums[i]);
    }

    PRINTF("\n[%3d]max   ", __LINE__);
    for (i = 0; i < numsSize + 1; i++) {
        PRINTF("%5d", dp_max[i]);
    }

    PRINTF("\n[%3d]min   ", __LINE__);
    for (i = 0; i < numsSize + 1; i++) {
        PRINTF("%5d", dp_min[i]);
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

    system("pause");
    return 0;
}