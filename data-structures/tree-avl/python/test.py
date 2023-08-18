from avl import AVLTree

def main():
    avl = AVLTree()
    root = None
    nums = [33, 13, 52, 9, 21, 61, 8, 11, 12, 15, 15, 15, 23]
    for num in nums:
        root = avl.insert_node(root, num)

    avl.print_tree(root)
    
    root = avl.insert_node(root, 10)
    root = avl.insert_node(root, 2)
    root = avl.insert_node(root, 5)
    root = avl.insert_node(root, 7)

    print('------' * 11)
    avl.print_tree(root)

    root = avl.delete_node(root, 10)
    root = avl.delete_node(root, 2)
    root = avl.delete_node(root, 5)
    root = avl.delete_node(root, 7)

    print('------' * 11)
    avl.print_tree(root)

if __name__ == '__main__':
    main()
