#include <stdio.h>
#include <stdlib.h>
/*���ֲ��ҷ�*/
int  BinarySearch(int Arry[],int len,int value);
int main()
{
   int a[] = {1,3,5,7,9,13,15,17,19,21,23};     //���ַ���������Ҫ��������������
   int k ,position;
   k = sizeof(a)/sizeof(int);               //�������鳤��
   int m = 15;
   position = BinarySearch(a,k,m);           //���λ��ʱ��0������ʼ��
   printf("���ҵ�����λ��Ϊ����� %d ��Ԫ��",position+1);
}

int  BinarySearch(int Arry[],int len,int value)
{
    if(Arry==NULL||len<0)
    return -1;

    int start = 0;
    int end = len-1;
    /*���ֲ��ҷ�Ҫע��
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
