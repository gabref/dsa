from heap import Heap

def main():
    heap = Heap()

    heap.insert(3)
    heap.insert(4)
    heap.insert(9)
    heap.insert(5)
    heap.insert(2)
    heap.insert(11)
    heap.insert(15)
    heap.insert(0)

    print(str(heap.heap))
    heap.show_tree()

    heap.delete_node(4)
    heap.delete_node(15)
    heap.delete_node(9)

    print(str(heap.heap))
    heap.show_tree()

if __name__ == '__main__':
    print('running tests')
    main()
    print('tests ok')
