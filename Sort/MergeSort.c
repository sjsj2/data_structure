//
//  MergeSort.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 13..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[],int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid+1;
    int *sortArr = (int*)malloc(sizeof(int)*(right+1));
    int sIdx = left;
    int j;
    //두 데이터 뭉치를 비교하여 sortArr에 옮겨 담는 과정
    while(fIdx<=mid && rIdx<=right)
    {
        if(arr[fIdx]<=arr[rIdx])
        {
            sortArr[sIdx] = arr[fIdx];
            fIdx++;
        }else {
            sortArr[sIdx] = arr[rIdx];
            rIdx++;
        }
        sIdx++;
    }
    
    if(fIdx>mid)
    {
        //뒷부분 옮기고
        while(rIdx<=right)
        {
            sortArr[sIdx] = arr[rIdx];
            rIdx++;
            sIdx++;
        }
    }else {
        //앞부분 옮긴다.
    
        while(fIdx<=mid)
        {
            sortArr[sIdx] = arr[fIdx];
            fIdx++;
            sIdx++;
        }
    }
    for(j=left; j<=right;j++)
    {
        arr[j] = sortArr[j];
        printf("%d  ",arr[j]);
    }
    printf("\n");
    free(sortArr);
    
}

void MergeSort(int arr[], int left, int right) // left와 right 값으로 범위 설정
{
    int mid;
    if(left < right)
    {
        mid = (left + right)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        
        MergeTwoArea(arr,left,mid,right);
    }
}

int main()
{
    int arr[] = {8,2,3,7,1,5,4,6};
    int left = 0,right = sizeof(arr)/sizeof(int)-1;
    int i;
    
    MergeSort(arr, left,right);
    
    for(i=0;i<=right;i++)
    {
        //printf("%d  ",arr[i]);
    }
    
}