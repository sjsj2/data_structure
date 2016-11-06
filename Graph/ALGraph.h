//
//  ALGraph.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef ALGraph_h
#define ALGraph_h

#include <stdio.h>
#include "MyList.h"

enum {A, B, C, D, E, F, G };
typedef struct _ual{
    
    int numV; // 정점의 ㅇ수
    int numE; // 엣지의 수
    List *adjList;//간선의 정보
}ALGraph;

void GraphInit(ALGraph *alg,int nv);
void GraphDestroy();
void AddEdge(ALGraph *alg, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph *alg);


#endif /* ALGraph_h */
