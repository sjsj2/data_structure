//
//  stackList.h
//  HelloWorld
//
//  Created by 유수진 on 2016. 7. 6..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef stackList_h
#define stackList_h

#include <stdio.h>
#include <stdlib.h>
#define TRUE    1
#define FALSE   0
typedef int Data;
typedef struct _node //연결리스트 노드를 표현한 구조체
{
    Data data;
    struct _node *next;
}Node;
typedef struct _listStack
{
    Node *head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack); // 스택이 비었을 경우 TRUE, 그렇지 않으면 FALSE

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeak(Stack *pstack); //마지막에 저장된 요소를 반환하되 삭제 ㄴㄴ
#endif /* stackList_h */
