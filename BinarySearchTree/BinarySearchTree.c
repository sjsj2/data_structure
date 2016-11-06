//
//  BinarySearchTree.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 18..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include "BinarySearchTree.h"
//BST생성 및 초기화
void BSTMakeAndInit(BTreeNode **pRoot)
{/*
    BTreeNode *bt = (BTreeNode*)malloc(sizeof(BTreeNode));
    bt->left = NULL;
    bt->right= NULL;
    // *pRoot = (BTreeNode*)malloc(sizeof(BTreeNode));
    pRoot = &bt;*/
    *pRoot = NULL;
}
BSTData BSTGetNodeData(BTreeNode *bst)
{
    
    return GetData(bst);
}
void BSTInsert(BTreeNode **pRoot, BSTData data)
{
    BSTData nData;
    BTreeNode *tmp = *pRoot; // current Node;
    BTreeNode *pt = NULL; // parent Node;
    BTreeNode *bt = NULL;
    while(tmp !=NULL){
        nData = GetData(tmp);
        if(nData == data)
            break;
        
        pt = tmp;
        if(nData<data){
            tmp=GetRightSubTree(tmp);}
        else{
            tmp = GetLeftSubTree(tmp);}
    }
    bt = MakeBTreeNode();
    SetData(bt, data);
    if(pt == NULL) {
        //새로운 노드가 루트노드
        *pRoot = bt;
    }else {
        if(nData<data)
        {
            MakeRightSubTree(pt, bt);
        }else {
            MakeLeftSubTree(pt, bt);
        }
    }
}
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target)
{
    int nData = bst->data;
    BTreeNode *tmp = bst;
    while(tmp !=NULL){
        nData = GetData(tmp);
        if(nData<target) {
            tmp = tmp->right;
            //nData = GetData(tmp); 여기에 하면 오류남
        }else if(target<nData) {
            tmp = tmp->left;
          //nData = GetData(tmp);
        }else {
            return tmp;
        }
    }
    return NULL;
}
void BSTDelete(BTreeNode *bst, BSTData target)
{
    BTreeNode *cNode = BSTSearch(bst, target);
    //BTreeNode *dNode = cNode;
    printf("data : %d\n",cNode->data);
    //BTreeNode *tmp;
    if(GetLeftSubTree(cNode) == NULL && GetRightSubTree(cNode) == NULL)
    {
        //단말 노드일 때
        cNode->left = NULL;
        cNode->right = NULL;
        free(cNode);
    
    }else if(GetRightSubTree(cNode) == NULL || GetLeftSubTree(cNode) == NULL)
    {
        //한 개의 서브트리
        if(GetLeftSubTree(cNode) != NULL) {
            cNode->data = GetLeftSubTree(cNode)->data;
            cNode->left = NULL;
        }else {
            cNode->data = GetRightSubTree(cNode)->data;
            cNode->right=NULL;
        }
    }else {
        //두개의 서브 트리
        BTreeNode *tmp = GetRightSubTree(cNode); // 대체할 노드
        BTreeNode *pNode = NULL; // 부모 노드
        int num;
        while(GetLeftSubTree(tmp) !=NULL)
        {
            pNode = tmp;
            tmp = GetLeftSubTree(tmp);
        }
        num = GetData(tmp);
        //free(tmp);
        SetData(cNode, num); // 데이타 데입
        //대체할 노드의 자식노드와 부모노드를 연결
        if(GetLeftSubTree(pNode) == tmp) {
            //MakeLeftSubTree(pNode, GetRightSubTree(tmp));
            pNode->left = GetRightSubTree(tmp);
        }
        else {
            //MakeRightSubTree(pNode, GetRightSubTree(tmp));
            pNode->right = GetRightSubTree(tmp);
        }
        free(tmp);
    }
}