
//核心函数，对数组A[p,r]进行就地重排，将小于A[r]的数移到数组前半部分，将大于A[r]的数移到数组后半部分。
int Partition(int *arr,int start,int end)
{
    int sential = arr[end];
    int i = start-1;
    int j ;
    int m;
    int n;
    for(j=start; j<end; j++) {
        if (arr[j]< sential){
            i = i + 1;
            #if DEBUG
            m = arr[i];
            n = arr[j];
            #endif // DEBUG
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[end]);
    return i+1;
}

void Quick_Sort(int *arr,int start,int end)
{
    if(start<end){
        int mid;
        mid = Partition(arr,start,end);
        Quick_Sort(arr,start,mid-1);
        Quick_Sort(arr,mid+1,end);
    }
}
