"""
Python does not have a built-in array data structure like C++,
but it has a list class that provides similar functionality

This class creates an empty list in the constructor, and then implements the:
push_back - appends an element to the list and increments the length
pop_back - deletes the last element of the list and decrements the length
size - returns the current size of the list
__getitem__ - allows access to the element at a given index using the [] operator like a built-in array


Python lists internally handle all the resizing and memory management,
so it is not necessary to implement a resize method like in the C++ example.
"""
class MyArray:
    def __init__(self):
        self.data = []
        self.len = 0

    def push_back(self, x):
        self.data.append(x)
        self.len += 1

    def pop_back(self):
        if self.len > 0:
            self.len -= 1
            self.data.pop()

    def __getitem__(self, idx):
        return self.data[idx]

    def size(self):
        return self.len

# Simple Implementation
arr = MyArray()

# Add elements
arr.push_back(1)
arr.push_back(2)
arr.push_back(3)

for item in arr:
    print(item)

# Pop an element
arr.pop_back()
for item in arr:
    print(item)
