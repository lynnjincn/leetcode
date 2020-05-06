#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
{
    int **dp;
    int i, j, result;

    if (triangleSize == 0) {
        return 0;
    } else if (triangleSize == 1) {
        return triangle[0][0];
    }

    dp = (int **)malloc(sizeof(int *) * triangleSize);
    for (i = 0; i < triangleSize; i++) {
        dp[i] = (int *)malloc(sizeof(int) * triangleColSize[i]);
        memset(dp[i], 0, sizeof(int) * triangleColSize[i]);
    }

    dp[0][0] = triangle[0][0];

    for (i = 1; i < triangleSize; i++) {
        for (j = 0; j < triangleColSize[i]; j++) {
            if (j == 0) {
                dp[i][j] = triangle[i][j] + dp[i - 1][0];
                continue;
            }

            if (j == i) {
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = triangle[i][j] + MIN(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    result = 0x7fffffff;

    for (i = 0; i < triangleColSize[triangleSize - 1]; i++) {
        result = MIN(result, dp[triangleSize - 1][i]);
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