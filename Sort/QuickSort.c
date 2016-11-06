//
//  QuickSort.c
//  HelloWorld
//
//  Created by yusujin on 2016. 7. 13..
//  Copyright © 2016년 유수진. All rights reserved.
//

#include <stdio.h>

void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int quickSort(int arr[], int left, int right, int pivot)
{
    int low = pivot+1;
    int high = right;
    int LLeft, LRight, LPivot, RLeft, RRight, RPivot;
    while(low<=high && low>= 0 && high>=0)
    {
        while(arr[low]<=arr[pivot] && low<=right)
        {
            low++;
        }
        while(arr[high]>=arr[pivot] && high>=(left+1))
        {
            high--;
        }
        if(low<=high){
            swap(&arr[low],&arr[high]);}
    }
    swap(&arr[pivot],&arr[high]);

    
    LLeft = left;
    LRight = high-1;
    LPivot = left;
    
    RLeft = high+1;
    RRight = right;
    RPivot = high+1;
    
    return high;
}

void doQuickSort(int arr[], int left, int right)
{
    if(left<=right)
    {
        int pivot = quickSort(arr, left, right, left);
        doQuickSort(arr, left, pivot-1);
        doQuickSort(arr, pivot+1, right);
    }
}

void qquickSort(int arr[])
{
    
}
int main()
{
    int arr[] = {5, 1, 3, 7, 9, 2, 4 , 6, 8};
    //int arr[] = {3, 3, 3};
    int left = 0, right = sizeof(arr)/sizeof(int)-1;
    int pivot,tmp1,tmp2;
    //doQuickSort(arr, left, right);
    
    pivot = quickSort(arr, left, right, left);
        while(1)
        {
            if(left<=right) {
                tmp1 = quickSort(arr,left,pivot-1,left);
                tmp2 = quickSort(arr, pivot+1, right, left);
            }else {
                break;
            }
        }
    
    for(int i =0; i<=right; i++)
    {
        printf("%d  ", arr[i]);
    }
}