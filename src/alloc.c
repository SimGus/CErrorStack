#include <stdlib.h>

#include "alloc.h"

void del(void* pointer)
{
   #if SAFE == 1
      if (pointer == NULL)
         fprintf(stderr, "ERROR: %s\n", "Tried to free an already freed pointer.");
   #endif

   free(pointer);
   pointer = NULL;
}
