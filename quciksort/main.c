#include <stdio.h>
#include <stdlib.h>
/*
 * Author: XSF
 * Note:   快速排序版本2---《算法导论》
 *核心思想：
 */

//交换数据
#define DEBUG 1
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
//    *a = *a ^ *b;
//    *b = *b ^ *a;
//    *a = *a ^ *b;
}
//打印函数
void PrintArray(int *arr,int num)
{
    int i;
    for(i=0; i<num; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
//核心函数，对数组A[p,r]进行就地重排，将小于A[r]的数移到数组前半部分，将大于A[r]的数移到数组后半部分。
int Partition(int *arr,int start,int end)
{
    int sential = arr[end];
    int i = start-1;
    int j ;
    int m;
    int n;
    for(j=start; j<end; j++) {
        if (arr[j]< sential){
            i = i + 1;
            #if DEBUG
            m = arr[i];
            n = arr[j];
            #endif // DEBUG
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[end]);
    return i+1;
}

void Quick_Sort(int *arr,int start,int end)
{
    if(start<end){
        int mid;
        mid = Partition(arr,start,end);
        Quick_Sort(arr,start,mid-1);
        Quick_Sort(arr,mid+1,end);
    }
}

int main()
{
    int arry[5]={2,8,1,4,3};
    printf("排序前：\n");
    PrintArray(arry,5);
//    int m = Partition(arry,0,9);
//    printf("%d",m);
    Quick_Sort(arry,0,4);
    printf("排序后：\n");
    PrintArray(arry,5);
    return 0;
}
