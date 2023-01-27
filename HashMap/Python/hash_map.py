"""
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
"""
class HashMap:
    def __init__(self):
        self.map = {}

    def put(self, key, value):
        self.map[key] = value

    def get(self, key):
        if key in self.map:
            return self.map[key]
        else:
            return -1

if __name__ == "__main__":
    # Create elements
    hm = HashMap()

    # Insert elements
    hm.put("key1", 1)
    hm.put("key2", 2)
    hm.put("key3", 3)
    hm.put("key1", 4) # collision case

    # Get Elements
    print(hm.get("key1")) # should print 4
    print(hm.get("key2")) # should print 2
    print(hm.get("key3")) # should print 3
    print(hm.get("key4")) # should print None
