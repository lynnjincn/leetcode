// 0072.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/edit-distance/

#include <iostream>

#define PRINTF printf
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

/* 
 * 本题使用动态规划的通项公式如下：
 * 如果想要将"XA"变为"YB"存在三种做法，假设XA变为Y、X变为YB以及X变为Y结果已知
 * 1. 替换：
 *    X | A           X |[B]
 *      |     ==>       |
 *    Y | B           Y | B
 * 也就是在X变为Y的基础上增加1个消耗
 *
 * 2. 增加B:
 *    XA|             XA|[B]
 *      |     ==>       |
 *    Y | B           Y | B
 * 在XA变为Y的基础上，再在XA上增加一个字符使得XAB与YB相同
 *
 * 3. 删除A:
 *    X | A           X |
 *      |     ==>       |
 *    YB|             YB|
 * 在X变为YB的基础上，再在XA上删除一个字符使得X与YB相同
 *
 * 如果是XA与YA的情况则，因为尾字符相同，只需要考虑以上2、3两种策略
 */

int minDistance(char* word1, char* word2)
{
    int len_1 = strlen(word1);
    int len_2 = strlen(word2);
    int i, j;
    int **dp;

    PRINTF("\n[%3d]word1[%d]=%s", __LINE__, len_1, word1);
    PRINTF("\n[%3d]word2[%d]=%s", __LINE__, len_2, word2);

    if ((len_1 == 0) && (len_2 == 0)) {
        return 0;
    } else if (len_1 == 0) {
        return len_2;
    } else if (len_2 == 0) {
        return len_1;
    }

    dp = (int **)malloc(sizeof(int *) * (len_2 + 1));
    for (i = 0; i < len_2 + 1; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (len_1 + 1));
        memset(dp[i], 0, sizeof(int) * (len_1 + 1));
    }

    for (j = 0; j < len_1 + 1; j++) {
        dp[0][j] = j;
    }

    for (i = 0; i < len_2 + 1; i++) {
        dp[i][0] = i;
    }

    PRINTF("\n[%3d]init dp:", __LINE__);
    for (i = 0; i < len_2 + 1; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < len_1 + 1; j++) {
            PRINTF("%3d", dp[i][j]);
        }
    }

    for (i = 1; i < len_2 + 1; i++) {
        for (j = 1; j < len_1 + 1; j++) {
            PRINTF("\n[%3d]word1[%d]=%c, word2[%d]=%c", __LINE__, j - 1, word1[j - 1], i - 1, word2[i - 1]);
            if (word1[j - 1] == word2[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = MIN(MIN(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
            }
        }
    }

    PRINTF("\n[%3d]calculated dp:", __LINE__);
    for (i = 0; i < len_2 + 1; i++) {
        PRINTF("\n[%3d]", __LINE__);
        for (j = 0; j < len_1 + 1; j++) {
            PRINTF("%3d", dp[i][j]);
        }
    }

    return dp[len_2][len_1];
}


int main()
{
    char word1[] = "horse";
    char word2[] = "ros";
    printf("\n[%3d]result=%d", __LINE__, minDistance(word1, word2));
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
