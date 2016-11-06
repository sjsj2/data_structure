//
//  stackArray.h
//  HelloWorld
//
//  Created by 유수진 on 2016. 7. 6..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef stackArray_h
#define stackArray_h

#include <stdio.h>
#include <stdlib.h>
#define TRUE    1
#define FALSE   0
#define STACK_LEN   100

typedef int Data;
typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack); // 스택이 비었을 경우 TRUE, 그렇지 않으면 FALSE
void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeak(Stack *pstack); //마지막에 저장된 요소를 반환하되 삭제 ㄴㄴ
#endif /* stackArray_h */
