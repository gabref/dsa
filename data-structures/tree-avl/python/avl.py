
class TreeNode:
    def __init__(self, data) -> None:
        self.data = data
        self.left: TreeNode | None = None
        self.right: TreeNode | None = None
        self.height = 1
        self.children = []

class AVLTree:

    def get_height(self, root: TreeNode | None):
        if not root:
            return 0
        return root.height

    def get_balance(self, root: TreeNode | None):
        if not root:
            return 0
        return self.get_height(root.left) - self.get_height(root.right)

    def get_min_value_node(self, root: TreeNode):
        if not root or not root.left:
            return root
        return self.get_min_value_node(root.left)

    def pre_order(self, root: TreeNode | None):
        if not root:
            return
        print('{0} '.format(root.data), end='')
        self.pre_order(root.left)
        self.pre_order(root.right)

    def get_col(self, h):
        if h == 1:
            return 1
        return self.get_col(h - 1) + self.get_col(h - 1) + 1

    def print_tree_util(self, M, root, col, row, height):
        if root is None:
            return
        M[row][col] = root.data
        self.print_tree_util(M, root.left, col - pow(2, height - 2), row + 1, height - 1)
        self.print_tree_util(M, root.right, col + pow(2, height - 2), row + 1, height - 1)

    def print_tree(self, root: TreeNode):
        h = self.get_height(root)
        col = self.get_col(h)
        M = [[0 for _ in range(col)] for __ in range(h)]
        self.print_tree_util(M, root, col // 2, 0, h)
        for i in M:
            for j in i:
                if j == 0:
                    print(' ', end=' ')
                else:
                    print(j, end=' ')
            print('')

    def left_rotate(self, z: TreeNode):
        y = z.right
        t2 = y.left
        y.left = z
        z.right = t2
        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        return y

    def right_rotate(self, z: TreeNode):
        y = z.left
        t2 = y.right
        y.right = z
        z.left = t2
        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        return y

    def insert_node(self, root: TreeNode | None, data):
        
        # find location to insert the node
        if not root:
            return TreeNode(data)
        elif data < root.data:
            root.left = self.insert_node(root.left, data)
        elif data > root.data:
            root.right = self.insert_node(root.right, data)

        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))

        # update the balance factor and balance the tree
        balanceFactor = self.get_balance(root)
        if balanceFactor > 1:
            if data < root.left.data:
                return self.right_rotate(root)
            else:
                root.left = self.left_rotate(root.left)
                return self.right_rotate(root)

        if balanceFactor < -1:
            if data > root.right.data:
                return self.left_rotate(root)
            else:
                root.right = self.right_rotate(root.right)
                return self.left_rotate(root)

        return root

    def delete_node(self, root, data):

        # find the node to be deleted and remove it
        if not root:
            return root

        elif data < root.data:
            root.left = self.delete_node(root.left, data)
        elif data > root.data:
            root.right = self.delete_node(root.right, data)
        else:
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left 
                root = None
                return temp
            temp = self.get_min_value_node(root.right)
            root.data = temp.data
            root.right = self.delete_node(root.right, temp.data)

        # update the balance factor of nodes
        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))
        balanceFactor = self.get_balance(root)

        # balance the tree
        if balanceFactor > 1:
            if self.get_balance(root.left) >= 0:
                return self.right_rotate(root)
            else:
                root.left = self.left_rotate(root.left)
                return self.right_rotate(root)
        if balanceFactor < -1:
            if self.get_balance(root.right) <= 0:
                return self.left_rotate(root)
            else:
                root.right = self.right_rotate(root.right)
                return self.left_rotate(root)
        return root

