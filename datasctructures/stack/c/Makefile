files := main.c test.c
stack_array := $(files) stack-array.c
stack_linkedlist := $(files) stack-linkedlist.c
executable := main

linkedlist: $(stack_linkedlist)
	gcc $(stack_linkedlist) -o $(executable) -DLINKEDLIST_IMPLEMENTATION
	./$(executable)

array: $(stack_array)
	gcc $(stack_array) -o $(executable) -DARRAY_IMPLEMENTATION
	./$(executable)

clean:
	rm -f $(executable)
