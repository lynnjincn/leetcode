#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (0)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int my_cmp_func(void *v_1, void *v_2) { return (*(int *)v_1 - *(int *)v_2); }

int *largestDivisibleSubset(int *nums, int numsSize, int *returnSize)
{
    int *dp_len;
    int *dp_index;
    int *result;
    int i, j;
    int temp_max_len;
    int temp_len;
    int temp_len_index;

    if ((nums == NULL) || (numsSize <= 1)) {
        *returnSize = numsSize;
        return nums;
    }

    PRINTF("\n[%3d]source input_array:\n", __LINE__);
    for (i = 0; i < numsSize; i++) {
        PRINTF("%3d ", nums[i]);
    }

    qsort(nums, numsSize, sizeof(int), my_cmp_func);
    PRINTF("\n[%3d]sorted input_array:\n", __LINE__);
    for (i = 0; i < numsSize; i++) {
        PRINTF("%3d ", nums[i]);
    }

    dp_len = (int *)malloc(sizeof(int) * numsSize);
    dp_index = (int *)malloc(sizeof(int) * numsSize);
    if ((dp_len == NULL) || (dp_index == NULL)) {
        return 0;
    }

    for (i = 0; i < numsSize; i++) {
        dp_len[i] = 1;
    }

    for (i = 0; i < numsSize; i++) {
        dp_index[i] = -1;
    }

    dp_len[0] = 1;
    dp_index[0] = -1;

    temp_max_len = 0;
    for (i = 1; i < numsSize; i++) {
        for (j = 0; j < i; j++) {
            PRINTF("\n[%3d]i=%d, j=%d", __LINE__, i, j);
            if (nums[i] % nums[j] == 0) {
                PRINTF("\n[%3d]dp_len[j]=%d", __LINE__, dp_len[j]);
                if (dp_len[j] + 1 >= dp_len[i]) {
                    dp_len[i] = dp_len[j] + 1;
                    dp_index[i] = j;
                    PRINTF("\n[%3d]dp_len[i]=%d, dp_index[i]=%d", __LINE__, dp_len[i], dp_index[i]);
                }
            }
        }

        if (dp_len[i] > temp_max_len) {
            temp_max_len = dp_len[i];
            temp_len_index = i;
            PRINTF("\n[%3d]max_len=%d, max_len_index=%d", __LINE__, temp_max_len, temp_len_index);
        }
    }

    result = (int *)malloc(sizeof(int) * temp_max_len);
    if (result == NULL) {
        return 0;
    }

    PRINTF("\n[%3d]dp_len:\n", __LINE__);
    for (i = 0; i < numsSize; i++) {
        PRINTF("%3d ", dp_len[i]);
    }
    PRINTF("\n[%3d]dp_index:\n", __LINE__);
    for (i = 0; i < numsSize; i++) {
        PRINTF("%3d ", dp_index[i]);
    }

    PRINTF("\n[%3d]max_len=%d, max_len_index=%d", __LINE__, temp_max_len, temp_len_index);

    if (temp_max_len == 0) {
        *returnSize = 1;
        return &nums[0];
    }

    i = temp_len_index;
    j = 0;
    while (i != -1) {
        PRINTF("\n[%3d]i=%d, value=%d", __LINE__, i, nums[i]);
        result[j] = nums[i];
        i = dp_index[i];
        PRINTF("\n[%3d]result[%d]=%d, next_index=%d", __LINE__, j, result[j], temp_len_index);
        j++;
        PRINTF("\n[%3d]i=%d", __LINE__, i);
    }

    *returnSize = temp_max_len;
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
    int input[] = {546, 669};
    int return_size = 0;

    largestDivisibleSubset(input, sizeof(input) / sizeof(int), &return_size);

    system("pause");
    return 0;
}