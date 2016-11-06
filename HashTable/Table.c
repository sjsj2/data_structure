//
//  Table.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "Table.h"

void TBLInit(Table *pt, HashFunc *f)
{
    int i;
    
    for(i=0;i<MAX_TBL; i++)
        ListInit(&(pt->tbl[i]));
    
    pt->hf = f;
}
void TBLInsert(Table *pt, Key k, Value v)
{
    int key = pt->hf(k);
    Slot ns = {k,v};
    //pt->tbl[key].cur->next->data.val = v;
    if(TBLSearch(pt, k) != NULL) {
        printf("키 중복\n");
        return;
    }else
    {
        LInsert(&pt->tbl[key], ns);
    }
}
Value TBLDelete(Table *pt, Key k)
{
    int key = pt->hf(k);
    
    if(pt->tbl[key].header == NULL)
        return FALSE;
    else
        return LRemove(&pt->tbl[key]).val;
}
Value TBLSearch(Table *pt, Key k);
