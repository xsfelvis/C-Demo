#include <time.h>
/*
冒泡排序思想：
1． 比较相邻的前后二个数据，如果前面数据大于后面的数据，就将二个数据交换。
2． 这样对数组的第0个数据到N-1个数据进行一次遍历后，最大的一个数据就“沉”到数组第N-1个位置。
3． N=N-1，如果N不为0就重复前面二步，否则排序完成。
按从小到大排序
*/
//冒泡排序1:基本
void Bubble_Sort1(int Arry[],int n)//数组名和数组长度
{   //clock_t t1,t2;
//    t1 = clock();
    int i,j;
    for(i=0; i<n; i++) {
        for(j=1; j<n-i; j++) //内层循环，对余下的数进行比较
            //如果a[j-1]>a[j]则进行交换
            if(Arry[j-1]>Arry[j])
                swap(&Arry[j-1],&Arry[j]);
    }
//    t2 = clock();
//    printf("Bubble_Sort1 time=%f\n",(double)(t2-t1)/CLOCKS_PER_SEC);

}

//冒泡排序2：要是某一趟没有发生任何的交换则说明已经排好了无需再继续了
/*通过设置标志位flag
*/
void Bubble_Sort2(int Arry[],int n)//数组名和数组长度
{
    int i,j;
    int flag = 1;
    for(i=0; i<n; i++) {
        flag = 0;//每趟交换的开始先将flag置0
        for(j=1; j<n-i; j++) {
            //内层循环，对余下的数进行比较
            //如果a[j-1]>a[j]则进行交换

            if(Arry[j-1]>Arry[j]) {
                swap(&Arry[j-1],&Arry[j]);
                flag = 1;
            }
        }
        if(flag==0)
            return;
    }

}
//正宗冒泡，前面都为沉底排序
void Bubble_Sort3(int Arry[],int n)//数组名和数组长度
{
    int i,j;
    int flag = 1;
    for(i=0; i<n; i++) {
        flag = 0;//每趟交换的开始先将flag置0
        for(j=n-1; j>=i; j--) {
            //内层循环，对余下的数进行比较
            //如果a[j-1]>a[j]则进行交换

            if(Arry[j]>Arry[j+1]) {
                swap(&Arry[j],&Arry[j+1]);
                flag = 1;
            }
        }
        if(flag==0)
            return;
    }

}
