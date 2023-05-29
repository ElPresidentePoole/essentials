HEADERS = e_lists.h e_foreach.h

default: test_essentials

e_foreach.o: e_foreach.c $(HEADERS)
	gcc -c e_foreach.c -o e_foreach.o

e_lists.o: e_lists.c $(HEADERS)
	gcc -c e_lists.c -o e_lists.o

test_essentials.o: test_essentials.c $(HEADERS)
	gcc -c test_essentials.c -o test_essentials.o

test_essentials: test_essentials.o e_lists.o e_foreach.o
	gcc test_essentials.o e_lists.o e_foreach.o -o test_essentials.exe

clean:
	-rm -f e_lists.o
	-rm -f e_foreach.o
	-rm -f test_essentials.o
	-rm -f test_essentials
