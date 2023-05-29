#include <stdio.h>
#include <stdlib.h>
#include "e_lists.h"

arraylist_t* e_arraylist_create(unsigned int size) {
    arraylist_t* al = malloc(sizeof(arraylist_t));
    al->size = size; // size being how many blocks of memory we allocated
    al->data = malloc(sizeof(void*) * size);
    for(unsigned int i = 0; i < size; i++) {
        al->data[i] = NULL;
    }
    return al;
}

void e_arraylist_free(arraylist_t* al) {
    free(al->data);
    free(al);
}

void e_arraylist_resize(arraylist_t* al, unsigned int new_size) {
    void** new_data = realloc(al->data, sizeof(void*) * new_size);
    if(new_data == NULL) {
        printf("Failed to allocate %u of memory for arraylist_t\n", new_size * sizeof(void*));
        e_arraylist_free(al);
        exit(1);
    } else {
        al->data = new_data;
        al->size = new_size;
        for(unsigned int i = 0; i < al->size; i++) {
            al->data[i] = NULL;
        }
    }
}

unsigned int e_arraylist_length(arraylist_t* al) {
    unsigned int len = 0;
    for(unsigned int i = 0; i < al->size; i++) {
        if(al->data[i] != NULL) {
            len++;
        } else {
            return len;
        }
    }
}
