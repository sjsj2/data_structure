//
//  ALGraphBFS.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 21..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "ALGraphBFS.h"
#include "QueueList.h"

void VisitInfoReset(ALGraph *alg)
{
    int i;
    for(i=0;i<alg->numV;i++)
    {
        alg->VisitInfo[i]=0;
    }
}

void GraphInit(ALGraph *alg, int nv)
{
    int i;
    alg->numE = 0;
    alg->numV = nv;
    
    alg->adjList = (List*)malloc(sizeof(List)*nv);
    alg->VisitInfo = (int*)malloc(sizeof(int)*nv);
    for(i=0;i<nv;i++)
    {
        Listinit(&alg->adjList[i]);
        //alg->VisitInfo[i]=0;
    }
    VisitInfoReset(alg);
}
void GraphDestroy(ALGraph *alg);
void AddEdge(ALGraph *alg, int fromV,int toV)
{
    if(ListSearch(&alg->adjList[fromV], toV) == FALSE) {
        //데이터를 찾아도 없으면
        ListLastInsert(&alg->adjList[fromV], toV);
        ListLastInsert(&alg->adjList[toV], fromV);
        alg->numE++;
    }else {
        printf("이미 존재합니다.\n");
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

void BFShowGraphVertex(ALGraph *alg, int startV)
{
    int toV=0;
    int fromV =startV;
    Queue q;
    InitQueue(&q);
    printf("%c  ->",startV+65);
    //시작점은 이미 방문한거니깐.
    alg->VisitInfo[fromV] = 1;
    while(1){
        if(alg->adjList[fromV].Head->next == NULL)
        {
            printf("노드가 없습니다.\n");
        }
        else
        {
            alg->adjList[fromV].Cur = alg->adjList[fromV].Head;
            while(1)
            {
                alg->adjList[fromV].Cur = alg->adjList[fromV].Cur->next;
            
                ///끝까지 돌았으면 break;
                if(alg->adjList[fromV].Cur == NULL)
                    break;
                //visitinfo가 0이면 queue에 넣는다.
                toV = alg->adjList[fromV].Cur->data;
                if(alg->VisitInfo[toV] == 0) {
                    EnQueue(&q, toV);
                    printf("%c  -> ",toV+65);
                    alg->VisitInfo[toV] = 1;}
            } //이렇게 했으면 한 리스트(vertex)에대한 탐색을 마친거임. 그러면 다음으로 큐를 내보낸다.
        }
        //queue에서 꺼내서 그거를 fromV에 대입하고 또다시 탐색.
        if(IsQEmpty(&q) == TRUE)
            break;
        else
            fromV = DeQueue(&q);
    }//while(IsQEmpty(&q) == FALSE);
    
    VisitInfoReset(alg);
    
}