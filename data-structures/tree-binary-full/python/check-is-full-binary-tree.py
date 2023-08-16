
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.left: Node | None = None
        self.right: Node | None = None

def isFullBinaryTree(root: Node):
    if root is None:
        return True

    if root.left is None and root.right is None:
        return True

    if root.left is not None and root.right is not None:
        return isFullBinaryTree(root.left) and isFullBinaryTree(root.right)

    return False

root = Node(1)
root.right = Node(3)
root.left = Node(2)

root.left.left = Node(4)
root.left.right = Node(5)

root.right.left = Node(6)
root.right.right = Node(7)

if isFullBinaryTree(root):
    print('is full binary tree')
else:
    print('is not')

root.left.left.left = Node(8)

if isFullBinaryTree(root):
    print('is full binary tree')
else:
    print('is not')
