//
//  Table.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef Table_h
#define Table_h

#include <stdio.h>
#include "Slot.h"
#include "DLinkedList.h"

#define MAX_TBL     100

typedef int HashFunc(Key K);

typedef struct _table
{
    List tbl[MAX_TBL];
    HashFunc *hf;
}Table;

void TBLInit(Table *pt, HashFunc *f);
void TBLInsert(Table *pt, Key k, Value v);
Value TBLDelete(Table *pt, Key k);
Value TBLSearch(Table *pt, Key k);


#endif /* Table_h */
