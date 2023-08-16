
class Node:
    def __init__(self, item):
        self.item = item
        self.next: Node | None = None

class LinkedList:
    def __init__(self):
        self.head = None

    def push_beg(self, data):
        new_node = Node(data)

        if (self.head == None):
            self.head = new_node
            return

        new_node.next = self.head 
        self.head = new_node

    def push_end(self, data):
        new_node = Node(data)

        if (self.head == None):
            self.head = new_node
            return

        current = self.head
        while (current.next != None):
            current = current.next
        current.next = new_node

    def pop_beg(self):
        if (self.head == None):
            return
        popped = self.head.item
        self.head = self.head.next
        return popped

    def pop_end(self):
        if (self.head is None):
            return None


        if (self.head.next is None):
            popped = self.head.item
            self.head = None
            return popped

        current = self.head
        while current.next.next is not None:
            current = current.next
        popped = current.next.item
        current.next = None
        return popped

    def get(self, index):
        if (self.head == None):
            return
        current = self.head
        i = 0
        while (current != None and i != index):
            current = current.next
            if (i > index):
                return None
            i = i + 1

        if (current):
            return current.item
        return None

    def print_linkedList(self):
        current = self.head
        while (current != None):
            print(str(current.item) + ' ->', end = ' ')
            current = current.next
        print(' NULL')
    
