
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.left: Node | None = None
        self.right: Node | None = None

class BST:
    def __init__(self) -> None:
        self.root: Node | None = None

    def inorder(self):
        self.inorder_algorithm(self.root)
        print()

    def inorder_algorithm(self, root):
        if root is not None:

            self.inorder_algorithm(root.left)

            print(str(root.data) + ' -> ', end='')

            self.inorder_algorithm(root.right)

    def insert(self, data):
        self.root = self.insert_algorithm(self.root, data)


    def insert_algorithm(self, node: Node | None, data):
        # if tree is empty
        if node is None:
            return Node(data)

        # traverse the tree and find the right spot
        if data < node.data:
            node.left =  self.insert_algorithm(node.left, data)
        if data > node.data:
            node.right =  self.insert_algorithm(node.right, data)

        return node

    def minValueNode(self, node: Node | None) -> Node:
        current = node

        # find the leftmost leaf
        while(current.left is not None):
            current = current.left

        return current

    def delete(self, data_to_delete):
        self.root = self.delete_node_algorithm(self.root, data_to_delete)

    def delete_node_algorithm(self, root, data_to_delete):

        # return if tree is empty
        if root is None:
            return root

        # find the node to be deleted
        if data_to_delete < root.data:
            root.left = self.delete_node_algorithm(root.left, data_to_delete)
        elif data_to_delete > root.data:
            root.right = self.delete_node_algorithm(root.right, data_to_delete)
        else:
            # if the node is with only one child or no child
            if root.left is None:
                temp = root.right
                root = None
                return temp
            if root.right is None:
                temp = root.left
                root = None
                return temp

            # if the node has two children
            # place the inorder successor in position of the node to be deleted
            temp = self.minValueNode(root.right)

            root.data = temp.data

            # delete the inorder successor
            root.right = self.delete_node_algorithm(root.right, temp.data)

        return root
