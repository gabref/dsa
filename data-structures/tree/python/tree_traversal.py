
class Node:
    def __init__(self, data) -> None:
        self.left: Node | None = None
        self.right: Node | None = None
        self.data = data

def inorder(root: Node | None):
    if root:
        inorder(root.left)
        print(str(root.data) + ' -> ', end='')
        inorder(root.right)

def postorder(root: Node | None):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(str(root.data) + ' -> ', end='')

def preorder(root: Node | None):
    if root:
        print(str(root.data) + ' -> ', end='')
        preorder(root.left)
        preorder(root.right)

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print('\ninorder traversal: ', end='')
inorder(root)

print('\npostorder traversal: ', end='')
postorder(root)

print('\npreorder traversal: ', end='')
preorder(root)
