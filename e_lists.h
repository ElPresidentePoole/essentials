#ifndef E_LISTS_H_
#define E_LISTS_H_

typedef struct {
    unsigned int size;
    void** data;
} arraylist_t;

arraylist_t* e_arraylist_create(unsigned int length);
void e_arraylist_free(arraylist_t* al);
void e_arraylist_resize(arraylist_t* al, unsigned int new_length);
unsigned int e_arraylist_length(arraylist_t* al);

#endif // E_LISTS_H_
