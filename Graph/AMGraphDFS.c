//
//  AMGraphDFS.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "AMGraphDFS.h"
#include <stdlib.h>
void GraphInit(GraphMatrix *gm, int nv)
{
    int i, j;
    gm->column = nv;
    gm->raw = nv;
    
    for(i = 0; i<gm->raw; i++)
    {
        for(j=0;j<gm->column;j++)
        {
            gm->matrix[i][j] = 0;
        }
        gm->visitInfo[i] = 0;
    }
}
void GraphDestroy(GraphMatrix *gm)
{
    int i, j;
    for(i = 0; i<gm->raw; i++)
    {
        for(j=0;j<gm->column;j++)
        {
            gm->matrix[i][j] = 0;
        }
        gm->visitInfo[i] = 0;
    }
}
void AddEdge(GraphMatrix *gm, int fromV, int toV)
{
    gm->matrix[fromV][toV] = 1;
    gm->matrix[toV][fromV] = 1;
}

void ShowGraphEdgeInfo(GraphMatrix *gm)
{
    int i,j;
    for(i = 0; i<gm->raw; i++)
    {
        printf("%c와 연결된 정점 : ",i+65);
        for(j=0;j<gm->column;j++)
        {
            if(gm->matrix[i][j]>0){
                printf(" %c  ",j+65);}
        }
        printf("\n");
    }
}
void DFShowGraphVertex(GraphMatrix *gm, int startV)
{
    int fromV = startV;
    int toV = 0;
    int flag =0;
    int popData=0;
    Stack s;
    StackInit(&s);
    s.topIndex++;
    gm->visitInfo[startV]=1;
    
    do
    {
        //while(gm->visitInfo[j] ==0){ //
        while(toV < gm->column){
            if(gm->matrix[fromV][toV] == 1 && gm->visitInfo[toV] == 0){
                flag = 1;
                break;
            }
            toV++;
        }
        if(flag == 0) // 다 돌아도 한번도 거치지 않음
        {
            popData = StackPop(&s);
           // printf("\npop : %c -> %c \n", fromV+65,popData+65);
            fromV = popData;
        }else{ //한번 거침
            gm->visitInfo[toV] = 1; // 그 j의 방문정보를 1로,
            StackPush(&s, fromV);//그리고이전 정보를 스택에 담는다.
           // printf("-> %c",fromV+65);
            fromV = toV;
            flag =0;
            printf("-> %c   " ,toV+65);
            
        }
        toV= 0;
        
    }while(StackIsEmpty(&s) != TRUE);

    printf("\n");
    for(int i=0;i<gm->column;i++)
        gm->visitInfo[i]=0;
}


