from b_tree import BTree

def main():
    b = BTree(3)

    for i in range(10):
        b.insert((i, 2 * i))

    b.print_tree(b.root)

    if b.search_key(8) is not None:
        print('\nFound')
    else:
        print('\nNot found')

    b.delete(b.root, (8,))
    print('\n')
    b.print_tree(b.root)

if __name__ == '__main__':
    main()
