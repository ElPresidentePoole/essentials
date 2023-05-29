#include "e_lists.h"
#include "e_foreach.h"
#include <stdlib.h>
#include <stdio.h>

void print_number(void* int_ptr) {
    printf("%d", *(int*)int_ptr);
}

int main(void) {
    //arraylist_t* list = e_arraylist_create(10);

    //e_arraylist_resize(list, 20);

    //e_arraylist_free(list);
    //
    int* array[5];
    for(int i = 0; i < 5; i++) {
        array[i] = malloc(sizeof(int));
        *array[i] = i;
    }
    e_array_for_each((void**)array, 5, &print_number);
    for(int i = 0; i < 5; i++) {
        free(array[i]);
    }

    return 0;
}
