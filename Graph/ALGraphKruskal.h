//
//  ALGraphKruskal.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 21..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef ALGraphKruskal_h
#define ALGraphKruskal_h

#include <stdio.h>

#include "MyList.h"
#include "ALEdge.h"
#include "QueueList.h"
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;
    int numE;
    List *adjList;
    int *visitInfo;
    Queue queue;
    
}ALGraph;

void GraphInit(ALGraph *pg, int nv);
void GraphDestroy(ALGraph *pg);
void GraphShow();
#endif /* ALGraphKruskal_h */
