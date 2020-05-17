#define PRINTF //printf
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))


char * multiply(char * num1, char * num2){
    if ((num1 == NULL) || (num2 == NULL)) {
        return NULL;
    }

    int len_1 = strlen(num1);
    int len_2 = strlen(num2);
    int i, j, temp_num_1, temp_num_2, temp_result, mark_i, mark_j, offset;
    int *result;
    char *result_char;

    if (((len_1 == 1) && (num1[0] == '0')) || ((len_2 == 1) && (num2[0] == '0'))) {
        PRINTF("\n[%3d]MARK", __LINE__);
        return "0";
    }

    result = (int *)malloc(sizeof(int) * (len_1 + len_2 + 1));
    result_char = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
    if ((result == NULL) || (result_char == NULL)){
        return NULL;
    } else {
        memset(result, 0, sizeof(int) * (len_1 + len_2 + 1));
        memset(result_char, '0', sizeof(char) * (len_1 + len_2 + 1));
        result_char[len_1 + len_2] = '\0';
    }

    PRINTF("\n[%3d]result_char=%s", __LINE__, result_char);
    for (mark_i = len_1 - 1; mark_i >= 0; mark_i--) {
        for (mark_j = len_2 - 1; mark_j >= 0; mark_j--) {
            i = len_1 - mark_i - 1;      // i, j表示从低位开始的第几个位数
            j = len_2 - mark_j - 1;

            temp_num_1 = num1[mark_i] - '0';
            temp_num_2 = num2[mark_j] - '0';
            offset = i + j;

            PRINTF("\n[%3d]temp_num_1[%d]=%d, temp_num_2[%d]=%d, offset=%d", __LINE__,
                mark_i, temp_num_1, mark_j, temp_num_2, offset);

            result[offset] += (temp_num_1 * temp_num_2);
            PRINTF("\n[%3d]result[%d]=%d", __LINE__, offset, result[offset]);
        }
    }

    for (i = 0; i < len_1 + len_2 - 1; i++) {
        if (result[i] >= 10) {
            result[i + 1] += result[i] / 10;
            result[i] = result[i] % 10;
        }
        PRINTF("\n[%3d]result[%d]=%d", __LINE__, i, result[i]);
    }

    for (i = len_1 + len_2 - 1; i >= 0; i--) {
        PRINTF("\n[%3d]result[%d]=%d", __LINE__, i, result[i]);
        result_char[len_1 + len_2 - i - 1] = result[i] + '0';
    }

    PRINTF("\n[%3d]result_char=%s", __LINE__, result_char);

    if (result_char[0] == '0') {
        return &result_char[1];
    }

    return result_char;
}