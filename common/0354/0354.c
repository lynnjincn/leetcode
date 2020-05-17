#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int my_cmp_func(const void *v_1, const void *v_2)
{
    int *item_1 = *(int **)v_1;
    int *item_2 = *(int **)v_2;

    if ((item_1[0] == item_2[0]) && (item_1[1] == item_2[1])) {
        return 0;
    } else if ((item_1[0] > item_2[0]) || ((item_1[0] == item_2[0]) && (item_1[1] > item_2[1]))) {
        return 1;
    } else {
        return -1;
    }
}

int maxEnvelopes(int **envelopes, int envelopesSize, int *envelopesColSize)
{
    int *dp;
    int i, j;
    int result = 1;

    if ((envelopes == NULL) || (envelopesSize == 0)) {
        return 0;
    } else if (envelopesSize == 1) {
        return 1;
    }

    dp = (int *)malloc(sizeof(int) * envelopesSize);
    if (dp == NULL) {
        return 0;
    }

    for (i = 0; i < envelopesSize; i++) {
        dp[i] = 1;
    }

    PRINTF("\n[%3d]b4 sort:", __LINE__);
    for (i = 0; i < envelopesSize; i++) {
        PRINTF("\n[%3d]envelopes[%d]={%d, %d}", __LINE__, i, envelopes[i][0], envelopes[i][1]);
    }

    qsort(envelopes, envelopesSize, sizeof(int **), my_cmp_func);

    PRINTF("\n[%3d]after sort:", __LINE__);
    for (i = 0; i < envelopesSize; i++) {
        PRINTF("\n[%3d]envelopes[%d]={%d, %d}", __LINE__, i, envelopes[i][0], envelopes[i][1]);
    }

    for (i = 0; i < envelopesSize; i++) {
        for (j = 0; j < i; j++) {
            PRINTF("\n[%3d]i=%d, j=%d", __LINE__, i, j);
            PRINTF("\n[%3d]prev={%d, %d}, cur={%d, %d}", __LINE__, envelopes[i][0], envelopes[i][1], envelopes[j][0],
                   envelopes[i][1]);

            if ((envelopes[i][0] > envelopes[j][0]) && (envelopes[i][1] > envelopes[j][1])) {
                dp[i] = MAX(dp[i], dp[j] + 1);
            }
        }

        PRINTF("\n[%3d]dp[%d]=%d", __LINE__, i, dp[i]);
        result = MAX(result, dp[i]);
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