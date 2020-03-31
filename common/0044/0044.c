// https://leetcode-cn.com/problems/wildcard-matching/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTF printf

#define FALSE 0
#define TRUE 1

char isMatch(char *s, char *p) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    int i_loop, j_loop, i, j;
    char **dp;

    dp = (char **)malloc(sizeof(char **) * (p_len + 1));
    if (dp == NULL) {
        return FALSE;
    } else {
        for (j_loop = 0; j_loop < p_len + 1; j_loop++) {
            dp[j_loop] = (char *)malloc(sizeof(char *) * (s_len + 1));
            memset(dp[j_loop], 0, sizeof(char) * (s_len + 1));
        }
    }
    dp[0][0] = TRUE;
    for (j_loop = 1; j_loop < p_len + 1; j_loop++) {
        j = j_loop - 1;
        if (p[j] == '*') {
            if (j == 0) {
                dp[j_loop][0] = TRUE;
            } else {
                if (dp[j_loop - 1][0] == TRUE) {
                    dp[j_loop][0] = TRUE;
                }
            }
        }
    }

    PRINTF("\n[%3d]init dp:", __LINE__);
    PRINTF("\n[%3d]    # ", __LINE__);
    for (i = 0; i < s_len; i++) {
        PRINTF(" %c ", s[i]);
    }

    for (j_loop = 0; j_loop < p_len + 1; j_loop++) {
        if (j_loop == 0) {
            PRINTF("\n[%3d] # ", __LINE__);
        } else {
            PRINTF("\n[%3d] %c ", __LINE__, p[j_loop - 1]);
        }
        for (i_loop = 0; i_loop < s_len + 1; i_loop++) {
            PRINTF(" %d ", dp[j_loop][i_loop]);
        }
    }

    for (j_loop = 1; j_loop < p_len + 1; j_loop++) {
        for (i_loop = 1; i_loop < s_len + 1; i_loop++) {
            i = i_loop - 1;
            j = j_loop - 1;
            PRINTF("\n[%3d]i=%d, j=%d", __LINE__, i, j);
            if (p[j] == '*') {
                if (j == 0) {
                    dp[j_loop][i_loop] = TRUE;
                    PRINTF("\n[%3d]MARK", __LINE__);
                    continue;
                }

                if (dp[j_loop - 1][i_loop - 1] == TRUE) {
                    PRINTF("\n[%3d]MARK", __LINE__);
                    dp[j_loop][i_loop] = TRUE;
                    continue;
                }

                if (((p[j - 1] == s[i]) || (p[j - 1] == '?') || (p[j - 1] == '*')) && (dp[j_loop - 1][i_loop] == TRUE)) {
                    PRINTF("\n[%3d]MARK", __LINE__);
                    dp[j_loop][i_loop] = TRUE;
                    continue;
                }

                if (dp[j_loop][i_loop - 1] == TRUE) {
                    PRINTF("\n[%3d]MARK", __LINE__);
                    dp[j_loop][i_loop] = TRUE;
                    continue;
                }
            } else {
                PRINTF("\n[%3d]s[i]=%c, p[j]=%c, dp_prev=%d", __LINE__, s[i], p[j], dp[j_loop - 1][i_loop - 1]);
                if ((s[i] == p[j]) || (p[j] == '?')) {
                    dp[j_loop][i_loop] = dp[j_loop - 1][i_loop - 1];
                }
            }
        }
    }

    PRINTF("\n[%3d]calculated dp:", __LINE__);
    PRINTF("\n[%3d]    # ", __LINE__);
    for (i = 0; i < s_len; i++) {
        PRINTF(" %c ", s[i]);
    }

    for (j_loop = 0; j_loop < p_len + 1; j_loop++) {
        if (j_loop == 0) {
            PRINTF("\n[%3d] # ", __LINE__);
        } else {
            PRINTF("\n[%3d] %c ", __LINE__, p[j_loop - 1]);
        }
        for (i_loop = 0; i_loop < s_len + 1; i_loop++) {
            PRINTF(" %d ", dp[j_loop][i_loop]);
        }
    }

    return dp[p_len][s_len];
}

int main() {
    char string[256];
    char pattern[256];

    memset(string, '\0', 256);
    memset(pattern, '\0', 256);

    printf("input string:\n");
    gets(string);
    printf("\ninput pattern:\n");
    gets(pattern);

    printf("\n[%3d]Result=%d", __LINE__, isMatch(string, pattern));
    system("pause");
    return 0;
}