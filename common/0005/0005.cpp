// 0005.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define PRINTF //printf

/*
 * 本题使用动态规划，基本通项公式如下：
 * 对于字符串xxxx而言，如果在左右两端各增加一个相同的字符，不会改变结果字符串的回文属性.
 * 如果xxxx字符串本身已经是回文字符串，增加相同字符后，仍旧是回文字符串，并且长度增加2.
 * 如果xxxx字符串本省不是回文字符串，增加相同字符后，仍旧不是回文字符串
 * 因此只需要从最基本的0个、1个、2个字符开始判断是否是回文字符串，并在其两侧逐步增加字符即可知道过程中的回文字符串最大长度
 */

char *longestPalindrome(char *s)
{
    int **dp = NULL;
    char *result = NULL;
    int str_len = strlen(s);
    int i, j, loop;
    int left = 0;
    int right = 0;
    int max_len = 1;

    PRINTF("\r\nstrlen=%d", str_len);

    if (str_len == 0) {
        return NULL;
    } else if (str_len == 1) {
        return s;
    }

    dp = (int **)malloc(sizeof(int *) * str_len);
    for (loop = 0; loop < str_len; loop++) {
        dp[loop] = (int *)malloc(sizeof(int) * str_len);
        memset(dp[loop], 0, sizeof(int) * str_len);
    }

    for (i = str_len - 1; i >= 0; i--) {
        for (j = i; j < str_len; j++) {
            PRINTF("\r\n i=%d, j=%d", i, j);
            if (s[i] == s[j]) {
                if (i == j) {
                    dp[i][j] = 1;
                    goto HANDLE_MAX;
                }

                if (i + 1 == j) {
                    dp[i][j] = 2;
                    goto HANDLE_MAX;
                }

                if (dp[i + 1][j - 1] != 0) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    goto HANDLE_MAX;
                }
            }

        HANDLE_MAX:
            if (dp[i][j] > max_len) {
                max_len = dp[i][j];
                left = i;
                right = j;
                PRINTF("\r\nfind max, len=%d, left=%d, right=%d", max_len, left, right);
            }
        }
    }

    PRINTF("\r\ndp=\n");
    for (i = 0; i < str_len; i++) {
        for (j = 0; j < str_len; j++) {
            PRINTF("%2d ", dp[i][j]);
        }

        PRINTF("\n");
    }

    PRINTF("\r\nmax_len=%d, left=%d, right=%d", max_len, left, right);

    result = (char *)malloc(right - left + 2);
    memcpy(result, &(s[left]), right - left + 1);
    result[right - left + 1] = '\0';
    return result;
}

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
