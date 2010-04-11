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

  // Used to retrive the values from the stack
  int result;

  // Create a new stack
  Stack s;
  StackNew(&s, sizeof(int));

  // Counter for the for loops, must compile in C99 mode to allow initial declarations in for loops
  int i = 0;

  // Add values 0 - 99
  for(i; i < 100; i += 1)
  {
    StackPush(&s, &i);
  }

  // Pop the value 99
  StackPop(&s, &result);
  printf("top = %i\n", result);

  // Add values 200 - 299
  i = 200;
  for(i; i < 300; i += 1)
  {
    StackPush(&s, &i);
  }

  // Pop the values 299 - 200
  i = 0;
  for(i; i < 100; i += 1)
  {
    StackPop(&s, &result);
    printf("top = %i\n", result);
  }

  // Peek the value 98 three times
  StackPeek(&s, &result);
  printf("top = %i\n", result);

  StackPeek(&s, &result);
  printf("top = %i\n", result);

  StackPeek(&s, &result);
  printf("top = %i\n", result);

  // Pop all the remaining values
  while(s.size > 0)
  {
    StackPop(&s, &result);
    printf("top = %i\n", result);
  }

  // Free the memory allocated
  StackDestroy(&s);

  printf("Done!\n");

  return (EXIT_SUCCESS);
}

