# Definition for a binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# Recursive function to traverse the tree in DFS (in-order)
def DFS(root):
    if root:
        DFS(root.left)
        print(root.val, end=' ')
        DFS(root.right)


if __name__ == '__main__':
    # Test example
    # Construct the following binary search tree:
    #      4
    #     / \
    #    2   5
    #   / \
    #  1   3
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)

    # Call DFS function to traverse the tree
    DFS(root)
    print()
