//
//  DLinkedList.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "DLinkedList.h"
#include <stdlib.h>
void FInsert(List *plist, LData data);
void SInsert(List *plist, LData data);
void ListInit(List *plist)
{
    plist->header = (Node*)malloc(sizeof(Node)); // 더미노드의 생성
    plist->header->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}
void LInsert(List *plist, LData data)
{
    
    if(plist->comp == NULL) // 정렬 기준이 마련되지 않았다면
        FInsert(plist,data); // 머리에 노드를 추가
    else
        SInsert(plist,data); //정렬기준에 근거하여 노드를 추가
}

void FInsert(List *plist, LData data)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = plist->header->next;
    plist->header->next = n;
    
    plist->numOfData++;
}
void SInsert(List *plist, LData data)
{
    Node *n = (Node*)malloc(sizeof(Node));
    Node *pred = plist->header;
    n->data = data;
    
    while(pred->next != NULL && plist->comp(pred->next->data,data) != 0)
    {
        pred = pred->next;
    }
    
    n->next = pred->next;
    pred->next = n;
    
    (plist->numOfData)++;
}
int LFirst(List *plist, LData *pdata)
{
    if(plist->header->next == NULL) // 더미노드가 NULL이면
        return FALSE;
    
    plist->before = plist->header;
    plist->cur = plist->header->next;
    
    *pdata = plist->cur->data;
    
    return TRUE;
}
int LNext(List *plist , LData *pData)
{
    if(plist->cur->next == NULL)
        return FALSE;
    
    plist->before = plist->cur; // cur이 가리키던 것을 beforedl rkflzla
    plist->cur = plist->cur->next; /// cur은 그 다음 노드를 가리킴
    
    *pData = plist->cur->data; // cur이 가리키는 노드의 데이터 전달
    return TRUE;
}

LData LRemove(List *plist)
{
    //바로 이전에 호출된 LFirst 혹은 LNext함수가 반환한 데이터를 삭제한다.
    Node* dNode = plist->cur;
    LData data = dNode->data;
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    free(dNode);
    (plist->numOfData)--;
    return data;
}
int LCount(List *plist)
{
    return plist->numOfData;
}
//리스트 멤버 sort를 초기화
void SerSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}
