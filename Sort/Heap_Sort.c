/*
堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。
堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。

堆排序的平均时间复杂度为Ο(nlogn) 。

算法步骤：

1）创建一个堆H[0..n-1]

2）把堆首（最大值）和堆尾互换

3）把堆的尺寸缩小1，并调用shift_down(0),目的是把新的数组顶端数据调整到相应位置

4） 重复步骤2，直到堆的尺寸为1
*/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define PARENT(i) (i)/2
#define LEFT(i) 2*(i)+1
#define RIGHT(i) 2*(i+1)

//void swap(int *a,int *b)
//{
//    *a=*a^*b;
//    *b=*a^*b;
//    *a=*a^*b;
//}
void max_heapify(int *arr,int index,int len)
{
    int l=LEFT(index);
    int r=RIGHT(index);
    int largest;
    if(l<len && arr[l]>arr[index])
        largest=l;
    else
        largest=index;
    if(r<len && arr[r]>arr[largest])
        largest=r;
    if(largest != index){//将最大元素提升，并递归
        swap(&arr[largest],&arr[index]);
        max_heapify(arr,largest,len);
    }
}

void build_maxheap(int *arr,int len)
{
    int i;
    if(arr==NULL || len<=1)
        return;
    for(i=len/2+1;i>=0;i--)
        max_heapify(arr,i,len);
}
void Heap_Sort(int *arr,int len)
{
    int i;
    if(arr==NULL || len<=1)
        return;
    build_maxheap(arr,len);

    for(i=len-1;i>=1;i--){
        swap(&arr[0],&arr[i]);
        max_heapify(arr,0,--len);
    }
}

//int main()
//{
//    int arr[10]={1,4,6,2,5,8,7,6,9,12};
//    int i;
//    heap_sort(arr,10);
//    for(i=0;i<10;++i)
//        printf("%d ",arr[i]);
//    system("pause");
//}
