// 0322.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "stdlib.h"
#include "stdio.h"

#define PRINTF //printf
#define NOT_CALCULATE       (-1)
#define CANNOT_CALCULATE    0
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int g_cast = 0;
int *g_dp = NULL;

int my_compare_function(const void* nums1, const void* nums2)
{
    int n1 = *(int*)nums1;
    int n2 = *(int*)nums2;

    return (n1 - n2);
}

int get_cast(int* coins, int coinsSize, int amount)
{
    int i, temp;
    int cast = 0x7fffffff;

    PRINTF("\n[%3d]amount=%d", __LINE__, amount);

    if (amount < coins[0]) {
        g_dp[coins[amount]] = CANNOT_CALCULATE;
        return CANNOT_CALCULATE;
    }

    if (g_dp[amount] != NOT_CALCULATE) {
        return g_dp[amount];
    }

    for (i = 0; i < coinsSize; i++) {
        PRINTF("\n[%3d]coins[%d]=%d", __LINE__, i, coins[i]);
        PRINTF("\n[%3d]left=%d", __LINE__, amount - coins[i]);
        if (amount - coins[i] >=0) {
            PRINTF("\n[%3d]dp[left]=%d", __LINE__, g_dp[amount - coins[i]]);
        }
        if ((amount - coins[i] >= coins[0]) && (g_dp[amount - coins[i]] != CANNOT_CALCULATE)) {
            if (g_dp[amount - coins[i]] != NOT_CALCULATE) {
                temp = g_dp[amount - coins[i]] + 1;
            } else {
                temp = get_cast(coins, coinsSize, amount - coins[i]);
                if (temp != CANNOT_CALCULATE) {
                    temp += 1;
                }
            }
                        
            if (temp != CANNOT_CALCULATE) {
                cast = MIN(cast, temp);
            }
        }
    }

    if (cast != 0x7fffffff) {
        g_dp[amount] = cast;
    } else {
        g_dp[amount] = CANNOT_CALCULATE;
    }

    PRINTF("\n[%3d]g_dp[%d]=%d", __LINE__, amount, g_dp[amount]);
    return g_dp[amount];
}

int coinChange(int* coins, int coinsSize, int amount)
{
    g_dp = (int*)malloc(sizeof(int) * (amount + 1));
    int i;

    if (amount == 0) {
        return 0;
    }

    PRINTF("\n[%3d]before sort:", __LINE__);
    for (i = 0; i < coinsSize; i++) {
        PRINTF("%d ", coins[i]);
    }

    qsort(coins, coinsSize, sizeof(int), my_compare_function);

    PRINTF("\n[%3d]after sort:", __LINE__);
    for (i = 0; i < coinsSize; i++) {
        PRINTF("%d ", coins[i]);
    }

    if (amount < coins[0]) {
        return -1;
    }

    for (i = 0; i < amount + 1; i++) {
        g_dp[i] = NOT_CALCULATE;
    }

    for (i = 0; i < coinsSize; i++) {
        if (coins[i] <= amount) {
            g_dp[coins[i]] = 1;
        }
    }

    PRINTF("\n[%3d]init dp:", __LINE__);
    for (i = 0; i < amount + 1; i++) {
        if (g_dp[i] != -1) {
            PRINTF("\n[%3d]$%d need %d coin(s)", __LINE__, i, g_dp[i]);
        }
    }

    get_cast(coins, coinsSize, amount);

    PRINTF("\n[%3d]calculated dp:", __LINE__);
    for (i = 0; i < amount + 1; i++) {
        if ((g_dp[i] != NOT_CALCULATE) && (g_dp[i] != CANNOT_CALCULATE)) {
            PRINTF("\n[%3d]$%d need %d coin(s)", __LINE__, i, g_dp[i]);
        }
    }

    if ((g_dp[amount] == NOT_CALCULATE) || (g_dp[amount] == CANNOT_CALCULATE)) {
        return -1;
    }

    return g_dp[amount];
}



#if 动态规划（自底向上）
#define PRINTF printf
#define NOT_CALCULATE   (-1)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int my_compare_function(const void* nums1, const void* nums2)
{
    int n1 = *(int*)nums1;
    int n2 = *(int*)nums2;

    return (n1 - n2);
}

int coinChange(int* coins, int coinsSize, int amount)
{
    int* dp = (int *)malloc(sizeof(int) * (amount + 1));
    int i, j, cast;

    if (amount == 0) {
        return 0;
    }

    PRINTF("\n[%3d]before sort:", __LINE__);
    for (i = 0; i < coinsSize; i++) {
        PRINTF("%d ", coins[i]);
    }

    qsort(coins, coinsSize, sizeof(int), my_compare_function);

    PRINTF("\n[%3d]after sort:", __LINE__);
    for (i = 0; i < coinsSize; i++) {
        PRINTF("%d ", coins[i]);
    }

    if (amount < coins[0]) {
        return -1;
    }

    for (i = 0; i < amount + 1; i++) {
        dp[i] = NOT_CALCULATE;
    }

    for (i = 0; i < coinsSize; i++) {
        if (coins[i] <= amount) {
            dp[coins[i]] = 1;
        }
    }

    PRINTF("\n[%3d]init dp:", __LINE__);
    for (i = 0; i < amount + 1; i++) {
        if (dp[i] != -1) {
            PRINTF("\n[%3d]$%d need %d coin(s)", __LINE__, i, dp[i]);
        }
    }

    // 通过￥i遍历￥1至￥amount之间的所有金额可能的最小cast
    for (i = 1; i < amount + 1; i++) {
        if ((i < coins[0]) || (dp[i] != -1)) {
            // 当前要计算的数值比最小的硬币或者之前已经进行过最小cast计算的不再重复处理
            continue;
        }

        // 计算￥i元可能的最小cast，这里将￥i分为part_1和part_2两个部分，递归判断part_1与part_2的cast加和最小的情况
        cast = 0x7fffffff;
        PRINTF("\n[%3d]$i=%d", __LINE__, i);
        for (j = 0; j < coinsSize; j++) {
            PRINTF("\n[%3d]coin[%d]=%d, left=%d", __LINE__, j, coins[j], i - coins[j]);
            if ((i - coins[j] >= coins[0]) && (dp[i - coins[j]] != -1)) {
                PRINTF("\n[%3d]dp[i-coins[j]]=%d", __LINE__, dp[i - coins[j]]);
                cast = MIN(cast, 1 + dp[i - coins[j]]);
            }
        }

        if (cast != 0x7fffffff) {
            dp[i] = cast;        
        }
    }

    PRINTF("\n[%3d]calucate dp:", __LINE__);
    for (i = 0; i < amount + 1; i++) {
        if (dp[i] != -1) {
            PRINTF("\n[%3d]$%d need %d coin(s)", __LINE__, i, dp[i]);
        }
    }

    return dp[amount];
}
#endif

int main()
{
    int coins[] = {186,419,83,408};
    //int coins[] = {2, 3};

    printf("\n[%3d]result=%d", __LINE__, coinChange(coins, sizeof(coins) / sizeof(int), 6249));
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
