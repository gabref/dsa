# Stack implementation in python

class Stack:
    def __init__(self):
        self.stack = []

    def check_empty(self):
        return len(self.stack) == 0

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if (self.check_empty()):
            return
        return self.stack.pop()

    def print_stack(self):
        for e in self.stack:
            print(str(e) + ' ')
        print('end')
