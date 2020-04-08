#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例

#define PRINTF printf

int numDecodings(char *s)
{
    int len = strlen(s);
    int *dp;
    int result, i;

    if ((s == NULL) || (len == 0)) {
        return 0;
    } else if (s[0] == '0') {
        return 0;
    } else if (len == 1) {
        return 1;
    }

    PRINTF("\n[%3d]s[%d]=%s", __LINE__, len, s);

    dp = (int *)malloc(sizeof(int) * len);
    if (dp != NULL) {
        memset(dp, 0, sizeof(int) * len);
    } else {
        return 0;
    }

    dp[0] = 1;
    if (((s[0] == '2') && ((s[1] <= '6') && (s[1] > '0'))) || ((s[0] == '1') && (s[1] > '0'))) {
        dp[1] = 2;
        PRINTF("\n[%3d]MARK", __LINE__);
    } else if ((s[1] == '0') && (s[0] > '2')) {
        PRINTF("\n[%3d]MARK", __LINE__);
        return 0;
    } else {
        dp[1] = 1;
        PRINTF("\n[%3d]MARK", __LINE__);
    }

    for (i = 2; i < len; i++) {
        PRINTF("\n[%3d]current_num=%c, prev_num=%c", __LINE__, s[i], s[i - 1]);
        if (s[i] == '0') {
            if (s[i - 1] > '0' && s[i - 1] <= '2') {
                PRINTF("\n[%3d]MARK", __LINE__);
                dp[i] = dp[i - 2];
                continue;
            } else {
                return 0;
            }
        }

        if ((s[i - 1] == '1') || ((s[i - 1] == '2') && (s[i] <= '6'))) {
            PRINTF("\n[%3d]MARK", __LINE__);
            dp[i] = dp[i - 1] + dp[i - 2];
        } else {
            PRINTF("\n[%3d]MARK", __LINE__);
            dp[i] = dp[i - 1];
        }
    }

    result = dp[len - 1];
    free(dp);
    return result;
}

int main()
{
    char *input = NULL;
    int str_len = 0;
    printf("\ninput string len:");
    scanf("%d", &str_len);
    input = (char *)malloc(str_len + 1);
    memset(input, '\0', str_len + 1);
    getchar();
    printf("\ninput string:");
    gets(input);

    printf("\n[%3d]result=%d", __LINE__, numDecodings(input));

    system("pause");
    return 0;
}