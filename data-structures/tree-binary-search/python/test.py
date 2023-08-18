
from bst import BST

def main():
    bst = BST()

    bst.insert(1)
    bst.insert(3)
    bst.insert(5)
    bst.insert(7)
    bst.insert(9)

    bst.inorder()

    bst.insert(5)

    bst.inorder()

    bst.delete(2)
    bst.delete(3)
    bst.delete(9)

    bst.inorder()

if __name__ == '__main__':
    print('running tests\n')
    main()
    print('\n\ntests ok')
