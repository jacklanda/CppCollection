#include <stdio.h>

#include "hash_table.h"

int main() {
    ht_hash_table* ht = ht_new();
    ht_insert(ht, "jacklanda", "bad guy");
    printf("%s : %s\n", "jacklanda", ht_search(ht, "jacklanda"));
    return 0;
}
