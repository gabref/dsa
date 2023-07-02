# Arrays

## Requirements
Mutable vector with automatic resizing.

- [ ] arrays and pointers, and pointer math to jump to an index instead of using indexing
- [ ] new raw data array with allocated memory
    * - [ ] start with 16, or if starting number is greater, use power of 2 - 16, 32, ...
- [ ] size() - number of items
- [ ] capacity() - nuber of items it can hold
- [ ] is_empty()
- [ ] at(index) - returns item at given index, blows up if index out of bounds
- [ ] push(item)
- [ ] insert(index, item) - insedrt item at index, shifts that index's value and treialing element ot the right
- [ ] prepend (item) - can use insert above at index 0
- [ ] pop() - remove from end, return value
- [ ] delete(index) - delete item at index, shifting all trailing element left
- [ ] remove(item) - looks for value and removes index holding it (even multiple places)
- [ ] find (item) - looks for value and returns first index with that value, -1 if not found
- [ ] resize(new_capacity) // private
    * - [ ] when you reach capacity, resize to double the size
    * - [ ] when popping an item, if size is 1/4 of capacity, resize to half

- [ ] Time
    * - [ ] O(1) to add/remove at end, index or update
    * - [ ] O(n) to insert, remove elsewhere
- [ ] Space
    * - [ ] contiguous in memory, so proximity helps performance
    * - [ ] space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)

## Implementation Logic

* new(capacity)
    * determine capacity
    * allocates memory
    * define values (size, capacity, data)

* size()
    * return size

* capacity()
    * return capacity

* is_empty()
    * returns true or false

* destroy
    * free data and pointer of array

* push(item)
    * resize_for_size, will resize if needed
    * using pointer arithmetic, define item as last in array
    * increment size

* print()
    * print size, capacity and items

* at(index)
    * check if index is valid (not less than 0 and not out of bouds)
    * return value at index

* insert(index, value)
    * check if index is valid
    * resize_for_size, will resize if needed
    * shift items to right (memmove or loop)
    * insert item
    * increment size

* prepend(value)
    * insert at 0

* pop()
    * if size 0, exit failure
    * get popped value 
    * resize_for_size, will resize if needed
    * decrement size

* delete(index)
    * check if index is valid
    * shift items to left (memmove or loop)
    * resize_for_size, will resize if needed
    * decrement size  

* remove(value)
    * loop through all data
    * if value at index = value, delete at index, decrement i to recheck the index that was deleted

* find(value)
    * found index = -1
    * loop through all data
    * if value at index = value, return i

### Implementation Utils

* determine_capacity(capacity)
    * if capacity less than minCapacity (1) exit failure
    * make capacity bigger by power of 2 and return result

* upsize()
    * from current capacity, determine new bigger capacity
    * reallocate data to new_capacity (check for null)
    * reassing new_data and capacity

* downsize()
    * from current capacity, determine new smaller capacity
    * if new_capacity is different than old, reallocate data
    * reassing new_data and capacity

* resize_for_size(candidate_size)
    * if growing, upsize
    * if shrinking, downsize
    * if equal to current size, do nothing

* check_address(void *p)
    * check if p == NULL
    * if it is, print and exit failure
