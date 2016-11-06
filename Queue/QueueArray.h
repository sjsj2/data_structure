//
//  Queue.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 7..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#define ARRAYLEN  5
#define TRUE        1
#define FALSE       0
#include <stdio.h>
typedef int Data;
typedef struct _queue_list
{
    int Head;
    int Tail;
    Data str[ARRAYLEN];
}QueueList;
typedef QueueList Queue;
void QueueInit(Queue *queue);
void EnQueue(Queue *queue, Data data);
Data DeQueue(Queue *queue);
#endif /* Queue_h */
