// 0010.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/regular-expression-matching/

#include <iostream>

#define PRINTF printf

int find_last_char_index(char *s, char target_p) {
    int s_len = strlen(s);
    int i;
    int result = -1;
    for (i = 0; i < s_len; i++) {
        if (s[i] == target_p) {
            result = i;
        }
    }

    return result;
}

bool isMatch(char *s, char *p)
{
    int s_len = strlen(s);
    int p_len = strlen(p);
    int i_loop, j_loop, temp_i, i, j;
    char **dp;

    if ((p_len == 2) && (p[0] == '.') && (p[1] == '*')) {
        return true;
    }

    if (p_len == 0) {
        if (s_len == 0) {
            return true;
        } else {
            return false;
        }
    }

    dp = (char **)malloc(sizeof(char **) * (p_len + 1));
    if (dp == NULL) {
        return false;
    } else {
        for (j_loop = 0; j_loop < p_len + 1; j_loop++) {
            dp[j_loop] = (char *)malloc(sizeof(char) * (s_len + 1));
            if (dp[j_loop] == NULL) {
                return false;
            } else {
                memset(dp[j_loop], false, s_len + 1);
            }
        }
    }

    dp[0][0] = true;
        for (j_loop = 1; j_loop < p_len + 1; j_loop++) {
        if (p[j_loop - 1] == '*') {
            PRINTF("\n[%3d]dp[j_loop - 2][0]=%d", __LINE__, dp[j_loop - 2][0]);
            dp[j_loop][0] = dp[j_loop - 2][0];
        }
    }

    PRINTF("\n[%3d]init dp:", __LINE__);
    PRINTF("\n[%3d]    # ", __LINE__);
    for (i_loop = 0; i_loop < s_len ; i_loop++) {
        PRINTF(" %c ", s[i_loop]);
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

    for (i_loop = 1; i_loop < s_len + 1; i_loop++) {
        for (j_loop = 1; j_loop < p_len + 1; j_loop++) {
            i = i_loop - 1;
            j = j_loop - 1;
            PRINTF("\n[%3d]p[%d]=%c, s[%d]=%c", __LINE__, j, p[j], i, s[i]);
            if (p[j] == s[i]) {
                // 如果string的最后一个字符与patern的最后一个字符相同则只参考比较去掉string和patern最后一个字符的结果即dp[j][i] = dp[j-1][i-1]
                dp[j_loop][i_loop] = dp[j_loop - 1][i_loop - 1];
            } else {
                if (p[j] == '*') {
                    if (p[j - 1] == '.') {
                        // .*
                        if (j_loop == 2) {
                            // 在patern开头的情况
                            dp[j_loop][i_loop] = true;
                        } else {
                            // 不在开头
                            for (temp_i = 0; temp_i < s_len + 1; temp_i++) {
                                if (dp[j_loop - 2][temp_i]) {
                                    dp[j_loop][i_loop] = true;
                                    break;
                                }
                            }                       
                        }
                    } else {
                        PRINTF("\n[%3d]p[j-1]=%c, s[i]=%c, s[i-1]=%c", __LINE__, p[j - 1], s[i], s[i - 1]);

                        // 0 * p[j-1]
                        if (dp[j_loop - 2][i_loop] == true) {
                            dp[j_loop][i_loop] = true;
                            continue;
                        }

                        // 1 * p[j-1]
                        if ((p[j - 1] == s[i]) && (dp[j_loop][i_loop - 1] == true)) {
                            dp[j_loop][i_loop] = true;
                            continue;
                        }
                    }
                } else if (p[j] == '.') {
                    dp[j_loop][i_loop] = dp[j_loop - 1][i_loop - 1];
                }
            }
        }
    }

    PRINTF("\n[%3d]after calculated dp:", __LINE__);
    PRINTF("\n[%3d]    # ", __LINE__);
    for (i = 0; i < s_len ; i++) {
        PRINTF(" %c ", s[i]);
    }

    for (j = 0; j < p_len + 1; j++) {
        if (j == 0) {
            PRINTF("\n[%3d] # ", __LINE__);
        } else {
            PRINTF("\n[%3d] %c ", __LINE__, p[j - 1]);
        }

        for (i = 0; i < s_len + 1; i++) {
            PRINTF(" %d ", dp[j][i]);
        }
    }

    return dp[p_len][s_len];
}

int main()
{
    /*char string[] = "miss";
    char patern[] = "mis*";
    char string[] = "mississippi";
    char patern[] = "mis*is*ip*.";*/
    /*char string[] = "abcd";
    char patern[] = "a.*d";
    char string[] = "abc";
    char patern[] = ".*";
    char string[] = "abcdefg";
    char patern[] = "a.*g";
    char string[] = "abaaa";
    char patern[] = "ab*a*";*/
    char string[] = "ab";
    char patern[] = "ad.*";
    printf("\n[%3d]result=%d", __LINE__, isMatch(string, patern));
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

/*
"fasdfasdfasdfas"
"f.*asdf.*asdf.*asdf.*s"

*/

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
