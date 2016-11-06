//
//  SimpleHeapMain.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 11..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include <stdio.h>
#include "SimpleHeap.h"
int main()
{
    printf("Hello\n");
    Heap hp;
    HeapInit(&hp);
    
    HInsert(&hp, 'a', 1);
    HInsert(&hp, 'b', 7);
    HInsert(&hp, 'c', 5);
    HInsert(&hp, 'a', 1);
    HInsert(&hp, 'b', 7);
    HInsert(&hp, 'c', 5);
    printf("%c\n", HDelete(&hp));
    printf("%c\n", HDelete(&hp));
    printf("%c\n", HDelete(&hp));
    HInsert(&hp, 'c', 5);
    HInsert(&hp, 'a', 1);
    HInsert(&hp, 'b', 7);
    HInsert(&hp, 'c', 5);
    
    while(!HIsEmpty(&hp)){
        printf("%c\n", HDelete(&hp));}
    printf("end\n");
    
}