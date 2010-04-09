/* 
 * File:   main.c
 * Author: walle
 *
 * Created on April 9, 2010, 7:44 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

/*
 * 
 */
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

  printf("Done!\n");

  return (EXIT_SUCCESS);
}

