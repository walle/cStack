/* 
 * File:   Stack.h
 * Author: walle
 *
 * Created on April 9, 2010, 7:49 PM
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

    void StackNew(Stack* s, int elemSize);
    void StackDestroy(Stack* s);
    void StackPush(Stack* s, void* value);
    void StackPop(Stack* s, void* returnValue);
    void StackPeek(Stack* s, void* returnValue);

#ifdef	__cplusplus
}
#endif

#endif	/* _STACK_H */

