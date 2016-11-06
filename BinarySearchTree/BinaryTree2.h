//
//  BinaryTree2.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 18..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef BinaryTree2_h
#define BinaryTree2_h

#include <stdio.h>
#include <stdlib.h>

typedef int BTData;
typedef struct _binaryTree
{
    BTData data;
    struct _binaryTree *left;
    struct _binaryTree *right;
}BTreeNode;

BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);
BTreeNode * GetLeftSubTree(BTreeNode *bt);
BTreeNode * GetRightSubTree(BTreeNode *bt);
void MakeLeftSubTree(BTreeNode *main,BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main,BTreeNode *sub);

void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub);

#endif /* BinaryTree2_h */
