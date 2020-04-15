#include<stdio.h>
#include<stdlib.h>
int n,a[50];
void combine(int low,int mid,int high)
{
    int i,j,k;
    int c[50];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    if(i>mid)
    {
        while(j<=high)
            c[k++]=a[j++];
    }
    if(j>high)
    {
        while(i<=mid)
            c[k++]=a[i++];
    }
    for(i=low;i<=high;i++)
        a[i]=c[i];
}
void split(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(high+low)/2;
        split(low,mid);
        split(mid+1,high);
        combine(low,mid,high);
    }
}
int main()
{
    int i;
    printf("n:");;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    split(0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}