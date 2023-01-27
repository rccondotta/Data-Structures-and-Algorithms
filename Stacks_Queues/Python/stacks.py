"""
this implementation has a time complexity of O(1) for push, pop and top operations
if you use a linked list or dynamic array the time complexity will be O(n)
"""
class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()

    def peek(self):
        if not self.is_empty():
            return self.items[-1]

    def is_empty(self):
        return len(self.items) == 0

stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
print(stack.peek()) # Output: 3
stack.pop()
print(stack.peek()) # Output: 2
stack.pop()
print(stack.peek()) # Output: 1
stack.pop()
print(stack.is_empty()) # Output: True
