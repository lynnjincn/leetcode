#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf

bool isScramble(char *s1, char *s2)
{
    int len_1 = strlen(s1);
    int len_2 = strlen(s2);
    int len = len_1;
    int i, j, k, s;
    bool ***dp;

    PRINTF("\n[%3d]s1[%d]=%s", __LINE__, len_1, s1);
    PRINTF("\n[%3d]s2[%d]=%s", __LINE__, len_2, s2);

    if ((len_1 == 0) || (len_2 == 0) || (len_1 != len_2)) {
        PRINTF("\n[%3d]mark", __LINE__);
        return false;
    }

    dp = (bool ***)malloc(sizeof(bool **) * len);
    if (dp != NULL) {
        for (i = 0; i < len; i++) {
            dp[i] = (bool **)malloc(sizeof(bool *) * len);
            if (dp[i] != NULL) {
                for (j = 0; j < len; j++) {
                    dp[i][j] = (bool *)malloc(sizeof(bool) * (len + 1));
                    if (dp[i][j] != NULL) {
                        memset(dp[i][j], 0, sizeof(bool) * (len + 1));
                    } else {
                        return false;
                    }
                }
            } else {
                return false;
            }
        }
    } else {
        return false;
    }

    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j][1] = true;
            }
        }
    }

    // 遍历字符长度
    for (k = 2; k <= len; k++) {
        // 遍历s1起始点
        for (i = 0; i <= len - k; i++) {
            // 遍历s2起始点
            for (j = 0; j <= len - k; j++) {
                // 遍历分割点
                for (s = 1; s <= k - 1; s++) {
                    // s1[i~s]与s2[j~s]可以相互转换，s1[(i+s)~k]与s2[(j+s)~k]可以相互转换，也就是S1==>T1,S2==>T2
                    if ((dp[i][j][s] == true) && (dp[i + s][j + s][k - s] == true)) {
                        dp[i][j][k] = true;
                        break;
                    }

                    // s1[i~s]与s2[j+(k-s)~s]可以相互转换，s1[i+s~k][j~(k-s)]可以相互转换，也就是S1==>T2，S2==>T1
                    if ((dp[i][j + k - s][s] == true) && (dp[i + s][j][k - s])) {
                        dp[i][j][k] = true;
                        break;
                    }
                }
            }
        }
    }

    return dp[0][0][len];
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