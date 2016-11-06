//
//  BinaryTree.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 8..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "BinaryTree.h"
#include <stdlib.h>
BTreeNode *MakeBTreeNode(void)
{
    BTreeNode *bt = (BTreeNode*)malloc(sizeof(BTreeNode));
    bt->left = NULL;
    bt->right = NULL;
    return bt;
}
BTData GetData(BTreeNode *bt)
{
    return bt->data;
} // 노드에 저장된 데이터를 반환
void SetData(BTreeNode *bt, BTData data)
{
    bt->data = data;
}//노드에 데이터를 저장

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}
BTreeNode *GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    if(main->left != NULL)
    {
        free(main->left);
    }
    main->left = sub;
}
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    if(main->right !=NULL)
    {
        free(main->right);
    }
    main->right = sub;
}