//
//  BinaryTree2.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 18..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "BinaryTree2.h"

BTreeNode * MakeBTreeNode(void)
{
    BTreeNode *bt = (BTreeNode*)malloc(sizeof(BTreeNode));
    bt->left = NULL;
    bt->right = NULL;
    return bt;
}
BTData GetData(BTreeNode *bt)
{
    BTData data = bt->data;
    return data;
}
void SetData(BTreeNode *bt, BTData data)
{
    bt->data = data;
}
BTreeNode * GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}
void MakeLeftSubTree(BTreeNode *main,BTreeNode *sub)
{
    if(main->left !=NULL)
        free(main->left);
    
    main->left = sub;
}
void MakeRightSubTree(BTreeNode *main,BTreeNode *sub)
{
    if(main->right != NULL)
        free(main->right);
    
    main->right = sub;
}
void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    main->left = sub;
}
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    main->right = sub;
}