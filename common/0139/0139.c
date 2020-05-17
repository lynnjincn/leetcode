#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

bool wordBreak(char *s, char **wordDict, int wordDictSize)
{
    bool *dp;
    int i, j, k, word_len;
    int s_len = strlen(s);

    if ((s == NULL) || (wordDictSize == 0)) {
        return false;
    }

    dp = (bool *)malloc(sizeof(bool) * s_len);
    memset(dp, 0, sizeof(bool) * s_len);

    for (k = 0; k < wordDictSize; k++) {
        word_len = strlen(wordDict[k]);
        if (word_len <= s_len) {
            if (memcmp(s, wordDict[k], word_len) == 0) {
                dp[word_len - 1] = true;
            }
        }
    }

    for (i = 0; i < s_len; i++) {
        for (j = 0; j < i; j++) {
            PRINTF("\n[%3d]i=%d, j=%d, dp[j]=%d", __LINE__, i, j, dp[j]);
            if (dp[j] == true) {
                for (k = 0; k < wordDictSize; k++) {
                    word_len = strlen(wordDict[k]);
                    PRINTF("\n[%3d]k=%d, word[%d]=%s, s_diff=%d", __LINE__, k, word_len, wordDict[k], i - j + 1);
                    if ((word_len == i - j) && (memcmp(&(s[j + 1]), wordDict[k], word_len) == 0)) {
                        dp[i] = true;
                        PRINTF("\n[%3d]MARK, i=%d", __LINE__, i);
                        break;
                    }
                }
            }
        }
    }

    return dp[s_len - 1];
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