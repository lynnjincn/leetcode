#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int maximalSquare(char **matrix, int matrixSize, int *matrixColSize)
{
    int **dp;
    int i, j;
    int temp_len = 0;

    if ((matrix == NULL) || (matrixSize == 0) || (matrixSize == NULL) || (matrixColSize[0] == 0)) {
        return 0;
    }

    dp = (int **)malloc(sizeof(int *) * (matrixSize + 1));
    for (i = 0; i <= matrixSize; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (matrixColSize[0] + 1));
        memset(dp[i], 0, sizeof(int) * (matrixColSize[0] + 1));
    }

    for (i = 1; i <= matrixSize; i++) {
        for (j = 1; j <= matrixColSize[0]; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = MIN(MIN(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                temp_len = MAX(temp_len, dp[i][j]);
            }
        }
    }

    return temp_len * temp_len;
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