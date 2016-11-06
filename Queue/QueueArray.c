//
//  Queue.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 7..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "QueueArray.h"

void QueueInit(Queue *queue)
{
    queue->Head = 0;
    queue->Tail = 0;
}
int QisEmpty(Queue *queue)
{
    if(queue->Head == queue->Tail)
    {
        return TRUE;
    }else return FALSE;
}
int QisOk(int num)
{
    if(num >= ARRAYLEN-1) {
        return 0;
    }else {
        return num+1;
    }
}
void EnQueue(Queue *queue, Data data)
{
    if(QisOk(queue->Tail) == queue->Head) {
        printf("Memory Error\n");
        exit(-1);
    }
    queue->Tail = QisOk(queue->Tail);
    queue->str[queue->Tail] = data;
}
Data DeQueue(Queue *queue)
{
    if(QisEmpty(queue) == TRUE) {
        printf("Queue is empty");
        exit(-1);
    }
    queue->Head = QisOk(queue->Head);
    return queue->str[queue->Head];
}
