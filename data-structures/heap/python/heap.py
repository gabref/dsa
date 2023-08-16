import math
from io import StringIO

class Heap():
    def __init__(self):
        self.heap = []

    def heapify(self, n, i):
        """
        Parameters
        ----------
        arr : list[int]
            The array representing the heap
        n : int
            Length of the array
        i : int
            Current non-leaf index
        """
        largest = i
        l = 2 * i + 1
        r = 2 * i + 2

        if l < n and self.heap[largest] < self.heap[l]:
            largest = l

        if r < n and self.heap[largest] < self.heap[r]:
            largest = r

        if largest != i:
            self.heap[i], self.heap[largest] = self.heap[largest], self.heap[i]
            self.heapify(n, largest)

    def insert(self, data):
        size = len(self.heap)
        if size == 0:
            self.heap.append(data)
        else:
            self.heap.append(data)
            # for i = size / 2 - 1; i >= 0; i--
            for i in range((size // 2) - 1, -1, -1):
                self.heapify(size, i)

    def delete_node(self, num):
        size = len(self.heap)
        i = 0
        for i in range(0, size):
            if num == self.heap[i]:
                break

        self.heap[i], self.heap[size - 1] = self.heap[size - 1], self.heap[i]

        self.heap.remove(num)

        for i in range ((len(self.heap) // 2) - 1, -1, -1):
            self.heapify(len(self.heap), i)

    def show_tree(self, total_width=20, fill=' '):
        """Pretty-print a tree.
        total_width depends on your input size"""
        output = StringIO()
        last_row = -1
        for i, n in enumerate(self.heap):
            if i:
                row = int(math.floor(math.log(i+1, 2)))
            else:
                row = 0
            if row != last_row:
                output.write('\n')
            columns = 2**row
            col_width = int(math.floor((total_width * 1.0) / columns))
            output.write(str(n).center(col_width, fill))
            last_row = row
        print (output.getvalue())
        print ('-' * total_width)
        return
