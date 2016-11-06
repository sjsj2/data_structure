//
//  RadixSort.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 13..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include <stdio.h>
#include "QueueList.h"

void RadixSort(int arr[],int len)
{
    Queue queue[10];
    int i,j;
    for(i =0;i<10;i++){
        InitQueue(&queue[i]);}
    int radix;
    for(i = 1; i<=10000; i=i*10)
    {
        for(j=0; j<len;j++)
        {
            radix = (arr[j]/i)%10;
            EnQueue(&queue[radix], arr[j]);
        }
        j=0;
        for(radix=0;radix<10;radix++)
        {
            while(IsQEmpty(&queue[radix]) == FALSE)
            {
                arr[j] = DeQueue(&queue[radix]);
                j++;
            }
        }
    }
    
}

int main()
{
    int arr[] = {13, 323, 14,  5161, 10987, 6, 16};
    int len = sizeof(arr)/sizeof(int);
    RadixSort(arr,len);
    
    for(int i=0;i<len;i++){
        printf("%d   ",arr[i]);}
}