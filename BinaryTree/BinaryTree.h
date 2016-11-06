//
//  BinaryTree.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 8..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
typedef int BTData;
typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
    
}BTreeNode;

BTreeNode *MakeBTreeNode(void); // 노드의 생성
BTData GetData(BTreeNode *bt); // 노드에 저장된 데이터를 반환
void SetData(BTreeNode *bt, BTData data); //노드에 데이터를 저장

BTreeNode *GetLeftSubTree(BTreeNode *bt);
BTreeNode *GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);
#endif /* BinaryTree_h */
