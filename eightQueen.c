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
}
