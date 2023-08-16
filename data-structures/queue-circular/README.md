# Circular Queue

In a circular queue, the last element points to the first element making a circular link.

The main advantage of a circular queue over a simple queue is better memory utilization. If the last position is full and the first position is empty, we can insert an element in the first position. This action is not possible in a simple queue.

## Requirements

- [ ] enqueue(value) - adds value at position at tail
- [ ] dequeue() - returns value and removes least recently added (begin)
- [ ] empty
- [ ] print debug
- [ ] create queue
- [ ] destroy queue
- [ ] check address
