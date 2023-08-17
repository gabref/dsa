
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.left: Node | None = None
        self.right: Node | None = None

class Height:
    def __init__(self) -> None:
        self.height = 0

def is_height_balanced(root, height: Height):
    left_height = Height()
    right_height = Height()

    if root is None:
        return True

    l = is_height_balanced(root.left, left_height)
    r = is_height_balanced(root.right, right_height)

    # left_height > right_height ? left_height : right_height
    height.height = max(left_height.height, right_height.height) + 1

    # if ((left_height - right_height >= 2) || (right_height - left_height >= 2))
    #       return 0;
    # else return l && r;
    if abs(left_height.height - right_height.height) <= 1:
        return l and r

    return False


height = Height()
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

if is_height_balanced(root, height): print('tree is balanced')
else: print('tree is NOT balanced')

root.left.left.left = Node(12)
root.left.left.left.left = Node(12)

if is_height_balanced(root, height): print('tree is balanced')
else: print('tree is NOT balanced')
