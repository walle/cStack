/*
 * A simple generic stack implementation in c
 *
 * The implementation of the stack's methods
 *
 * File:   Stack.c
 * Author: Fredrik Wallgren <fredrik@wallgren.me>
 *
 * @license MIT
 */

#include <stdlib.h>
#include <string.h>

#include "Stack.h"

void StackNew(Stack* s, int elemSize)
{
  s->allocatedSize = 16; // Default to a stack that is 16 elements high
  s->size = 0;
  s->elemSize = elemSize;
  s->elements = malloc(s->allocatedSize * s->elemSize); // Allocate the needed memory
}

void StackDestroy(Stack* s)
{
  free(s->elements); // Free the allocated memory
}

void StackPush(Stack* s, void* valueAddress)
{
  if (s->size == s->allocatedSize)
  {
    s->allocatedSize *= 2; // Use a doubling strategy. Every time the stack is too small, double it's size
    s->elements = realloc(s->elements, s->allocatedSize * s->elemSize); // Reallocate the memory to the new size
  }

  void* target = (char*) s->elements + s->size * s->elemSize; // Find the memory segment where to insert the new data
  memcpy(target, valueAddress, s->elemSize); // Copy the data from the valueAddress to target
  s->size += 1;
}

void StackPop(Stack* s, void* returnAddress)
{
  if (s->size > 0)
  {
    s->size -= 1; // This "removes" the element, it will be overwritten the next time push is called
    void* source = (char*) s->elements + s->size * s->elemSize; // Find the memory segment where to fetch the data from
    memcpy(returnAddress, source, s->elemSize); // Copy the data to the returnAddress
  }
  // Else error!
}

void StackPeek(Stack* s, void* returnAddress)
{
  if (s->size > 0)
  {
    void* source = (char*) s->elements + (s->size - 1) * s->elemSize; // Find the memory segment where to fetch the data from
    memcpy(returnAddress, source, s->elemSize); // Copy the data to the returnAddress
  }
  // Else error!
}
