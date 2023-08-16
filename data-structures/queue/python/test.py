from gqueue import Queue

def main():
    queue = Queue()

    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    queue.enqueue(4)
    queue.enqueue(5)

    assert 1 == queue.dequeue()
    assert 2 == queue.dequeue()
    assert 3 == queue.dequeue()
    assert 4 == queue.dequeue()
    assert 5 == queue.dequeue()
    assert None == queue.dequeue()
    
if __name__ == '__main__':
    print('running tests')
    main()
    print('\nall tests ok')
