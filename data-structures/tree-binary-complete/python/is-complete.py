
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.left: Node | None = None
        self.right: Node | None = None

def count_nodes(root):
    if root is None:
        return 0
    return (1 + count_nodes(root.left) + count_nodes(root.right))

def is_complete(root, index, numberNodes):
    if root is None:
        return True

    if index >= numberNodes:
        return False

    # give the child node with its index
    return (is_complete(root.left, 2 * index + 1, numberNodes) 
            and is_complete(root.right, 2 * index + 2, numberNodes))

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

node_count = count_nodes(root)

if is_complete(root, 0, node_count): print('the tree is complete binary tree')
else: print('the tree is NOT complete binary tree')

root.right.right.left = Node(8)

if is_complete(root, 0, node_count): print('the tree is complete binary tree')
else: print('the tree is NOT complete binary tree')
