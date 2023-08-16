from stack import Stack

def main(): 
    stack = Stack()

    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    
    assert 4 == stack.pop()
    assert 3 == stack.pop()
    assert 2 == stack.pop()
    assert 1 == stack.pop()
    assert None == stack.pop()


if __name__ == '__main__':
    print('testing python stack')
    main()
    print('all tests ok')
