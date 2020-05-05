#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void prev_handle(char *s, int **map)
{
    int i, j;
    int len = strlen(s);

    for (i = len - 1; i >= 0; i--) {
        for (j = i; j < len; j++) {
            PRINTF("\n[%3d]i=%d, j=%d", __LINE__, i, j);
            PRINTF("\n[%3d]s[i]=%c, s[j]=%c", __LINE__, s[i], s[j]);
            if (i == j) {
                map[i][j] = true;
                PRINTF("\n[%3d]MARK", __LINE__);
                continue;
            }

            PRINTF("\n[%3d]i=%d, j=%d, map[i+1][j-1]=%d", __LINE__, i, j, map[i + 1][j - 1]);

            if ((s[i] == s[j]) && ((i + 1 == j) || (map[i + 1][j - 1] == true))) {
                PRINTF("\n[%3d]MARK", __LINE__);
                map[i][j] = true;
            }
        }
    }
}

int minCut(char *s)
{
    int len = strlen(s);
    int *dp = NULL;
    int **map;
    int i, j;

    if (len < 2) {
        return 0;
    }

    map = (int **)malloc(sizeof(int *) * len);
    for (i = 0; i < len; i++) {
        map[i] = (int *)malloc(sizeof(int) * len);
        memset(map[i], 0, sizeof(int) * len);
    }

    prev_handle(s, map);

    for (i = 0; i < len; i++) {
        PRINTF("\n");
        for (j = 0; j < len; j++) {
            PRINTF(" %d ", map[i][j]);
        }
    }

    dp = (int *)malloc(sizeof(int) * len);
    for (i = 0; i < len; i++) {
        dp[i] = i;
    }

    for (i = 1; i < len; i++) {
        if (map[0][i]) {
            dp[i] = 0;
            continue;
        }

        for (j = 0; j < i; j++) {
            if (map[j + 1][i]) {
                dp[i] = MIN(dp[i], dp[j] + 1);
            }
        }
    }

    int result = dp[len - 1];

    for (i = 0; i < len; i++) {
        free(map[i]);
    }

    free(map);
    free(dp);

    return result;
}

int main()
{
    char input[] = "aab";
    minCut(input);
    system("pause");
    return 0;
}