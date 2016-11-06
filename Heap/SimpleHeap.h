//
//  SimpleHeap.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 11..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef SimpleHeap_h
#define SimpleHeap_h
#define TRUE        1
#define FALSE       0
#define STRLEN      100
#include <stdio.h>
#include <stdlib.h>

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
    Priority pr; // 값이 작을수록 높은 우선순위
    HData   data;
}HeapElem;

typedef struct struct_heap
{
    int numOfData;
    HeapElem heapArr[STRLEN];
    
}Heap;

void HeapInit(Heap *hp);
int HIsEmpty(Heap *hp);

void HInsert(Heap *hp, HData data, Priority pr);
HData HDelete(Heap *ph);
#endif /* SimpleHeap_h */
