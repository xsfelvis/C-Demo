#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int arry[]={2,4,3,1,5};
    int length = sizeof(arry)/sizeof(int);
    printf("排序前：");
    PrintArray(arry,length);

//    Quick_Sort(arry,0,4);
//    printf("Quick_Sort：");
//    PrintArray(arry,5);
//
//    printf("Bubble_Sort1：");
//    Bubble_Sort1(arry,length);
//    PrintArray(arry,length);
//
//    printf("Bubble_Sort2：");
//    Bubble_Sort2(arry,length);
//    PrintArray(arry,length);

//    printf("Bubble_Sort3：");
//    Bubble_Sort3(arry,length);
//    PrintArray(arry,length);


//    printf("Insert_Sort：");
//    Insert_Sort(arry,length);
//    PrintArray(arry,length);

//    printf("Hash_Sort：");
//    Hash_Sort(arry,length);
//    PrintArray(arry,length);

//    printf("Hash_Sort：");
//    Select_Sort(arry,length);
//    PrintArray(arry,length);

//    printf("Mergarry_Sort：");
//    Merg_Sort(arry,length);
//    PrintArray(arry,length);

    printf("Heap_Sort：");
    Heap_Sort(arry,length);
    PrintArray(arry,length);




    return 0;
}
