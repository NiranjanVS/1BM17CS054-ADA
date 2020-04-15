#include<stdio.h>
#include<stdlib.h>
int n,a[50];
int partition(int low , int high)
{
    int pivot=a[low];
    int temp;
    int i=(low+1);
    int j=high;
    while(1)
    {
        while( a[i]<=pivot && i<=high)
            i++;
        while(a[j]>pivot && j>=low)
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else
        {
            a[low]=a[j];
            a[j]=pivot;
            return j;
        }    
    }
}
int quicksort(int low,int  high)
{
    int pivot;
    if(low<high)
    {
        pivot = partition(low,high);
        quicksort(low,pivot-1);
        quicksort(pivot+1,high);
    }
}
int main()
{
    int i;
    printf("n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(0,n-1);
    for(i=0;i<n;i++)
        printf("%d",a[i]);
}