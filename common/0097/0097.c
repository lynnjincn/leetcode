#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PRINTF printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

bool isInterleave(char *s1, char *s2, char *s3)
{
    int len_1 = strlen(s1);
    int len_2 = strlen(s2);
    int len_3 = strlen(s3);
    int i, j;
    char **dp;

    if ((len_1 + len_2 != len_3) || (s3 == NULL)) {
        return false;
    }

    dp = (char **)malloc(sizeof(char *) * (len_1 + 1));
    if (dp != NULL) {
        for (i = 0; i <= len_1; i++) {
            dp[i] = (char *)malloc(len_2 + 1);
            if (dp[i] != NULL) {
                memset(dp[i], false, len_2 + 1);
            } else {
                return false;
            }
        }
    } else {
        return false;
    }

    for (i = 0; i <= len_1; i++) {
        for (j = 0; j <= len_2; j++) {
            if ((i == 0) && (j == 0)) {
                dp[i][j] = true;
            } else if (i == 0) {
                if ((s3[i + j - 1] == s2[j - 1]) && (dp[i][j - 1] == true)) {
                    dp[i][j] = true;
                }
            } else if (j == 0) {
                if ((s3[i + j - 1] == s1[i - 1]) && (dp[i - 1][j] == true)) {
                    dp[i][j] = true;
                }
            } else {
                if (((s3[i + j - 1] == s2[j - 1]) && (dp[i][j - 1] == true)) ||
                    ((s3[i + j - 1] == s1[i - 1]) && (dp[i - 1][j] == true))) {
                    dp[i][j] = true;
                }
            }
        }
    }

    return dp[len_1][len_2];
}

int main()
{
    system("pause");
    return 0;
}