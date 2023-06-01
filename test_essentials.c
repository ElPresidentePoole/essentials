#include <stdlib.h>
#include <stdio.h>

#include "e_new.h"
#include "e_lists.h"
#include "e_foreach.h"

void test_e_new() {
	int *i = e_new(int);
	*i = 6;
	printf("%d\n", *i);
	free(i);
}

void test_e_lists() {
	arraylist_t* al = e_arraylist_create(20);

	for(int i = 0; i < 20; i++) {
		al->data[i] = e_new(int);
		*(int*)al->data[i] = i;
	}

	printf("%d\n", e_arraylist_length(al));

	e_arraylist_resize(al, 40);

	for(int i = e_arraylist_length(al); i < 30; i++) {
		al->data[i] = e_new(int);
		*(int*)al->data[i] = i;
	}

	printf("%d\n", e_arraylist_length(al)); // 30

	e_arraylist_free(al);
}

void test_e_foreach() {
	void print_value(void* v) {
		printf("%d\n", *(int*)v);
	}

	int numbers[] = e_new(int[5]);
	unsigned int len = sizeof(numbers) / sizeof(int);
	e_foreach(numbers, len, (&print_value));
	free(numbers);
}

int main(void) {
	test_e_new();
	test_e_lists();
	// test_e_foreach(); // TODO

	return 0;
}
