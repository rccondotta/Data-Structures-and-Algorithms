# structure for a node of the binary tree
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# create a new node with the given data
def newNode(data):
    node = Node(data)
    return node

# perform inorder search
def inorder(root):
    if root is None:
        return
    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)

# perform preorder search
def preorder(root):
    if root is None:
        return
    print(root.data, end=" ")
    preorder(root.left)
    preorder(root.right)

# perform postorder search
def postorder(root):
    if root is None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.data, end=" ")

# test the binary tree search functions
if __name__ == '__main__':
    root = newNode(1)
    root.left = newNode(2)
    root.right = newNode(3)
    root.left.left = newNode(4)
    root.left.right = newNode(5)

    print("Inorder search:", end=" ")
    inorder(root)
    print("")

    print("Preorder search:", end=" ")
    preorder(root)
    print("")

    print("Postorder search:", end=" ")
    postorder(root)
    print("")
