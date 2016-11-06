//
//  GraphPrac.c
//  HelloWorld
//
//  Created by yusujin on 2016. 8. 6..
//  Copyright © 2016년 유수진. All rights reserved.
//
// adjacent matrix
#include "GraphPrac.h"
typedef struct _graph
{
    int numE;
    int numV;
    int graph[100][100];
}Graph;

typedef struct _queue
{
    int dataNum;
    int data[1000];
    int tail;
    int head;
}Queue;
void graphInit(Graph *g, int nV);
void addEdge(Graph *g, int from,int to, int weight);

void graphInit(Graph *g,int nV)
{
    int i,j;
    g->numE = 0;
    g->numV = nV;
    for(i=0;i<100;i++)
    {
        for(j=0;j<100;j++)
        {
            g->graph[i][j]=0;
        }
    }
}

void addEdge(Graph *g, int from,int to, int weight)
{
    g->graph[from][to] = weight;
    g->graph[to][from] = weight;
    g->numE++;
    g->numE++;
}
void initQueue(Queue *q)
{
    q->head =-1;
    q->tail =-1;
}
void enqueue(Queue *q, int data)
{
    q->tail++;
    q->data[q->tail] = data;
}
int dequeue(Queue *q)
{
    int data;
    q->dataNum--;
    data= q->data[q->head];
    q->head++;
    return data;
}
int main()
{
    int numV;
    int i,j,num;
    Graph g;
    int info[100][100];
    int queue[100];
    scanf("%d", &numV);
    for(j=0; j<numV; j++)
    {
        for(i =0;i<numV;i++)
        {
            scanf("%d",&num);
            g.graph[i][j] = num;
        }
    
    }
    i=0;
    for(j=0;j<numV;j++)
    {
        while(1)
        {
            g.graph[i][j]
        }
    }
    
    
}