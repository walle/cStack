/*
 * A simple generic stack implementation in c
 *
 * The definition of the stack and it's methods
 *
 * File:   Stack.h
 * Author: Fredrik Wallgren <fredrik@wallgren.me>
 *
 * @license MIT
 */

#ifndef _STACK_H
#define	_STACK_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        int allocatedSize;
        int size;
        int elemSize;
        void* elements;
    } Stack;

    /*
     * The "Constructor" allocates a new stack
     */
    void StackNew(Stack* s, int elemSize);

    /*
     * The "Destructor" deallocates a allocated stack
     */
    void StackDestroy(Stack* s);

    /*
     * Used to add a value to the stack
     * Requires the data that valueAddress is of the same size as elemSize that was passed to StackNew
     * otherwise funky stuff will happen.
     * If you give the StackNew function sizeof(int) valueAddress should point to an int.
     */
    void StackPush(Stack* s, void* valueAddress);

    /*
     * Used to retrive a value from the stack and removing it
     * The data at returnAddress is populated by the data at the top of the stack
     *
     * Requires the data that valueAddress is of the same size as elemSize that was passed to StackNew
     * otherwise funky stuff will happen.
     * If you give the StackNew function sizeof(int) valueAddress should point to an int.
     */
    void StackPop(Stack* s, void* returnAddress);

    /*
     * Used to retrive a value from the stack without removing it
     * The data at returnAddress is populated by the data at the top of the stack
     *
     * Requires the data that valueAddress is of the same size as elemSize that was passed to StackNew
     * otherwise funky stuff will happen.
     * If you give the StackNew function sizeof(int) valueAddress should point to an int.
     */
    void StackPeek(Stack* s, void* returnAddress);

#ifdef	__cplusplus
}
#endif

#endif	/* _STACK_H */

