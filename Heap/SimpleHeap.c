//
//  SimpleHeap.c
//  HelloWorld
//  한번더..ㅠ_ㅠ
//  Created by yusujin on 2016. 7. 11..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "SimpleHeap.h"

void HeapInit(Heap *hp)
{
    hp->numOfData = 0;
}
int HIsEmpty(Heap *hp)
{
    if(hp->numOfData == 0){
        return TRUE;
    }else {
        return FALSE;
    }
}
int getParentIdx(int idx)
{
    return idx/2;
}
int getLeftChildIdx(int idx)
{
    return 2*idx;
}
int getRightChildIdx(int idx)
{
    return 2*idx+1;
}
void HInsert(Heap *hp, HData data, Priority pr)
{
    int idx = hp->numOfData+1;
    HeapElem tmp = {pr,data};
    
    while(idx != 1)
    {
        if(hp->heapArr[getParentIdx(idx)].pr>pr)
        {
            hp->heapArr[idx] = hp->heapArr[getParentIdx(idx)];
            idx = getParentIdx(idx);
        }else {
            break;
        }
    }
    hp->heapArr[idx]=tmp;
    hp->numOfData++;
}
int getHiPriChildIdx(Heap *ph, int idx)
{
    if(getLeftChildIdx(idx)>ph->numOfData)
    {
        return 0;
    }else if(getLeftChildIdx(idx) == ph->numOfData)
    {
        return getLeftChildIdx(idx);
    }else {
        if(ph->heapArr[getLeftChildIdx(idx)].pr > ph->heapArr[getRightChildIdx(idx)].pr)
        {
            return getRightChildIdx(idx);
        }else
            return getLeftChildIdx(idx);
    }
}
HData HDelete(Heap *hp)
{
    int childIdx, idx=1;
    HData returnData = hp->heapArr[idx].data;
    HeapElem tmp = hp->heapArr[hp->numOfData];
    while(childIdx = getHiPriChildIdx(hp, idx)){
        if(hp->heapArr[childIdx].pr < tmp.pr) {
            hp->heapArr[idx] = hp->heapArr[childIdx];
            idx = childIdx;
        }else {
            break;
        }
    }
    hp->heapArr[idx] = tmp;
    hp->numOfData--;
    return returnData;
}