#include<stdio.h>
#include<stdlib.h>
int a[50],countm=0;
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
        countm+=1;
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
void selection(int b[],int n)
{
    int minI,i,j,temp,counts=0;
    for(i=0;i<n;i++)
   {
       minI=i;
       for(j=i+1;j<n;j++)
       {
           counts = counts+1;
           if(b[j]<b[minI])
           {
               minI=j;
           }
       }
       temp=b[minI];
       b[minI]=b[i];
       b[i]=temp;
   }
    /*for(i=0;i<n;i++)
        printf("%d ",b[i]);
    printf("\n");*/
     printf("selection sort : %d\n",counts);
}
void bubble(int b[],int n)
{
    int i,j,temp,count=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            count = count+1;
            if(b[j+1]<b[j])
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
            
        }
    }
    /*for(i=0;i<n;i++)
        printf("%d ",b[i]);
    printf("\n");*/
    printf("bubble sort : %d \n",count);
}
int main()
{
    int n,b[50],i;
    printf("n:");
    scanf("%d",&n);
    printf("enter the number");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    selection(b,n);
    bubble(b,n);
    split(0,n-1);
    printf("merge sort :%d \n",countm);
}