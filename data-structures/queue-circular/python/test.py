from circular_queue import MyCircularQueue

def main():
    cqueue = MyCircularQueue(5)

    cqueue.enqueue(1)
    cqueue.enqueue(2)
    cqueue.enqueue(3)
    cqueue.enqueue(4)
    cqueue.enqueue(5)

    cqueue.dequeue()
    cqueue.dequeue()
    cqueue.dequeue()

    cqueue.enqueue(6)
    cqueue.enqueue(7)
    cqueue.enqueue(8)

    assert 4 == cqueue.dequeue()
    assert 5 == cqueue.dequeue()
    assert 6 == cqueue.dequeue()
    assert 7 == cqueue.dequeue()
    assert 8 == cqueue.dequeue()
    assert None == cqueue.dequeue()

if __name__ == '__main__':
    print('running tests')
    main()
    print('\nall tests ok')
