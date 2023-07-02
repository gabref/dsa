# Linked List

## Requirements

[] size() - number of items
[] is_empty()
[] at(index) - returns item at given index, blows up if index out of bounds
[] push_begin(item)
[] push_end(item)
[] pop_begin()
[] pop_end()
[] get_begin() - get first value
[] get_end() - get last value
[] insert(index, item) - insert item at index
[] delete(index) - delete item at index
[] reverse() - reverses the list
[] remove(item) - looks for value and removes index first occurence
[] find (item) - looks for value and returns first index with that value, -1 if not found

## Implementation Logic

* new()
    * alloc memory for list
    * point stuff to null (head, tail)

* destroy()
    * create temp / current representing head
    * loop and with temp free memory of all nodes
    * after free the remaining variables

* size()
    * loop through list and increment size variable

* push_begin(value)
    * current = head
    * alloc for new node (always check for null)
    * define data and next as head
    * made that the new head
    * define tail with you want

* push_end(value)
    * allocate node
    * define data and next as NULL
    * if list empty, head and tail == node
    * else, tail -> next == node and tail == node

* print_debug
    * create current
    * print head, tail, and items

* empty()
    * return boolean head == NULL

* peek_begin()
    * check if empty, if empty exit failure
    * else return data at begin

* peek_end()
    * check if exists, if not, exit failure
    * return value at end (tail)

* pop_begin()
    * if empty, exit failure
    * else, create temp == head, make head == next
    * if tail == temp, tail == head
    * free temp

* pop_end()
    * if empty exit failure
    * if head == tail, free head and tail and point both to NULL
    * else make penultimate points to NULL, and free last

* insert(index, value)
    * go til index, check if index is out of bounds, exit if it is
    * create node and insert it, check if is_empty

* at(index)
    * go til index with temp / current
    * check if not out of bounds, exit if it is
    * return data

* delete(index)
    * check if list is empty, then it cannot delete nothing, exit with failure
    * go til index with temp and keep last also
    * check if not out of bounds
    * if head or not, reassing pointers to delete
    * free memory of deleted

* reverse()

* remove(value)
    * find value and remove node

### Implementation Utils

* check_address(void *p)
    * check if p NULL
    * exit failure if it is
