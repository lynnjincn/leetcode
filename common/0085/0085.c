#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize)
{
    int column, row, i, j, high, temp_aera, min_width;
    int result = 0;
    int **dp;

    if ((matrix == NULL) || (matrixColSize == NULL) || (matrixSize == 0)) {
        return 0;
    } else {
        PRINTF("\n[%3d]matrixSize=%d, matrixColSize[0]=%d", __LINE__, matrixSize, matrixColSize[0]);
        column = matrixSize;
        row = matrixColSize[0];
    }

    PRINTF("\n[%3d]input array:", __LINE__);
    for (i = 0; i < column; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < row; j++) {
            PRINTF(" %3c ", matrix[i][j]);
        }
    }

    dp = (int **)malloc(sizeof(int *) * column);
    if (dp == NULL) {
        return 0;
    } else {
        for (i = 0; i < column; i++) {
            dp[i] = (int *)malloc(sizeof(int) * row);
            if (dp[i] == NULL) {
                return 0;
            } else {
                memset(dp[i], 0, sizeof(int) * row);
            }
        }
    }

    for (i = 0; i < column; i++) {
        dp[i][0] = (matrix[i][0] == '1');
    }

    PRINTF("\n[%3d]init dp:", __LINE__);
    for (i = 0; i < column; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < row; j++) {
            PRINTF(" %3d ", dp[i][j]);
        }
    }

    for (i = 0; i < column; i++) {
        for (j = 1; j < row; j++) {
            if (matrix[i][j] == '0') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j - 1] + 1;
            }
        }
    }

    PRINTF("\n[%3d]calculated dp:", __LINE__);
    for (i = 0; i < column; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < row; j++) {
            PRINTF(" %3d ", dp[i][j]);
        }
    }

    for (i = 0; i < column; i++) {
        for (j = 0; j < row; j++) {
            PRINTF("\n[%3d]i=%d, j=%d:", __LINE__, i, j);
            min_width = 0x7fffffff;
            for (high = 1; high <= i + 1; high++) {
                PRINTF("\n[%3d]high=%d, dp[i-high+1][j]=%d:", __LINE__, high, dp[i - high + 1][j]);
                min_width = MIN(min_width, dp[i - high + 1][j]);
                PRINTF("\n[%3d]min_width=%d:", __LINE__, min_width);
                temp_aera = min_width * high;
                PRINTF("\n[%3d]temp_area=%d:", __LINE__, temp_aera);
                result = MAX(result, temp_aera);
                PRINTF("\n[%3d]result=%d:", __LINE__, result);
            }
        }
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

    printf("\n[%3d]result=%d", __LINE__, maximalRectangle(two_dimensional_array, column, &row));

    system("pause");
    return 0;
}