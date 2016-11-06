//
//  BinarySearchTree.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 18..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>
#include "BinaryTree2.h"

typedef  BTData BSTData;
//BST생성 및 초기화
void BSTMakeAndInit(BTreeNode **pRoot);
BSTData BSTGetNodeData(BTreeNode *bst);
void BSTInsert(BTreeNode **pRoot, BSTData data);
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target);
void BSTDelete(BTreeNode *bst, BSTData target);


#endif /* BinarySearchTree_h */
