class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def reverse(self):
        current = self.head
        prev = None
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev

def test_reverse():
    # Create a linked list with 3 nodes
    ll = LinkedList()
    ll.head = Node(1)
    second = Node(2)
    third = Node(3)
    ll.head.next = second
    second.next = third

    # Print the original list
    current = ll.head
    print("Original List: ", end='')
    while current:
        print(current.data, end=' ')
        current = current.next
    print()

    # Reverse the list
    ll.reverse()

    # Print the reversed list
    current = ll.head
    print("Reversed List: ", end='')
    while current:
        print(current.data, end=' ')
        current = current.next
    print()

test_reverse()
