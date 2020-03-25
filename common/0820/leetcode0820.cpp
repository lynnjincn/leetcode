// leetcode0820.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define START 1

#if START
#define PRINTF  printf

// 本函数特殊实现，在原始字符串空间上进行逆转
void reverse_string(char *string)
{
    int len = strlen(string);
    int middle = len / 2;
    int loop;
    char temp;

    for (loop = 0; loop < middle; loop++) {
        temp = string[loop];
        string[loop] = string[len - 1 - loop];
        string[len - 1 - loop] = temp;
    }
}

void sort_string(char** words, int wordsSize)
{
    int i, j;
    char* temp;

    for (i = 0; i < wordsSize; i++) {
        for (j = i + 1; j < wordsSize; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int minimumLengthEncoding(char** words, int wordsSize)
{
    int i, j;
    char* temp;
    int result = 0;

    if (wordsSize == 0) {
        return 1;
    } else if (wordsSize == 1) {
        return (1 + strlen(words[0]));
    }


    for (i = 0; i < wordsSize; i++) {
        reverse_string(words[i]);
    }

    sort_string(words, wordsSize);

    PRINTF("\nprev operate finished:");
    for (i = 0; i < wordsSize; i++) {
        PRINTF("\n[%3d]words[%d]=%s", __LINE__, i, words[i]);
    }

    for (i = 0; i < wordsSize - 1; i++) {
        PRINTF("\n[%3d]i=%d", __LINE__, i);
        PRINTF("\n[%3d]i_string=%s", __LINE__, words[i]);
        for (j = i + 1; j < wordsSize; j++) {
            PRINTF("\n[%3d]j=%d", __LINE__, j);
            PRINTF("\n[%3d]j_string=%s", __LINE__, words[j]);
            if (strcmp(words[i], words[j]) != 0) {
                temp = strstr(words[j], words[i]);
                PRINTF("\n[%3d]temp=%p, words[j]=%p", __LINE__, temp, words[j]);
                if (temp != words[j]) {
                    // 找到与words[i]没有“包含”关系的第一个字符串，这里的“包含”关系指的是真前缀的情况
                    result += (strlen(words[j - 1]) + 1);
                    i = j - 1;
                    PRINTF("\n[%3d]increase=%d", __LINE__, strlen(words[j - 1]) + 1);
                    PRINTF("\n[%3d]result=%d", __LINE__, result);
                    break;
                }
            }
        }
    }

    result += (strlen(words[wordsSize - 1]) + 1);

    return result;
}
#endif

int main()
{
    char temp[3][10] = { "c", "bc", "abc" };
    char** input;
    int i;

    input = (char**)malloc(sizeof(char*) * 3);
    for (i = 0; i < 3; i++) {
        input[i] = (char*)malloc(strlen(temp[i]) + 1);
        memset(input[i], '\0', strlen(temp[i]) + 1);
        memcpy(input[i], temp[i], strlen(temp[i]));
    }

    printf("\n[%3d]result=%d", __LINE__, minimumLengthEncoding(input, 3));
    /*printf("\nbefore:%s", temp);
    reverse_string(temp);
    printf("\nafter:%s", temp);*/
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
