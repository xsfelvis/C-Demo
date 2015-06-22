/*
Author: XSF

About:  《算法导论》第9章 查找序列第i小的数字
*/
#include <stdio.h>
#include <stdlib.h>
//交换的函数
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//找到划分位置
int partition(int *arr,int p,int r)
{
    int x = arr[r];
    int i = p-1;
    int j;
    for(j=p;j<=r-1;j++)
    {
        if(arr[j]<=x)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
//随机划分算法
int RandomPartition(int *arr, int p,int r)
{
    int i = p+rand()%(r-p+1);
    swap(&arr[r],&arr[i]);
    return partition(arr,p,r);
}
//随机选择
int RandomSelect(int *arr,int p,int r,int i)
{
    if(p==r)
        return arr[p];
    int q = RandomPartition(arr,p,r);
    int k = q-p+1;
    if (i==k)         //找到中间元素
        return arr[q];
    else if (i<k)
        return RandomSelect(arr,p,q-1,i);
    else
        return RandomSelect(arr,q+1,r,i);
}
int main()
{
     int a[] = {0, 89, 100, 21, 5, 2, 8, 33, 27, 63};
    int num = 9;
    int ith;
	printf("序列为：\n");
	int i;
    for(i=1; i<=num; ++i)
        printf("%d ",a[i]);
	printf("\n");
    ith = RandomSelect(a, 1, num, 3);
	printf("第2小的数字为%d",ith);
	getchar();

    return 0;
}
