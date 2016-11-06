//
//  Stack.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#define STACK_LEN     100
#define TRUE          1
#define FALSE         0

typedef int Data;
typedef struct _stack
{
    int topIndex;
    Data stack[STACK_LEN];
}Stack;

void StackInit(Stack *s);
int StackIsEmpty(Stack *s);
int StackIsFull(Stack *s);
void StackPush(Stack *s,Data data);
Data StackPop(Stack *s);
#endif /* Stack_h */
