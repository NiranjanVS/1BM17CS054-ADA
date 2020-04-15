#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,i,start,end,mid,rpnt,n,key,flag=0;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<a[i-1])
        {
            rpnt=i;
        }
    }
    printf("Enter the key value : ");
    scanf("%d",&key);
    //searching
    if(key>=a[0])
    {
        start=0;
        end=rpnt-1;
    }
    else
    {
        start=rpnt;
        end=n-1;
    }
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(a[mid]==key)
        {
            printf("key found at index %d",mid);
            flag=1;
            break;
        }
        else if(key>a[mid])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    if(flag==0)
        printf("key not found..!!");
}

