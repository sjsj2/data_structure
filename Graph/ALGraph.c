//
//  ALGraph.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "ALGraph.h"

void GraphInit(ALGraph *alg, int nv)
{
    
    alg->adjList = (List*)malloc(sizeof(List)*nv);
    alg->numV = nv;
    alg->numE = 0;
    
    int i;
    for(i=0;i<nv;i++)
    {
        Listinit(&alg->adjList[i]);
    }
    
}
void GraphDestroy();
void AddEdge(ALGraph *alg, int fromV, int toV)
{
    while(1)
    {
        if(ListSearch(&alg->adjList[fromV],toV) &&
           ListSearch(&alg->adjList[toV], fromV) == TRUE) {
            printf("이미 있음\n");
            break;
        }
        else
        {
            ListLastInsert(&alg->adjList[fromV], toV);
            ListLastInsert(&alg->adjList[toV], fromV);
            alg->numE++;
            break;
        }
    }
}
void ShowGraphEdgeInfo(ALGraph *alg)
{
    int i;
    //ListShow(&alg->adjList[fromV]);
    for(i=0;i<alg->numV;i++){
        alg->adjList[i].Cur = alg->adjList[i].Head;
        printf("%c와 연결된 정점들 : ", i+65);
        while(1){
            alg->adjList[i].Cur  = alg->adjList[i].Cur->next;
            if(alg->adjList[i].Cur == NULL)
                break;
            printf("%c ->",alg->adjList[i].Cur->data + 65);
        }
        printf("\n");
    }
}
