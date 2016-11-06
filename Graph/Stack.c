//
//  Stack.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "Stack.h"
void StackInit(Stack *s)
{
    s->topIndex = -1;
}
int StackIsEmpty(Stack *s)
{
    if(s->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}
int StackIsFull(Stack *s)
{
    if(s->topIndex == STACK_LEN-1)
        return TRUE;
    else
        return FALSE;
}
void StackPush(Stack *s,Data data)
{
    if(StackIsFull(s) == TRUE){
        printf("stack is full\n");
        return;
    }
    s->topIndex++;
    s->stack[s->topIndex] = data;
}
Data StackPop(Stack *s)
{
    Data data;
    if(StackIsEmpty(s) == TRUE){
        printf("Stack is empty\n");
        return 0;
    }
    data= s->stack[s->topIndex];
    s->stack[s->topIndex] = 0;
    s->topIndex--;
    return data;
}