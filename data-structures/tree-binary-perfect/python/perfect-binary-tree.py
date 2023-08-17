
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.left: Node | None = None
        self.right: Node | None = None

def depth(node):
    d = 0
    while (node is not None):
        d += 1
        node = node.left
    return d

def is_perfect(root, d, level=0):

    # check if tree or subtree is empty
    if (root is None):
        return True

    # if the subtree ends here, are we in the most depth of the tree? if not, is not perfect
    if (root.left is None and root.right is None):
        return (d == level + 1)

    # if any of the childs is none and not the other, stop here and return false
    if (root.left is None or root.right is None):
        return False

    return (is_perfect(root.left, d, level + 1) and is_perfect(root.right, d, level + 1))


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

if (is_perfect(root, depth(root))): print('the tree is perfect')
else: print('the tree is NOT perfect')

root.left.left.left = Node(8)

if (is_perfect(root, depth(root))): print('the tree is perfect')
else: print('the tree is NOT perfect')
