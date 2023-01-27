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
#include <iostream>
#include <vector>

using namespace std;

const int TABLE_SIZE = 100;

struct Node {
    string key;
    int value;
    Node(string k, int v) : key(k), value(v) {}
};

class HashMap {
    vector<Node> table[TABLE_SIZE];

public:
    void put(string key, int value) {
        int slot = hash<string>()(key) % TABLE_SIZE;
        for (auto &entry : table[slot]) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
        }
        table[slot].push_back(Node(key, value));
    }

    int get(string key) {
        int slot = hash<string>()(key) % TABLE_SIZE;
        for (auto &entry : table[slot]) {
            if (entry.key == key) {
                return entry.value;
            }
        }
        return -1;
    }

    // handle collision cases
    void handle_collision(string key, int value) {
        int slot = hash<string>()(key) % TABLE_SIZE;
        int index = 0;
        for (auto &entry : table[slot]) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
            index++;
        }
        table[slot].insert(table[slot].begin() + index, Node(key, value));
    }
};

int main() {
    HashMap hm;

    hm.put("key1", 1);
    hm.put("key2", 2);
    hm.put("key3", 3);
    hm.put("key1", 4); // collision case
    hm.put("key1", 5); // handle collision

    cout << "value for key1: " << hm.get("key1") << endl;
    cout << "value for key2: " << hm.get("key2") << endl;
    cout << "value for key3: " << hm.get("key3") << endl;
    cout << "value for key4: " << hm.get("key4") << endl; // should print -1
    return 0;
}
