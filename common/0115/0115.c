#include <stdio.h>
#include <stdlib.h>

// https://leetcode-cn.com/problems/distinct-subsequences/

int numDistinct(char *s, char *t)
{
    int s_len = strlen(s);
    int t_len = strlen(t);
    long **dp;
    int i, j;

    dp = (long **)malloc(sizeof(long *) * (t_len + 1));
    for (i = 0; i < t_len + 1; i++) {
        dp[i] = (long *)malloc(sizeof(long) * (s_len + 1));
        memset(dp[i], 0, sizeof(long) * (s_len + 1));
    }

    for (j = 0; j < s_len + 1; j++) {
        dp[0][j] = 1;
    }

    for (i = 1; i < t_len + 1; i++) {
        for (j = 1; j < s_len + 1; j++) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[t_len][s_len];
}

int main()
{
    char s[100] = {'\0'};
    char t[100] = {'\0'};

    gets(s);
    gets(t);

    numDistinct(s, t);
    system("pause");
    return 0;
}