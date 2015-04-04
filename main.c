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
}
