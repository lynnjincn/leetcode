#define HASH_TABLE_SIZE 1024
#define MAX_RESULT_SIZE 256
#define TRUE 1
#define FALSE 0

typedef struct hash_item_s {
    char *words;               // word本体
    int count;                 // 在words中出现的次数
    int mark_count;            // 在s滑窗中出现的次数
    struct hash_item_s *next;  // 哈希逃生链表
} HASH_TABLE_ITEM_S;

typedef enum {
    INSERT_NEW = 0,
    INSERT_CONFLICT = 1,
} INSERT_TYPE;

HASH_TABLE_ITEM_S **creat_hash_table(int hash_size)
{
    HASH_TABLE_ITEM_S **hash_table = (HASH_TABLE_ITEM_S **)malloc(sizeof(HASH_TABLE_ITEM_S *) * hash_size);
    if (hash_table == NULL) {
        return NULL;
    }

    memset(hash_table, 0, sizeof(HASH_TABLE_ITEM_S *) * hash_size);

    return hash_table;
}

int get_hash_index(char *words, int len, int hash_size)
{
    int i;
    unsigned int temp_hash_value = 5381;

    for (i = 0; i < len; i++) {
        temp_hash_value += (temp_hash_value << 5) + words[i];
    }

    return temp_hash_value % hash_size;
}

void insert_hash_item(HASH_TABLE_ITEM_S **hash_table, int hash_index, char *word, int word_len)
{
    HASH_TABLE_ITEM_S *temp_item = NULL;
    INSERT_TYPE insert_type;

    if (hash_table[hash_index] != NULL) {
        // 输入数据重复，计数增加
        if (memcmp(hash_table[hash_index]->words, word, word_len) == 0) {
            hash_table[hash_index]->count++;
            return;
        } else {
            // hash冲突
            insert_type = INSERT_CONFLICT;
        }
    } else {
        // 插入新节点
        insert_type = INSERT_NEW;
    }

    temp_item = (HASH_TABLE_ITEM_S *)malloc(sizeof(HASH_TABLE_ITEM_S));
    temp_item = (HASH_TABLE_ITEM_S *)malloc(sizeof(HASH_TABLE_ITEM_S));
    temp_item->words = (char *)malloc(sizeof(char) * word_len);
    temp_item->next = NULL;
    temp_item->count = 1;
    temp_item->mark_count = 0;
    memcpy(temp_item->words, word, word_len);

    if (insert_type == INSERT_NEW) {
        hash_table[hash_index] = temp_item;
    } else {
        hash_table[hash_index]->next = temp_item;
    }
}

void restore_hash_table(HASH_TABLE_ITEM_S **hash_table, int hash_table_size)
{
    int i;
    HASH_TABLE_ITEM_S *hash_item;

    for (i = 0; i < hash_table_size; i++) {
        hash_item = hash_table[i];
        if (hash_item == NULL) {
            continue;
        } else {
            while (hash_item != NULL) {
                hash_item->mark_count = 0;
                hash_item = hash_item->next;
            }
        }
    }
}

int check_hash_table(HASH_TABLE_ITEM_S **hash_table, int hash_table_size)
{
    int i;
    HASH_TABLE_ITEM_S *temp_hash_item;

    for (i = 0; i < hash_table_size; i++) {
        temp_hash_item = hash_table[i];
        while (temp_hash_item != NULL) {
            if (temp_hash_item->count != temp_hash_item->mark_count) {
                return FALSE;
            }

            temp_hash_item = temp_hash_item->next;
        }
    }

    return TRUE;
}

int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    if ((s == NULL) || (words == NULL) || (wordsSize == 0)) {
        *returnSize = 0;
        return s;
    }

    int i, j, hash_index;
    int word_len = strlen(words[0]);
    int s_len = strlen(s);
    int cmp_len = word_len * wordsSize;
    int *result;
    HASH_TABLE_ITEM_S **hash_table;
    HASH_TABLE_ITEM_S *hash_item;

    *returnSize = 0;

    result = (int *)malloc(sizeof(int) * MAX_RESULT_SIZE);
    hash_table = creat_hash_table(HASH_TABLE_SIZE);
    if ((result == NULL) || (hash_table == NULL)) {
        return s;
    }

    // 初始化hash表
    for (i = 0; i < wordsSize; i++) {
        hash_index = get_hash_index(words[i], word_len, HASH_TABLE_SIZE);
        insert_hash_item(hash_table, hash_index, words[i], word_len);
    }

    for (i = 0; i <= s_len - cmp_len; i++) {
        for (j = 0; j < wordsSize; j++) {
            hash_index = get_hash_index(s + i + j * word_len, word_len, HASH_TABLE_SIZE);
            hash_item = hash_table[hash_index];
            while (hash_item != NULL) {
                // 遍历hash链表，精确判断与其中某个节点对应
                if (memcmp(hash_item->words, s + i + j * word_len, word_len) == 0) {
                    hash_item->mark_count++;
                    break;
                }

                hash_item = hash_item->next;
            }
        }

        if (check_hash_table(hash_table, HASH_TABLE_SIZE) == TRUE) {
            result[(*returnSize)] = i;
            (*returnSize)++;
        }

        restore_hash_table(hash_table, HASH_TABLE_SIZE);
    }

    return result;
}