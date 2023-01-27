"""
This implementation uses a linked list to store the elements in the queue.

- enqueue() method adds an element to the end of the queue
- dequeue() method removes the element from the front of the queue
- is_empty() method checks if the queue is empty.

In this example, it enqueues three elements (1, 2, 3) and then dequeues them one by one, printing 1, 2, 3 respectively.
"""
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def is_empty(self):
        return self.head is None

    def enqueue(self, data):
        new_node = Node(data)
        if self.tail is None:
            self.head = self.tail = new_node
            return
        self.tail.next = new_node
        self.tail = new_node

    def dequeue(self):
        if self.is_empty():
            return None
        temp = self.head
        self.head = temp.next
        if(self.head is None):
            self.tail = None
        return temp.data

# Example usage
q = Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
print(q.dequeue()) # prints 1
print(q.dequeue()) # prints 2
print(q.dequeue()) # prints 3
