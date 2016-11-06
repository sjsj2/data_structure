//
//  AMGraph.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 19..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef AMGraph_h
#define AMGraph_h

#include <stdio.h>
#define Matrix_Len      100
enum { A, B, C, D, E, F, G, H, I, J};
typedef struct _matrix
{
    int raw;
    int column;
    int matrix[Matrix_Len][Matrix_Len];
}GraphMatrix;
void GraphInit(GraphMatrix *gm, int nv);
void GraphDestroy(GraphMatrix *gm);
void AddEdge(GraphMatrix *gm, int fromV, int toV);
void ShowGraphEdgeInfo(GraphMatrix *gm);

#endif /* AMGraph_h */
