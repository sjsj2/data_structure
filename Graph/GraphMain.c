//
//  GraphMain.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include <stdio.h>
//#include "AMGraphDFS.h"
//#include "ALGraph.h"
#include "ALGraphBFS.h"
int main()
{
    ALGraph gm;
    
    GraphInit(&gm, 7);
    
    AddEdge(&gm, A, B);
    AddEdge(&gm, A, D);
    AddEdge(&gm, B, C);
    AddEdge(&gm, D,C);
    AddEdge(&gm, D, E);
    AddEdge(&gm, E, F);
    AddEdge(&gm, E,G);
   // AddEdge(&gm, E, G);
    ShowGraphEdgeInfo(&gm);
    
  //  BFShowGraphVertex(&gm, A);printf("\n");
  //  BFShowGraphVertex(&gm, C);printf("\n");
//    BFShowGraphVertex(&gm, E);printf("\n");
    BFShowGraphVertex(&gm, G);printf("\n");
}