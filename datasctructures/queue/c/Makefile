files := main.c test.c
queue_array := $(files) queue-array.c
queue_linkedlist := $(files) queue-linkedlist.c
executable := main

linkedlist: $(queue_linkedlist)
	gcc $(queue_linkedlist) -o $(executable) -DLINKEDLIST_IMPLEMENTATION
	./$(executable)

array: $(queue_array)
	gcc $(queue_array) -o $(executable) -DARRAY_IMPLEMENTATION
	./$(executable)

clean:
	rm -f $(executable)
