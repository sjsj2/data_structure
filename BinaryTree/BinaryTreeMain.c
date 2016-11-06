//
//  BinaryTreeMain.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 8..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include <stdio.h>
#include "BinaryTree.h"

int main()
{
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt3, bt4);
    
    printf("%d\n",GetData(GetRightSubTree(bt1)));
}