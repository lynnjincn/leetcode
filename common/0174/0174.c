#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int get_right_temp(int **dungeon, int **dp, int i, int j)
{
    int right_temp;
    if (dungeon[i][j] >= 0) {
        // 当前值能否满足前一个格子的入口需求
        if (dungeon[i][j] >= dp[i][j + 1]) {
            PRINTF("\n[%3d]right_temp=%d", __LINE__, right_temp);
            right_temp = 1;
        } else {
            right_temp = dp[i][j + 1] - dungeon[i][j];
            PRINTF("\n[%3d]right_temp=%d", __LINE__, right_temp);
        }
    } else {
        right_temp = dp[i][j + 1] - dungeon[i][j];
        PRINTF("\n[%3d]right_temp=%d", __LINE__, right_temp);
    }

    return right_temp;
}

int get_down_temp(int **dungeon, int **dp, int i, int j)
{
    int down_temp;
    if (dungeon[i][j] >= 0) {
        if (dungeon[i][j] >= dp[i + 1][j]) {
            PRINTF("\n[%3d]dungeon=%d, prev_need=%d", __LINE__, dungeon[i][j], dp[i + 1][j]);
            down_temp = 1;
        } else {
            down_temp = dp[i + 1][j] - dungeon[i][j];
            PRINTF("\n[%3d]dungeon=%d, prev_need=%d", __LINE__, dungeon[i][j], dp[i + 1][j]);
        }
    } else {
        down_temp = dp[i + 1][j] - dungeon[i][j];
        PRINTF("\n[%3d]dungeon=%d, prev_need=%d", __LINE__, dungeon[i][j], dp[i + 1][j]);
    }

    return down_temp;
}

int calculateMinimumHP(int **dungeon, int dungeonSize, int *dungeonColSize)
{
    int **dp = NULL;
    int column = dungeonColSize[0];  // 列
    int row = dungeonSize;           // 行
    int i, j, current_need, right_temp, down_temp;

    if ((column == 1) && (row == 1)) {
        return (dungeon[row - 1][column - 1] > 0) ? 1 : (1 - dungeon[row - 1][column - 1]);
    }

    dp = (int **)malloc(sizeof(int *) * row);
    for (i = 0; i < row; i++) {
        dp[i] = (int *)malloc(sizeof(int) * column);
        memset(dp[i], 0, sizeof(int) * column);
    }

    dp[row - 1][column - 1] = (dungeon[row - 1][column - 1] > 0) ? 1 : (1 - dungeon[row - 1][column - 1]);
    for (j = column - 2; j >= 0; j--) {
        dp[row - 1][j] = get_right_temp(dungeon, dp, row - 1, j);
    }

    for (i = row - 2; i >= 0; i--) {
        dp[i][column - 1] = get_down_temp(dungeon, dp, i, column - 1);
    }

    PRINTF("\n[%3d]after init:", __LINE__);
    for (i = 0; i < row; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < column; j++) {
            PRINTF("%3d", dp[i][j]);
        }
    }

    PRINTF("\n\n[%3d]dp start:", __LINE__);
    for (i = row - 2; i >= 0; i--) {
        for (j = column - 2; j >= 0; j--) {
            right_temp = get_right_temp(dungeon, dp, i, j);
            down_temp = get_down_temp(dungeon, dp, i, j);
            dp[i][j] = MIN(right_temp, down_temp);
        }
    }

    PRINTF("\n[%3d]after calculated:", __LINE__);
    for (i = 0; i < row; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < column; j++) {
            PRINTF("%3d", dp[i][j]);
        }
    }
    return dp[0][0];
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