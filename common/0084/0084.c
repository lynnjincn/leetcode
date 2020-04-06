#include <stdio.h>
#include <stdlib.h>

#define TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE (1)  //二维数组输入样例
#define PRINTF                                  // printf
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int largestRectangleArea(int *heights, int heightsSize)
{
    int i, j, min_height, width;
    int result = 0;

    PRINTF("\n[%3d]heightsSize=%d", __LINE__, heightsSize);
    if ((heightsSize == 0) || (heights == NULL)) {
        return result;
    }

    for (i = 0; i < heightsSize; i++) {
        PRINTF("\n[%3d]i=%d", __LINE__, i);
        min_height = 0x7fffffff;
        for (j = i; j < heightsSize; j++) {
            PRINTF("\n[%3d]j=%d", __LINE__, j);
            min_height = MIN(min_height, heights[j]);
            width = j - i + 1;
            PRINTF("\n[%3d]width=%d, height=%d", __LINE__, width, min_height);
            result = MAX(result, width * min_height);
        }
    }

    return result;
}

// 栈法（单调栈），保持栈的单调递增，
// 出现扰乱单调性的元素准备入栈时，制定对应的处理策略。所有元素处理完成之后，针对留在栈中的元素制定对应的处理策略。
int *g_stack = NULL;
int g_pop = 0;

int *create_stack(int depth)
{
    int *stack = (int *)malloc(sizeof(int) * depth);
    return stack;
}

int get_stack_pop(void)
{
    return g_stack[g_pop - 1];
}

void pop_stack(void)
{
    g_pop--;
    g_stack[g_pop] = 0;
}

void push_stack(int value)
{
    g_stack[g_pop] = value;
    g_pop++;
}

int largestRectangleArea(int *heights, int heightsSize)
{
    int result = 0;
    int i, temp_height, width;

    PRINTF("\n[%3d]heightsSize=%d", __LINE__, heightsSize);
    if ((heightsSize == 0) || (heights == NULL)) {
        return result;
    } else if (heightsSize == 1) {
        return heights[i];
    }

    g_pop = 0;
    g_stack = create_stack(heightsSize + 1);

    push_stack(-1);

    for (i = 0; i < heightsSize; i++) {
        PRINTF("\n[%3d]height[%d]=%d, stack_pop=%d", __LINE__, i, heights[i], get_stack_pop());
        while ((get_stack_pop() != -1) && (heights[i] <= heights[get_stack_pop()])) {
            PRINTF("\n[%3d]heightsSize=%d", __LINE__, heightsSize);
            temp_height = heights[get_stack_pop()];
            pop_stack();

            // i - 1表示stack[top]与height[i]比较前最后一个栈元素的下标
            width = i - 1 - get_stack_pop();
            result = MAX(width * temp_height, result);
        }

        PRINTF("\n[%3d]g_pop=%d", __LINE__, g_pop);
        push_stack(i);
        PRINTF("\n[%3d]heightsSize=%d", __LINE__, heightsSize);
    }
    PRINTF("\n[%3d]heightsSize=%d", __LINE__, heightsSize);

    while (get_stack_pop() != -1) {
        temp_height = heights[get_stack_pop()];
        pop_stack();

        width = heightsSize - get_stack_pop() - 1;
        result = MAX(result, width * temp_height);
    }

    free(g_stack);

    return result;
}

int main()
{
#if TWO_DIMENSIONAL_ARRAY_INPUT_SAMPLE
    int **two_dimensional_array;
    int column = 0;
    int row = 0;
    int i, j;

    printf("\ninput column:");
    scanf("%d", &column);
    printf("\ninput row:");
    scanf("%d", &row);

    two_dimensional_array = (long **)malloc((sizeof(long *) * column));
    if (two_dimensional_array == NULL) {
        return 0;
    } else {
        for (i = 0; i < column; i++) {
            two_dimensional_array[i] = (long *)malloc(sizeof(long) * row);
            if (two_dimensional_array[i] == NULL) {
                return 0;
            } else {
                memset(two_dimensional_array[i], 0, sizeof(long *) * row);
            }
        }
    }

    for (i = 0; i < column; i++) {
        for (j = 0; j < row; j++) {
            printf("\ninput column[%d][%d]]:", i, j);
            scanf("%d", &two_dimensional_array[i][j]);
        }
    }
#endif

    system("pause");
    return 0;
}