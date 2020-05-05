#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (0)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int **g_dp = NULL;

typedef struct {
    int *nums;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
    NumArray *my_array;
    int i, j;

    if (numsSize == 0) {
        return NULL;
    }

    my_array = (NumArray *)malloc(sizeof(NumArray));
    my_array->nums = (int *)malloc(numsSize * sizeof(int));

    if (g_dp != NULL) {
        free(g_dp);
    }

    g_dp = (int **)malloc(sizeof(int *) * numsSize);

    for (i = 0; i < numsSize; i++) {
        my_array->nums[i] = nums[i];
        g_dp[i] = (int *)malloc(sizeof(int *) * numsSize);
        memset(g_dp[i], 0, sizeof(int *) * numsSize);
    }

    for (i = numsSize - 1; i >= 0; i--) {
        for (j = i; j < numsSize; j++) {
            if (i == j) {
                g_dp[i][j] = nums[i];
            } else {
                g_dp[i][j] = g_dp[i + 1][j] + nums[i];
            }
        }
    }

    return my_array;
}

int numArraySumRange(NumArray *obj, int i, int j) {}

void numArrayFree(NumArray *obj) {}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);

 * numArrayFree(obj);
*/

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