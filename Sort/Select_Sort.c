/*
直接排序：
直接选择排序和直接插入排序类似，都将数据分为有序区和无序区，所不同的是
直接插入排序是将无序区的第一个元素直接插入到有序区以形成一个更大的有
序区，而直接选择排序是从无序区选一个最小的元素直接放到有序区的最后。
设数组为 a[0…n-1]。
4. 初始时， 数组全为无序区为 a[0..n-1]。 令 i=0
5. 在无序区 a[i…n-1]中选取一个最小的元素，将其与 a[i]交换。交换之后 a[0…i]
就形成了一个有序区。
6. i++并重复第二步直到 i==n-1。排序完成。
*/
void Select_Sort(int arry[],int length)
{
    int i,j,nMaxIndex;
    for(i=0;i<length;i++){
            nMaxIndex = i;
        for(j=i+1;j<length;j++){//找到最小元素的位置
            if(arry[j]<arry[nMaxIndex]){
               nMaxIndex = j;
            }
        }
        swap(&arry[i],&arry[nMaxIndex]);
    }
}
