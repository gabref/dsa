from linked_list import LinkedList

def main():
    ll = LinkedList()
    
    ll.push_beg(3)
    ll.push_beg(2)
    ll.push_beg(1)
    ll.push_end(4)
    ll.push_end(5)
    ll.push_end(6)

    assert ll.get(2) == 3
    assert ll.get(5) == 6
    assert ll.get(6) == None

    assert 1 == ll.pop_beg()
    assert 6 == ll.pop_end()
    assert 2 == ll.pop_beg()
    assert 5 == ll.pop_end()

    assert ll.get(0) == 3
    assert ll.get(1) == 4

    assert 4 == ll.pop_end()
    assert 3 == ll.pop_end()
    assert None == ll.pop_end()
    assert None == ll.pop_beg()

if __name__ == '__main__':
    print('running tests')
    main()
    print('tests ok')
