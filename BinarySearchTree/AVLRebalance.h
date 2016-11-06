//
//  AVLRebalance.h
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 18..
//  Copyright © 2016년 유수진. All rights reserved.
//

#ifndef AVLRebalance_h
#define AVLRebalance_h

#include <stdio.h>
#include "BinarySearchTree.h"
int getHeight(BTreeNode *bst);
int getHeightDiff(BTreeNode *bst);
BTreeNode * RotateLL(BTreeNode *bst);
BTreeNode * RotateRR(BTreeNode *bst);
BTreeNode * RotateLR(BTreeNode *bst);
BTreeNode * RotateRL(BTreeNode *bst);
#endif /* AVLRebalance_h */
