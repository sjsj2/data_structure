//
//  QueueMain.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 8..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include <stdio.h>
#include "QueueList.h"
int main()
{
    Queue q;
    InitQueue(&q);
    
    EnQueue(&q, 1);
    EnQueue(&q, 2);
    EnQueue(&q, 3);
    EnQueue(&q, 4);
    printf("%d\n",DeQueue(&q));
    printf("%d\n",DeQueue(&q));
    
    EnQueue(&q, 5);
    EnQueue(&q, 6);
    
    EnQueue(&q, 9);
    while(IsQEmpty(&q) == FALSE)
    {
        printf("%d\n",DeQueue(&q));
        
    }
}