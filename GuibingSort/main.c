#include <stdio.h>
#include <stdlib.h>
/*实现归并排序*/
void display(int a[],int k);
void MERG(int a[],int p,int q,int r);
int main()
{
    int A[] = {2,1,5,3,6};

    MERGE(A,4,7,11); //截断的位置
    display(A,sizeof(A)/sizeof(int));
}
void MERGE(int a[],int p,int q,int r)
{
    int n1,n2;
    int i=0,j=0;
    int k=0;
    n1 = q-p+1;
    n2 = r-q;       //获取切割实际数组长度
    int L[n1+1],R[n2+1];    //注意预留哨兵位置
    //将待切割数组放到俩个数组中
    for(k=0;k<n1;k++)
        L[k] = a[p+k];
        //display(L,n1);
    for(k=0;k<n2;k++)
        R[k] = a[q+k+1];
        // display(R,n2);
    L[n1] = 1000;           //加入哨兵
     //display(L,n1+1);
    R[n2] = 1000;

    /*开始对俩个数组排序*/
    for(k=p;k<=r;k++)
    {

        if(L[i]<=R[j])
        {
            a[k] = L[i];
            i = i+1;
        }
        else
        {
            a[k] = R[j];
            j = j+1;
        }
        //printf("此时A[k]=%d",a[k]);

    }



}
void display(int a[],int k)
{
   int i;
   for(i=0;i<k;i++)
   {
       printf("%d  ",a[i]);
   }
}
