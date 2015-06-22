/*归并排序：
是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。

算法步骤：

1. 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列

2. 设定两个指针，最初位置分别为两个已经排序序列的起始位置

3. 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置

4. 重复步骤3直到某一指针达到序列尾

5. 将另一序列剩下的所有元素直接复制到合并序列尾
*/
//将序列a[first,mid]与a[mid+1,last]合并到temp[]中
#include<malloc.h>
void mergarrry(int a[],int first,int mid,int last,int temp[])
{
    int i = first,j=mid+1;
    int m = mid,n=last;
    int k = 0;
    while(i<=m && j<=n){//将小的元素加入到数组temp中
        if(a[i]<a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i<=m)//如果前半数组剩余，则将剩余全部加到数组temp中去
        temp[k++] = a[i++];
    while(j<=n)//如果后半数组剩余，则将剩余全部加到数组temp中去
        temp[k++] = a[j++];

    for(i=0;i<k;i++){
        a[i+first] = temp[i];
    }
}

//迭代归并
void merg_sort(int a[],int first,int last,int temp[])
{
    if(first<last){
       int mid = (first+last)/2;
       merg_sort(a,first,mid,temp);//前半有序
       merg_sort(a,mid+1,last,temp);//后半有序
       //合并数组
       mergarrry(a,first,mid,last,temp);
    }
}

//归并排序
void Merg_Sort(int a[],int n)
{
    int *p;
    p = (int *)malloc(sizeof(int)*n);
    if (p==NULL){
        printf("内存分配失败!\n");
        return;
    }
    merg_sort(a,0,n-1,p);
    free(p);

}
