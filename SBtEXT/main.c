#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k;
    for(i=1; i<5; i++)
    {
        /* 观察每行的空格数量，补全循环条件 */
        for(j=0;j<4-i;j++)
        {
            printf(" ");    //输出空格
        }
        /* 观察每行*号的数量，补全循环条件 */
        for( k=0;k<2i-1;k++)
        {
            printf("*");   //每行输出的*号
        }
        printf("\n");     //每次循环换行
    }
    return 0;
}
