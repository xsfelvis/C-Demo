//原址交换
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
//下面这种交换在互换相同数字会出错
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
