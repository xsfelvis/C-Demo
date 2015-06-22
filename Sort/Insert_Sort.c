/*
*插入排序思想：
直接插入排序(Insertion Sort)的基本思想是：每次将一个待排序的记录，按其关
键字大小插入到前面已经排好序的子序列中的适当位置，直到全部记录插入完成为止。
设数组为 a[0…n-1]。
1. 初始时， a[0]自成 1 个有序区，无序区为 a[1..n-1]。 令 i=1
2. 将 a[i]并入当前的有序区 a[0…i-1]中形成 a[0…i]的有序区间。
3. i++并重复第二步直到 i==n-1。排序完成。
*/
void Insert_Sort(int arry[],int length)
{
    int i,j;
    for(i=1;i<length;i++){
        for(j=i-1;j>=0;j--){
            if(arry[j]>arry[j+1])
                swap(&arry[j],&arry[j+1]);
        }
    }
}
