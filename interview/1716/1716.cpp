// 1716.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define START 1

#if START
#define PRINTF printf
#if 0
这种写法超时了，不过可以优化为dp保存已经计算过的数据
int get_long(int* array, int index, int size)
{
    PRINTF("\n[%3d]index=%d, size=%d", __LINE__, index, size);
    if (index + 2 >= size) {
        return array[index];
    }

    int i, temp, temp_i;
    int max = 0;

    for (i = index + 2; i < size; i++) {
        temp = get_long(array, i, size);
        PRINTF("\n[%3d]i=%d, temp=%d", __LINE__, i, temp);
        if (temp >= max) {
            max = temp;
            temp_i = i;
        }
    }

    return array[index] + get_long(array, temp_i, size);
}

int massage(int* nums, int numsSize)
{
    int i, temp_result;
    int max = 0;

    for (i = 0; i < numsSize; i++) {
        temp_result = get_long(nums, i, numsSize);
        if (max < temp_result) {
            max = temp_result;
        }
    }

    return max;
}
#endif

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int massage(int* nums, int numsSize)
{
    int i, dp_0, dp_1, temp_dp_0, temp_dp_1;

    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }

    dp_0 = 0;
    dp_1 = nums[0];

    for (i = 2; i < numsSize; i++) {
        temp_dp_0 = MAX(dp_0, dp_1);
        temp_dp_1 = nums[i] + dp_0;

        dp_0 = temp_dp_0;
        dp_1 = temp_dp_1;
    }

    return MAX(dp_0, dp_1);
}

#endif


int main()
{
    int array[] = {10};
    //int array[] = { 2, 1, 4, 5, 3, 1, 1, 3 };
    //int array[] = {1, 2, 3, 1};
    //int array[] = {2,7,9,3,1};

    printf("\n[%3d]result=%d", __LINE__, massage(array, sizeof(array) / sizeof(int)));
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
