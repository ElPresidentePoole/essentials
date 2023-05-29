#ifndef E_FOREACH_H_
#define E_FOREACH_H_

void e_array_for_each(void** array, int length, void (*callable)(void*));

#endif // E_FOREACH_H_
