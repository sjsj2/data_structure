//
//  DLinkedList.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef DLinkedList_h
#define DLinkedList_h
#define TRUE            1
#define FALSE           0
#include <stdio.h>
#include "Slot.h"

typedef Slot LData;
typedef struct _node
{
    LData data;
    struct _node *next;
}Node;

typedef struct _list
{
    Node *header;
    Node *cur;
    Node *before; // cur보다 한 칸 앞선..
    int numOfData;
    int (* comp)(LData d1, LData d2);
    
}List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist , LData *pData);

LData LRemove(List *plist);
int LCount(List *plist);

void SerSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif /* DLinkedList_h */