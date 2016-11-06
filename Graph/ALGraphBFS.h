//
//  ALGraphBFS.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 21..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef ALGraphBFS_h
#define ALGraphBFS_h

#include <stdio.h>
#include "MyList.h"
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;   //정점의 수
    int numE;   //edge 간선.
    List *adjList;   //간선의 정보
    int *VisitInfo;
}ALGraph;

void GraphInit(ALGraph *alg, int nv);
void GraphDestroy(ALGraph *alg);
void AddEdge(ALGraph *alg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph *alg);

void BFShowGraphVertex(ALGraph *alg, int startV); // 정점의 정보

#endif /* ALGraphBFS_h */
