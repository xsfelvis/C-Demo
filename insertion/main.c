#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*��������*/
//��������
void insertSort(int a[]);
void display(int a[],int k);

int main()
{   int k=0;
    int a[] = {5,2,4,6,1,3};
    k = sizeof(a)/sizeof(a[0]);
    insertSort(a);
    printf("��������鳤��Ϊ��%d\n",k);
    display(a,k);
    return 0;
}
void insertSort(int a[])
{
    int i=0,j=0,key=0;
    for(j=1;j<6;j++)
    {
        key = a[j]; //��ȡ��ǰԪ�ط���ؼ���
        i = j-1;        //��ǰԪ�ص�ǰһ��Ԫ��
        while(i>=0&&a[i]>key)  //��֤���մ�С����˳������
        {
            a[i+1]=a[i];
            i=i-1;

        }                      //�ҳ�Ҫ�����λ��i���ǹؼ�����
         printf("���ǲ���i%d ",i+1);
         a[i+1] = key;          //���Ĵ���

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

