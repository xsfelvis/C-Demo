<<<<<<< HEAD
//����һ�������ڵ������У���0��β����ɾ���������������ӡɾ����Ľ�����ֶ����ڴ��ͷŵ��õ�����
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node, *Linklist;

//�������ܣ���������
Linklist CreatLinkList(int n)
{
    Linklist p,r,list=NULL;
    ElemType e;
    int i;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&e);
        p=(Linklist)malloc(sizeof(Node));
        p->data=e;
        p->next=NULL;
        if (!list)
        {
            list=p;        //��������ͷָ��
        }
        else
        {
            r->next=p;  //���ڵ�һ��������P��
        }
        r=p;
    }
    return list;     //����ͷָ��
}

//�������ܣ�����Ԫ�ص�����
//������*list����ָ�룬q����ǰλ�ã�e�������Ԫ��
void Insertlist(Linklist *list,Linklist q,ElemType e)
{
    Linklist p;
    p=(Linklist)malloc(sizeof(Node));
    p->data=e;
    if(!*list)       //����ǿ�����
    {
        *list=p;
        p->next=NULL;
    }
    else
    {
        p->next=q->next;
        q->next=p;
    }
}

//�������ܣ�������ɾ��һ��Ԫ��
//������*list����ָ�룬q����ǰλ��
void DeLink(Linklist *list, Linklist q)
{
    Linklist r;
    if(q==*list)   //���ɾ���ĵ��ǵ�һ���ڵ�
    {
        *list=q->next;
        free(q);
    }
    else
    {
        for(r=*list;r->next!=q;r=r->next)
        ;

        if(r->next!=NULL)
        {
            r->next=q->next;
            free(q);
        }
    }
}

//�������ܣ�����һ������
void DestoryLinkList(Linklist *list)
{
    Linklist p,q;
    p=*list;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    *list=NULL;
}

int main()
{
    int e,i;
    Linklist l,q;
     printf("�����뼴�����������Ԫ�أ���0��ʾ����\n");
    q=l=CreatLinkList(1);

    scanf("%d",&e);
    while(e)
    {
        Insertlist(&l,q,e);
        q=q->next;
        scanf("%d",&e);
    }
    q=l;
    printf("��������ݵ���");
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    q=l;
    printf("\n\nɾ�������Ԫ�ء�����\n");
    for(i=0;i<4;i++)
    {
        q=q->next;
    }
    DeLink(&l,q);
    q=l;
    printf("����������ǣ�");
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    DestoryLinkList(&l);
    return 0;
=======
#include <stdio.h>
#include <stdlib.h>
int count = 0;  //ͳ�Ƴɹ���ȫ�ֱ���
int notDanger(int row, int j, int (*chess)[8])
{
    int i, k, flag1=0, flag2=0, flag3=0, flag4=0, flag5=0;
    //�ж��з���
    for (i=0; i<8; i++)
    {
        if(*(*(chess+i)+j) != 0)
       {
           flag1 = 1;
        break;
       }
    }
    //�ж����Ϸ�
    for (i=row, k=j; i>=0&&k>=0; i--,k--)
    {
        if(*(*(chess+i)+k) != 0)
      {
           flag2 = 1;
        break;
      }
    }
    //�ж����·�
    for (i=row, k=j; i<8&&k<8; i++,k++)
    {
        if(*(*(chess+i)+k) != 0)
       {
           flag3 = 1;
        break;
       }
    }
    //�ж����Ϸ�
     for (i=row, k=j; i>=0&&k<8; i--,k++)
    {
        if(*(*(chess+i)+k) != 0)
      {
           flag4 = 1;
        break;
      }
    }
    //�ж����·�
    for (i=row, k=j; i<8&&k>=0; i++,k--)
    {
        if(*(*(chess+i)+k) != 0)
       {
           flag5 = 1;
        break;
       }
    }
    if( flag1||flag2||flag3||flag4||flag5)
    {
        return 0;

    }
    else
    {
            return 1;
    }




}

void EightQueen(int row, int n, int (*chess)[8] )   //����row��ʾ��ʼ�У�nΪ������ָ��Ϊָ������ÿһ�еĵ�ָ��
{
    int chess2[8][8], i, j;

    //���������ʱλ��
    for ( i=0; i<8; i++)
    {
        for ( j=0; j<8; j++)
        {
            chess2[i][j] = chess[i][j];
        }
    }

    //��������
    if(8 == row)
    {
        printf("�� %d ��\n",count+1);
        for( i=0; i<8; i++)
        {
            for( j=0; j<8; j++)
            {
                printf("%d ", *(*(chess2+i)+j));
            }
            printf("\n");
        }
        printf("\n");
        count++;
    }
    //����ݹ�
    else
    {
        for( j=0; j<n; j++)                    //ÿһ�н���ɨ��
        {
            if( notDanger(row, j, chess))      //�ж�λ���Ƿ�Σ��
            {
                for( i=0; i<8; i++)
                {
                     *(*(chess2+row)+i) = 0;
                }
                    *(*(chess2+row)+j) = 1;    //��Σ�յ�λ�ø�ֵΪ�����˴���Σ��
                    EightQueen( row+1, n, chess2);
            }
        }
    }
}

int main()
{
    int chess[8][8], i, j;

    //��ʼ������
    for( i=0; i<8; i++ )
    {
        for( j=0; j<8; j++)
        {
            chess[i][j] = 0;
        }

    }

     EightQueen( 0, 8, chess);     //��0�п�ʼ���ܹ���8�У���ʼָ��Ϊchess
     printf("�ܹ���%d�ֽⷨ\n\n", count);
     return 0;
>>>>>>> 0df19e97d471cb323dd89bc652d25ca72fd7fcc4
}
