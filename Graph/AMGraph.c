//
//  AMGraph.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "AMGraph.h"

void GraphInit(GraphMatrix *gm, int nv)
{
    int i, j;
    gm->column = nv;
    gm->raw = nv;
    /*
    for(i = 0; i<gm->raw; i++)
    {
        for(j=0;j<gm->column;j++)
        {
            gm->matrix[i][j] = 0;
        }
    }*/
    
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
