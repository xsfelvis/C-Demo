<<<<<<< HEAD
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
=======
#include <stdio.h>
#include <stdlib.h>
int count = 0;  //统计成功的全局变量
int notDanger(int row, int j, int (*chess)[8])
{
    int i, k, flag1=0, flag2=0, flag3=0, flag4=0, flag5=0;
    //判断列方向
    for (i=0; i<8; i++)
    {
        if(*(*(chess+i)+j) != 0)
       {
           flag1 = 1;
        break;
       }
    }
    //判断左上方
    for (i=row, k=j; i>=0&&k>=0; i--,k--)
    {
        if(*(*(chess+i)+k) != 0)
      {
           flag2 = 1;
        break;
      }
    }
    //判断右下方
    for (i=row, k=j; i<8&&k<8; i++,k++)
    {
        if(*(*(chess+i)+k) != 0)
       {
           flag3 = 1;
        break;
       }
    }
    //判断右上方
     for (i=row, k=j; i>=0&&k<8; i--,k++)
    {
        if(*(*(chess+i)+k) != 0)
      {
           flag4 = 1;
        break;
      }
    }
    //判断左下方
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

void EightQueen(int row, int n, int (*chess)[8] )   //参数row表示起始行，n为列数，指针为指向棋盘每一行的的指针
{
    int chess2[8][8], i, j;

    //存放棋盘临时位置
    for ( i=0; i<8; i++)
    {
        for ( j=0; j<8; j++)
        {
            chess2[i][j] = chess[i][j];
        }
    }

    //结束条件
    if(8 == row)
    {
        printf("第 %d 种\n",count+1);
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
    //进入递归
    else
    {
        for( j=0; j<n; j++)                    //每一列进行扫描
        {
            if( notDanger(row, j, chess))      //判断位置是否危险
            {
                for( i=0; i<8; i++)
                {
                     *(*(chess2+row)+i) = 0;
                }
                    *(*(chess2+row)+j) = 1;    //不危险的位置赋值为表明此处不危险
                    EightQueen( row+1, n, chess2);
            }
        }
    }
}

int main()
{
    int chess[8][8], i, j;

    //初始化棋盘
    for( i=0; i<8; i++ )
    {
        for( j=0; j<8; j++)
        {
            chess[i][j] = 0;
        }

    }

     EightQueen( 0, 8, chess);     //第0行开始，总共有8列，起始指针为chess
     printf("总共有%d种解法\n\n", count);
     return 0;
>>>>>>> 0df19e97d471cb323dd89bc652d25ca72fd7fcc4
}
