/*
put operation has an average time complexity of O(1)
worst-case time complexity of O(n), where n is the number of key-value pairs in the same slot.

This is due to the use of a hash function to calculate the slot for a given key, which has an average case of O(1)
worst case of O(n) if there is a collision and the data structure must handle it.

get operation also has an average time complexity of O(1) and worst-case time complexity of O(n),
as it also uses the hash function to calculate the slot for a given key, and then it must iterate through the key-value pairs
in that slot to find the one with the matching key.

The space complexity is O(n),
where n is the number of key-value pairs in the data structure.
This is due to the use of a hash table to store the key-value pairs,
where each slot in the table can potentially store multiple key-value pairs in the case of collisions.

It's worth noting that these complexities are based on the assumption that the hash function distributes the keys evenly across the slots in the table, which is true in most cases.
However, if the hash function is poorly designed, the time complexity can degrade to O(n) in the worst case, resulting in a data structure that performs poorly.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct hash_table_entry {
    char *key;
    int value;
    struct hash_table_entry *next;
};

struct hash_table {
    struct hash_table_entry **entries;
};

struct hash_table *create_hash_table() {
    struct hash_table *ht = (struct hash_table*)malloc(sizeof(struct hash_table));
    ht->entries = (struct hash_table_entry**)malloc(TABLE_SIZE * sizeof(struct hash_table_entry*));
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        ht->entries[i] = NULL;
    }
    return ht;
}

unsigned int hash(char *key) {
    unsigned int h = 0;
    int i;
    for (i = 0; key[i] != '\0'; i++) {
        h = h + key[i];
    }
    return h % TABLE_SIZE;
}

void put(struct hash_table *ht, char *key, int value) {
    unsigned int slot = hash(key);
    struct hash_table_entry *entry = (struct hash_table_entry*)malloc(sizeof(struct hash_table_entry));
    entry->key = key;
    entry->value = value;
    entry->next = ht->entries[slot];
    ht->entries[slot] = entry;
}

int get(struct hash_table *ht, char *key) {
    unsigned int slot = hash(key);
    struct hash_table_entry *entry = ht->entries[slot];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}

int main() {
    // Create Hash Table
    struct hash_table *ht = create_hash_table();

    // Place Elements
    put(ht, "key1", 1);
    put(ht, "key2", 2);
    put(ht, "key3", 3);

    // Get Elements
    printf("value for key1: %d\n", get(ht, "key1"));
    printf("value for key2: %d\n", get(ht, "key2"));
    printf("value for key3: %d\n", get(ht, "key3"));
    printf("value for key4: %d\n", get(ht, "key4")); // should print -1

    return 0;
}


