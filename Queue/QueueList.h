//
//  QueueList.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 13..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef QueueList_h
#define QueueList_h
#define TRUE        1
#define FALSE       0
#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct _qlist
{
    Data data;
    struct _qlist *next;
}QNode;
typedef struct _list_Queue
{
    QNode* node;
    QNode* Tail;
    QNode* header;
}Queue;
void InitQueue(Queue *q);
void EnQueue(Queue *q,Data data);
Data DeQueue(Queue *q);
int IsQEmpty(Queue *q);

#endif /* QueueList_h */
