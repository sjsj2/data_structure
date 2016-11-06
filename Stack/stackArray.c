//
//  stackArray.c
//  HelloWorld
//  배열기반, 연결리스트 기반
//  Created by 유수진 on 2016. 7. 6..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "stackArray.h"
void StackInit(Stack *pstack)
{
    pstack->topIndex = -1;
}
int SIsEmpty(Stack *pstack)
{
    if(pstack->topIndex == -1) {
        return TRUE;
    }else return FALSE;
}
void SPush(Stack *pstack, Data data)
{
    pstack->topIndex +=1;
    pstack->stackArr[pstack->topIndex] = data;
}
Data SPop(Stack *pstack)
{
    if(SIsEmpty(pstack) == TRUE) {
        printf("Stack Memory Error");
        exit(-1);
    }
    Data data = pstack->stackArr[pstack->topIndex];
    pstack->topIndex -=1;
    return data;
}
Data SPeak(Stack *pstack)
{
    if(SIsEmpty(pstack) == TRUE) {
        printf("Stack memory error");
        exit(-1);
    }
    return pstack->stackArr[pstack->topIndex];
}