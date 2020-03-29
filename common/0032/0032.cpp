﻿// 0032.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/longest-valid-parentheses/

#include <iostream>

#define PRINTF //printf

void update_result(int *result, int num)
{
    if (num > *result) {
        *result = num;
    }
}

void debug_printf_string(char *s, int start ,int end, int line_num)
{
    int i;

    PRINTF("\n[%3d]string[%d, %d]=", line_num, start, end);

    for (i = start; i <= end; i++) {
        PRINTF("%c", s[i]);
    }
}

void update_max_end(int start, int end, int *max_end)
{
    if (end > max_end[start]) {
        max_end[start] = end;
    }
}

int longestValidParentheses(char * s)
{
    int len = strlen(s);
    int result = 0;
    int i, start, end, temp_end;
    char **dp;
    int *max_end;

    if (len < 2) {
        return 0;
    } else {
        dp = (char **)malloc(sizeof(char *) * len);
        if (dp == NULL) {
            return 0;
        } else {
            for (i = 0; i < len; i++) {
                dp[i] = (char *)malloc(sizeof(char) * len);
                if (dp[i] == NULL) {
                    return 0;
                } else {
                    memset(dp[i], false, sizeof(char) * len);
                }
            }

            max_end = (int *)malloc(sizeof(int) * len);
            memset(max_end, 0, sizeof(int) * len);
        }
    }

    for (start = len - 1; start >= 0; start--) {
        for (end = start; end < len; end++) {
            debug_printf_string(s, start, end, __LINE__);
            if ((start != end) && (s[end] != '(') && (s[start] != ')')) {
                if (start + 1 == end) {
                    if ((s[start] == '(') && (s[end] == ')')) {
                        dp[start][end] = true;
                        update_max_end(start ,end, max_end);
                        PRINTF("\n[%3d]true mark", __LINE__);
                    }
                } else {
                    if (dp[start + 1][end - 1] == true) {
                        dp[start][end] = true;
                        update_max_end(start ,end, max_end);
                        PRINTF("\n[%3d]true mark", __LINE__);
                        continue;
                    }

                    if (max_end[start] != 0) {
                        temp_end = max_end[start];
                        if (dp[temp_end + 1][end] == true) {
                            dp[start][end] = true;
                            update_max_end(start ,end, max_end); 
                            PRINTF("\n[%3d]true mark", __LINE__);
                        }
                    }
                }
            } else {
                PRINTF("\n[%3d]false mark", __LINE__);
            }
        }
    }

    PRINTF("\n[%3d]dp:", __LINE__);
    PRINTF("\n[%3d]   ", __LINE__);
    for (end = 0; end < len; end++) {
        PRINTF(" %d ", end);
    }

    for (start = 0; start < len; start++) {
        PRINTF("\n[%3d] %d ", __LINE__, start);
        for (end = 0; end < len; end++) {
            PRINTF(" %d ", dp[start][end]);
            if (dp[start][end] == true) {
                update_result(&result, end - start + 1);
            }
        }
    }

    return result;
}

int main()
{
    //char input_string[] = "(()())";
    char input_string[] = "(()(()()()(()())()(()()))()()())()(((()())((())(()()((()((((())(())()()(())()(()(()(())))))))(()()()))()()))))))(()())))((())())))()(((()(()))())((())))(())(((()()))))())))((()((()()(()))())(()))(())((())()(((()(((()))))()))()()())()()()(()(()(()()()(()(())(())))())()))())(())((())(()((((())((())((())(()()(((()))(()(((())())()(())))(()))))))(()(()(()))())(()()(()(((()()))()(())))(()()(())))))(()(()()())))()()())))))((())(()()(((()(()()))(())))(((()))())())())(((()((()((()())((()))(()()((()(())())(()))()())())))))()(()())))()()))(((()(()))((()((((())((())))((())()()))())()(((()()(((()))))))(((()))()(()(((())(())()()()))))()))()))))()(()))()()()))))()(()))()()(()())))(()))()())(())()())(())()()))(()())))((()())))())))))((()))())()()))))()))(((())(())()))()()((()))(((()))))((()((()))(())(((()))()()()())())())))(()(((())()())(())(((()()((())()))(()()(((())))((()(((()))(((((()(((())())))(())(()()((()(()(())())(((((())((()()))())(()())))()()()(()(((((((())))(()()()()((()(((())())())())))())())())))()((((())(((()()()())()))()()(()(()()))()))(())(()())))))()())()())))()()(())))))))((())()()(((()))()))())))))((()())((()())(((())()())()))(()(()()(((()(())()))()())()()(())()(()))))()))()()))))(())(()()(())((()))(()))((())))))(())))()))(()()(())))())()((())()))((()()(()())()()(()))())(((())()(((()((())()(()()()((()(()())(()())())((((())))())())))(()))(((())((()))))((()()(((())((())()()()))((()())()()())())))))((((()((()())))(())(())()()()(((((())())()()()(())())()((()(()())(((())((((()((()(((()))(()()))())()()(()(()(())))()))())))(()()(()))))))(()()())()()))()(())()(";
    
    printf("\n[%3d]result=%d", __LINE__, longestValidParentheses(input_string));
}

/*
"(()(()()()(()())()(()()))()()())()(((()())((())(()()((()((((())(())()()(())()(()(()(())))))))(()()()))()()))))))(()())))((())())))()(((()(()))())((())))(())(((()()))))())))((()((()()(()))())(()))(())((())()(((()(((()))))()))()()())()()()(()(()(()()()(()(())(())))())()))())(())((())(()((((())((())((())(()()(((()))(()(((())())()(())))(()))))))(()(()(()))())(()()(()(((()()))()(())))(()()(())))))(()(()()())))()()())))))((())(()()(((()(()()))(())))(((()))())())())(((()((()((()())((()))(()()((()(())())(()))()())())))))()(()())))()()))(((()(()))((()((((())((())))((())()()))())()(((()()(((()))))))(((()))()(()(((())(())()()()))))()))()))))()(()))()()()))))()(()))()()(()())))(()))()())(())()())(())()()))(()())))((()())))())))))((()))())()()))))()))(((())(())()))()()((()))(((()))))((()((()))(())(((()))()()()())())())))(()(((())()())(())(((()()((())()))(()()(((())))((()(((()))(((((()(((())())))(())(()()((()(()(())())(((((())((()()))())(()())))()()()(()(((((((())))(()()()()((()(((())())())())))())())())))()((((())(((()()()())()))()()(()(()()))()))(())(()())))))()())()())))()()(())))))))((())()()(((()))()))())))))((()())((()())(((())()())()))(()(()()(((()(())()))()())()()(())()(()))))()))()()))))(())(()()(())((()))(()))((())))))(())))()))(()()(())))())()((())()))((()()(()())()()(()))())(((())()(((()((())()(()()()((()(()())(()())())((((())))())())))(()))(((())((()))))((()()(((())((())()()()))((()())()()())())))))((((()((()())))(())(())()()()(((((())())()()()(())())()((()(()())(((())((((()((()(((()))(()()))())()()(()(()(())))()))())))(()()(()))))))(()()())()()))()(())()("
*/

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
