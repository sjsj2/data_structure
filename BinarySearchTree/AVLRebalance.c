//
//  AVLRebalance.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 18..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "AVLRebalance.h"

int getHeight(BTreeNode *bst)
{
    int LHeight;
    int RHeight;
    if(bst == NULL)
        return 0;
    else {
        LHeight = 1 + getHeight(GetLeftSubTree(bst));
        RHeight = 1 + getHeight(GetRightSubTree(bst));
        
        if(LHeight>RHeight)
            return LHeight;
        else
            return RHeight;
    }
}
int getHeightDiff(BTreeNode *bst)
{
    if(bst == NULL)
        return 0;
    return getHeight(GetLeftSubTree(bst)) - getHeight(GetRightSubTree(bst));
}
BTreeNode * RotateLL(BTreeNode *bst)
{
    BTreeNode * cNode;
    BTreeNode * pNode = bst;
    
    cNode = GetLeftSubTree(pNode);
    
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode,pNode);
    
    return cNode;
}
BTreeNode * RotateRR(BTreeNode *bst)
{
    BTreeNode * cNode;
    BTreeNode * pNode = bst;
    
    cNode = GetRightSubTree(pNode);
    
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode,pNode);
    
    return cNode;
}
BTreeNode * RotateLR(BTreeNode *bst)
{
    BTreeNode *cNode;
    BTreeNode *pNode = bst;
    
    cNode = GetLeftSubTree(pNode);
    
    cNode = RotateRR(cNode);
    ChangeLeftSubTree(pNode, cNode);
    
    return RotateLL(pNode);
}
BTreeNode * RotateRL(BTreeNode *bst)
{
    BTreeNode *pNode = bst;
    BTreeNode *cNode = GetRightSubTree(pNode);
    
    cNode = RotateLL(cNode);
    ChangeRightSubTree(pNode, cNode);
    
    return RotateRR(pNode);
}

BTreeNode *Rebalance(BTreeNode ** pRoot)
{
    int diff = getHeightDiff(*pRoot);
    //균형 인수가 2 이상이면 LL 또는 LR이다.
    if(diff>1)
    {
        if(getHeightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }
    //균형인수가 -2이상이면 RR 또는 RL이다..
    if(diff<-1)
    {
        if(getHeightDiff(GetRightSubTree(*pRoot))<0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }
    return *pRoot;
}