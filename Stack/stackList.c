//
//  stackList.c
//  HelloWorld
//
//  Created by 유수진 on 2016. 7. 6..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "stackList.h"
void StackInit(Stack *pstack)
{
    pstack->head = NULL; //포인터 변수 head는 null로 초기화
}
int SIsEmpty(Stack *pstack)
{
    if(pstack->head == NULL) {
        return TRUE;
    }else return FALSE;
}
void SPush(Stack *pstack, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->head;
    pstack->head = newNode;
}
Data SPop(Stack *pstack)
{
    Node *rnode;
    Data rdata;
    if(SIsEmpty(pstack) == TRUE) {
        printf("Stack Memory Error");
        exit(-1);
    }
    rnode = pstack->head;
    rdata = pstack->head->data;
    pstack->head = pstack->head->next;
    free(rnode);
    return rdata;
}
Data SPeak(Stack *pstack)
{
    if(SIsEmpty(pstack) == TRUE) {
        printf("Stack memory error");
        exit(-1);
    }
    return pstack->head->data;
}