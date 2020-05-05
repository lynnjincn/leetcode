#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int rob(int *nums, int numsSize)
{
    int **dp_first_steal;
    int **dp_first_not_steal;
    int result_first_steal = 0;
    int result_first_not_steal = 0;
    int i;

    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    } else if (numsSize == 2) {
        return MAX(nums[0], nums[1]);
    }

    // dp的第一个维度是当前天是否偷取，第二个维度是第几天
    dp_first_steal = (int **)malloc(2 * sizeof(int *));
    dp_first_steal[0] = (int *)malloc(numsSize * sizeof(int));
    dp_first_steal[1] = (int *)malloc(numsSize * sizeof(int));

    dp_first_not_steal = (int **)malloc(2 * sizeof(int *));
    dp_first_not_steal[0] = (int *)malloc(numsSize * sizeof(int));
    dp_first_not_steal[1] = (int *)malloc(numsSize * sizeof(int));

    dp_first_steal[0][0] = 0;
    dp_first_steal[1][0] = nums[0];

    for (i = 1; i < numsSize; i++) {
        dp_first_steal[0][i] = MAX(dp_first_steal[1][i - 1], dp_first_steal[0][i - 1]);
        dp_first_steal[1][i] = nums[i] + dp_first_steal[0][i - 1];
    }

    result_first_steal = dp_first_steal[numsSize - 1][0];  //第一次偷了但是最后一次没偷的情况

    // 第一天未偷取，从第二天开始计算结果
    dp_first_not_steal[0][0] = 0;
    dp_first_not_steal[1][0] = 0;
    dp_first_not_steal[0][1] = 0;
    dp_first_not_steal[1][1] = nums[1];

    for (i = 2; i < numsSize; i++) {
        dp_first_not_steal[0][i] = MAX(dp_first_not_steal[1][i - 1], dp_first_not_steal[0][i - 1]);
        dp_first_not_steal[1][i] = nums[i] + dp_first_not_steal[0][i - 1];
    }

    result_first_not_steal = MAX(dp_first_not_steal[0][numsSize - 1], dp_first_not_steal[1][numsSize - 1]);

    return MAX(result_first_not_steal, result_first_steal);
}

int main()
{
    system("pause");
    return 0;
}