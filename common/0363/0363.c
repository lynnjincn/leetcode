#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int maxSumSubmatrix(int **matrix, int matrixSize, int *matrixColSize, int k)
{
    int **dp;
    int i, j;
    int temp_min = 0;
    int i_1, i_2, j_1, j_2, temp_sum, temp_sum_a, temp_sum_b, temp_sum_c;
    int result = INT_MIN;

    dp = (int **)malloc(sizeof(int *) * matrixSize);
    if (dp == NULL) {
        return 0;
    } else {
        for (i = 0; i < matrixSize; i++) {
            dp[i] = (int *)malloc(sizeof(int) * matrixColSize[0]);
            if (dp[i] == NULL) {
                return 0;
            } else {
                memset(dp[i], 0, sizeof(int) * matrixColSize[0]);
            }
        }
    }

    dp[0][0] = matrix[0][0];
    for (j = 1; j < matrixColSize[0]; j++) {
        dp[0][j] = matrix[0][j] + dp[0][j - 1];
        if (dp[0][j] == k) {
            return k;
        }
    }

    for (i = 1; i < matrixSize; i++) {
        dp[i][0] = matrix[i][0] + dp[i - 1][0];
        if (dp[i][0] == k) {
            return k;
        }
    }

    for (i = 1; i < matrixSize; i++) {
        temp_sum = matrix[i][0];
        for (j = 1; j < matrixColSize[0]; j++) {
            dp[i][j] = matrix[i][j] + dp[i - 1][j] + temp_sum;
            temp_sum += matrix[i][j];
            if (dp[i][j] == k) {
                return k;
            }
        }
    }

    for (i_1 = 0; i_1 < matrixSize; i_1++) {
        for (j_1 = 0; j_1 < matrixColSize[0]; j_1++) {
            for (i_2 = i_1; i_2 < matrixSize; i_2++) {
                for (j_2 = j_1; j_2 < matrixColSize[0]; j_2++) {
                    if ((i_2 == i_1) && (j_2 == j_1)) {
                        temp_sum = matrix[i_1][j_1];
                    } else {
                        if ((i_1 == 0) && (j_1 == 0)) {
                            temp_sum_a = 0;
                            temp_sum_b = 0;
                            temp_sum_c = 0;
                        } else if (i_1 == 0) {
                            temp_sum_a = 0;
                            temp_sum_b = 0;
                            temp_sum_c = dp[i_2][j_1 - 1];
                        } else if (j_1 == 0) {
                            temp_sum_a = 0;
                            temp_sum_b = dp[i_1 - 1][j_2];
                            temp_sum_c = 0;
                        } else {
                            temp_sum_a = dp[i_1 - 1][j_1 - 1];
                            temp_sum_b = dp[i_1 - 1][j_2];
                            temp_sum_c = dp[i_2][j_1 - 1];
                        }

                        temp_sum = dp[i_2][j_2] - temp_sum_b - temp_sum_c + temp_sum_a;
                    }

                    temp_min = MIN(temp_min, temp_sum);

                    if (temp_sum == k) {
                        return k;
                    } else if (temp_sum < k) {
                        result = MAX(result, temp_sum);
                    }
                }
            }
        }
    }

    return result;
}

int main()
{
    int **test;
    int i;
    /*int input[][15] = {{27, 5, -20, -9, 1, 26, 1, 12, 7, -4, 8, 7, -1, 5, 8},
                       {16, 28, 8, 3, 16, 28, -10, -7, -5, -13, 7, 9, 20, -9, 26},
                       {24, -14, 20, 23, 25, -16, -15, 8, 8, -6, -14, -6, 12, -19, -13}};*/
    int input[][15] = {{27, 5, -20, -9, 1, 26, 1, 12, 7, -4, 8, 7, -1, 5, 8},
                       {16, 28, 8, 3, 16, 28, -10, -7, -5, -13, 7, 9, 20, -9, 26},
                       {24, -14, 20, 23, 25, -16, -15, 8, 8, -6, -14, -6, 12, -19, -13},
                       {28, 13, -17, 20, -3, -18, 12, 5, 1, 25, 25, -14, 22, 17, 12},
                       {7, 29, -12, 5, -5, 26, -5, 10, -5, 24, -9, -19, 20, 0, 18},
                       {-7, -11, -8, 12, 19, 18, -15, 17, 7, -1, -11, -10, -1, 25, 17},
                       {-3, -20, -20, -7, 14, -12, 22, 1, -9, 11, 14, -16, -5, -12, 14},
                       {-20, -4, -17, 3, 3, -18, 22, -13, -1, 16, -11, 29, 17, -2, 22},
                       {23, -15, 24, 26, 28, -13, 10, 18, -6, 29, 27, -19, -19, -8, 0},
                       {5, 9, 23, 11, -4, -20, 18, 29, -6, -4, -11, 21, -6, 24, 12},
                       {13, 16, 0, -20, 22, 21, 26, -3, 15, 14, 26, 17, 19, 20, -5},
                       {15, 1, 22, -6, 1, -9, 0, 21, 12, 27, 5, 8, 8, 18, -1},
                       {15, 29, 13, 6, -11, 7, -6, 27, 22, 18, 22, -3, -9, 20, 14},
                       {26, -6, 12, -10, 0, 26, 10, 1, 11, -10, -16, -18, 29, 8, -8},
                       {-19, 14, 15, 18, -10, 24, -9, -7, -19, -14, 23, 23, 17, -5, 6}};

    int len[] = {15};

    test = (int **)malloc(15 * sizeof(int *));
    for (i = 0; i < 15; i++) {
        test[i] = (int *)malloc(sizeof(int) * 15);
        memcpy(test[i], input[i], 15 * sizeof(int));
    }

    printf("\n[%3d]result=%d", __LINE__, maxSumSubmatrix(test, 15, len, -100));
    system("pause");
    return 0;
}