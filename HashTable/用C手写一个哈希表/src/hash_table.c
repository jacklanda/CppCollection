#include "hash_table.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

static ht_item HT_DELETED_ITEM = {NULL, NULL};

static ht_item* ht_new_item(const char* k, const char* v) {
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);

    return i;
}

ht_hash_table* ht_new() {
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));

    ht->size = 53;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));

    return ht;
}

static void ht_del_item(ht_item* i) {
    free(i->key);
    free(i->value);
    free(i);
}

void ht_del_hash_table(ht_hash_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        ht_item* item = ht->items[i];
        if (!item) ht_del_item(item);
    }
    free(ht->items);
    free(ht);
}

/* 传入一个ASCII字符串，一个大于128的素数，以及一个求余用的整型m
 * 使用以上三个参数进行运算，最后返回一个哈希值 */
static int ht_hash(const char* s, const int a, const int m) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long)pow(a, len_s - (i + 1)) * s[i];
        hash %= m;
    }
    return (int)hash;
}

static int ht_get_hash(const char* s, const int num_buckets,
                       const int attempt) {
    const int hash_a = ht_hash(s, 153, num_buckets);
    const int hash_b = ht_hash(s, 147, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

void ht_insert(ht_hash_table* ht, const char* key, const char* value) {
    ht_item* item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, ht->size, 0);
    ht_item* cur_item = ht->items[index];
    int i = 1;
    while (cur_item && cur_item != &HT_DELETED_ITEM) {
        if (strcmp(cur_item->key, key) == 0) {
            ht_del_item(cur_item);
            ht->items[index] = item;
            return;
        }
        index = ht_get_hash(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    }
    ht->items[index] = item;
    ht->count++;
}

char* ht_search(ht_hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* cur_item = ht->items[index];
    int i = 1;
    while (cur_item) {
        if (cur_item != &HT_DELETED_ITEM)
            if (strcmp(cur_item->key, key) == 0) return cur_item->value;
        index = ht_get_hash(key, ht->size, i);
        cur_item = ht->items[index];
        i += 1;
    }
    return NULL;
}

void ht_delete(ht_hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item) {
        if (item != &HT_DELETED_ITEM) {
            if (strcmp(item->key, key) == 0) {
                ht_del_item(item);
                ht->items[index] = &HT_DELETED_ITEM;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    ht->count--;
}
