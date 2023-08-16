
class MyCircularQueue():
    
    def __init__(self, k):
        self.k = k
        self.queue = [None] * k
        self.head = self.tail = -1

    def enqueue(self, data):
        # check if the queue is full
        if ((self.tail + 1) % self.k == self.head):
            print('The circular queue is full\n')

        # first element
        elif (self.head == -1):
            self.head = 0
            self.tail = 0
            self.queue[self.tail] = data
        else:
            self.tail = (self.tail + 1) % self.k
            self.queue[self.tail] = data

    def dequeue(self):
        # check if empty
        if (self.head == -1):
            print('the circular queue is empty\n')

        # check if only 1 element
        elif (self.head == self.tail):
            temp = self.queue[self.head]
            self.head = -1
            self.tail = -1
            return temp

        else:
            temp = self.queue[self.head]
            self.head = (self.head + 1) % self.k
            return temp

    def print_queue(self):
        if (self.head == -1):
            print('No element in the circular queue at the moment\n')
        elif (self.tail >= self.head):
            for i in range(self.head, self.tail + 1):
                print(self.queue[i], end = ' ')
            print()
        else:
            for i in range(self.head, self.k):
                print(self.queue[i], end=' ')
            for i in range(0, self.tail + 1):
                print(self.queue[i], end=' ')
            print()
