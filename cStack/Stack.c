#include <stdlib.h>

#include <string.h>

#include "Stack.h"

void StackNew(Stack* s, int elemSize)
{
  s->allocatedSize = 16;
  s->size = 0;
  s->elemSize = elemSize;
  s->elements = malloc(s->allocatedSize * s->elemSize);
}

void StackDestroy(Stack* s)
{
  free(s->elements);
}

void StackPush(Stack* s, void* address)
{
  if (s->size == s->allocatedSize)
  {
    s->allocatedSize *= 2;
    s->elements = realloc(s->elements, s->allocatedSize * s->elemSize);
  }

  void* target = (char*) s->elements + s->size * s->elemSize;
  memcpy(target, address, s->elemSize);
  s->size += 1;
}

void StackPop(Stack* s, void* address)
{
  if (s->size > 0)
  {
    s->size -= 1;
    void* source = (char*) s->elements + s->size * s->elemSize;
    memcpy(address, source, s->elemSize);
  }
}

void StackPeek(Stack* s, void* address)
{
  if (s->size > 0)
  {
    void* source = (char*) s->elements + (s->size - 1) * s->elemSize;
    memcpy(address, source, s->elemSize);
  }
}
