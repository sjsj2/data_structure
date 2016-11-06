//
//  QueueList.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 13..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "QueueList.h"

void InitQueue(Queue *q)
{
    q->header = NULL;
    q->Tail = NULL;
}

int IsQEmpty(Queue *q)
{
    if(q->header == NULL)
        return TRUE;
    else
        return FALSE;
}

void EnQueue(Queue *q, Data data)
{
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = data;
    if(IsQEmpty(q) == TRUE)
    {
        q->header = newNode;
        q->Tail = newNode;
    }else{
        q->Tail->next = newNode;
        q->Tail = newNode;
    }
}
Data DeQueue(Queue *q)
{
    QNode *node = q->header;
    Data data;
    if(IsQEmpty(q) == TRUE){
        printf("데이터가 이제 없음\n");
        exit(-1);
    }
    data = node->data;
    q->header = node->next;
    
    free(node);
    return data;
}