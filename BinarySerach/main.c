#include <stdio.h>
#include <stdlib.h>
/*二分查找法*/
int  BinarySearch(int Arry[],int len,int value);
int main()
{
   int a[] = {1,3,5,7,9,13,15,17,19,21,23};     //二分法查找首先要针对排序过的数组
   int k ,position;
   k = sizeof(a)/sizeof(int);               //计算数组长度
   int m = 15;
   position = BinarySearch(a,k,m);           //这个位置时从0计数开始的
   printf("查找的数据位置为数组第 %d 个元素",position+1);
}

int  BinarySearch(int Arry[],int len,int value)
{
    if(Arry==NULL||len<0)
    return -1;

    int start = 0;
    int end = len-1;
    /*二分查找法要注意
    right = n-1 => while(left <= right) => right = middle-1;
    right = n => while(left < right) => right = middle;

    */
    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if(Arry[mid]==value)
            return mid;
        else if (Arry[mid]<value)
            start = mid+1;
        else
            end = mid-1;
    }
}
