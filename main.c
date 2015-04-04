//输入一组数放在单链表中（以0结尾），删除第五个数，并打印删除后的结果，手动在内存释放掉该单链表
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node, *Linklist;

//函数功能：创建链表
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
            list=p;        //复制链表头指针
        }
        else
        {
            r->next=p;  //将节点一个个放入P中
        }
        r=p;
    }
    return list;     //返回头指针
}

//函数功能：插入元素到链表
//参数：*list链表指针，q链表当前位置，e待插入的元素
void Insertlist(Linklist *list,Linklist q,ElemType e)
{
    Linklist p;
    p=(Linklist)malloc(sizeof(Node));
    p->data=e;
    if(!*list)       //如果是空链表
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

//函数功能：链表中删除一个元素
//参数：*list链表指针，q链表当前位置
void DeLink(Linklist *list, Linklist q)
{
    Linklist r;
    if(q==*list)   //如果删除的的是第一个节点
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

//函数功能：销毁一个链表
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
     printf("请输入即将插入链表的元素，以0表示结束\n");
    q=l=CreatLinkList(1);

    scanf("%d",&e);
    while(e)
    {
        Insertlist(&l,q,e);
        q=q->next;
        scanf("%d",&e);
    }
    q=l;
    printf("链表的内容的是");
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    q=l;
    printf("\n\n删除第五个元素。。。\n");
    for(i=0;i<4;i++)
    {
        q=q->next;
    }
    DeLink(&l,q);
    q=l;
    printf("链表的内容是：");
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    DestoryLinkList(&l);
    return 0;
}
