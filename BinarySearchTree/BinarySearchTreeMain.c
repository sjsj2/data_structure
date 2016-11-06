//
//  BinarySearchTreeMain.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 18..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include <stdio.h>
#include "BinarySearchTree.h"

int main()
{
    BTreeNode *bstRoot;
    BTreeNode *sNode;
    
    BSTMakeAndInit(&bstRoot);
    
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 4);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 10);
    
    sNode = BSTSearch(bstRoot, 2);
    
    if(sNode == NULL)
        printf("탐색실패\n");
    else
        printf("탐색에 성공한 키의 값 : %d\n",sNode->data);
    
    sNode = BSTSearch(bstRoot, 7);
    
    if(sNode == NULL)
        printf("탐색실패\n");
    else
        printf("탐색에 성공한 키의 값 : %d\n",sNode->data);
    
    BSTDelete(bstRoot, 2);
    BSTDelete(bstRoot, 1);
    
    sNode = BSTSearch(bstRoot, 2);
    
    if(sNode == NULL)
        printf("탐색실패\n");
    else
        printf("탐색에 성공한 키의 값 : %d\n",sNode->data);
    
    sNode = BSTSearch(bstRoot, 1);
    
    if(sNode == NULL)
        printf("탐색실패\n");
    else
        printf("탐색에 성공한 키의 값 : %d\n",sNode->data);
    

    
}