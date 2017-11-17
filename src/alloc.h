#ifndef _CERRORSTACK_ALLOC_H_
#define _CERRORSTACK_ALLOC_H_

/*
 * Safely frees pointers by setting them to $NULL when they've been freed
 * If $SAFE is true, checks if the pointer has already been freed
 * before trying to free it
 * $SAFE is defined in the $defines.h file
 */
void del(void* pointer);

#endif //_CERRORSTACK_ALLOC_H_
