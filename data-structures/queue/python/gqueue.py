
class Queue:

    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if len(self.queue) == 0:
            return
        return self.queue.pop(0)

    def print_queue(self):
        print(self.queue)
