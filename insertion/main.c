#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*插入排序*/
//函数声明
void insertSort(int a[]);
void display(int a[],int k);

int main()
{   int k=0;
    int a[] = {5,2,4,6,1,3};
    k = sizeof(a)/sizeof(a[0]);
    insertSort(a);
    printf("排序后数组长度为：%d\n",k);
    display(a,k);
    return 0;
}
void insertSort(int a[])
{
    int i=0,j=0,key=0;
    for(j=1;j<6;j++)
    {
        key = a[j]; //获取当前元素放入关键字
        i = j-1;        //当前元素的前一个元素
        while(i>=0&&a[i]>key)  //保证按照从小到大顺序排序
        {
            a[i+1]=a[i];
            i=i-1;

        }                      //找出要插入的位置i才是关键所在
         printf("我是测试i%d ",i+1);
         a[i+1] = key;          //核心代码

    }
}
void display(int a[],int k)
{
   int i;
   for(i=0;i<k;i++)
   {
       printf("%d ",a[i]);
   }
}

