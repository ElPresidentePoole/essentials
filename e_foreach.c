#include "e_foreach.h"

void e_array_for_each(void** array, int length, void (*callable)(void*)) {
    for(unsigned int i = 0; i < length; i++) {
        (*callable)(array[i]);
    }
}
