/*
 * A simple generic stack implementation in c
 *
 * Testing so the stack works.
 * 
 * Defines a new stack and pushes 100 integers to it 0-99
 * Pops the top and prints it 99
 * Pushes 100 integers to it 200-299
 * Pops 100 integers and prints them 299-200
 * Peeks three times and prints the value 98
 * Pop all elements
 * Free the memory
 *
 * File:   main.c
 * Author: Fredrik Wallgren <fredrik@wallgren.me>
 *
 * @license MIT
 */

#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

int main(int argc, char** argv)
{
  printf("Stack test\n");

  int result;

  Stack s;
  StackNew(&s, sizeof(int));

  int i = 0;
  
  for(i; i < 100; i += 1)
  {
    StackPush(&s, &i);
  }

  StackPop(&s, &result);
  printf("top = %i\n", result);

  i = 200;
  for(i; i < 300; i += 1)
  {
    StackPush(&s, &i);
  }

  i = 0;
  for(i; i < 100; i += 1)
  {
    StackPop(&s, &result);
    printf("top = %i\n", result);
  }

  StackPeek(&s, &result);
  printf("top = %i\n", result);

  StackPeek(&s, &result);
  printf("top = %i\n", result);

  StackPeek(&s, &result);
  printf("top = %i\n", result);

  while(s.size > 0)
  {
    StackPop(&s, &result);
    printf("top = %i\n", result);
  }

  StackDestroy(&s);

  printf("Done!\n");

  return (EXIT_SUCCESS);
}

