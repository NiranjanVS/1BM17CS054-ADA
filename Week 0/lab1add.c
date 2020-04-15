#include<stdio.h>
#include<stdlib.h>
int main()
{
    int start=0,end,mid,key,n;
    int i,index=-1;
    int *a;
    int first=-1,last=-1,count=0;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    end=n-1;
    a=(int*) malloc(n*sizeof(int));
    printf("Enter the elements of the array : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the key : ");
    scanf("%d",&key);
    while(start<=end)
    {
      mid=(start+end)/2;
      if(a[mid]==key)
      {
          index=mid;
          break;
      }
      else if(a[mid]>key)
        end=mid-1;
      else
        start=mid+1;
    }
    if(index!=-1)
    {
        for(i=index;i>=0;i--)
        {
            if(a[i]==key)
            {
                count++;
                first=i;
            }
            else
                break;
        }
        for(i=index+1;i<n;i++)
        {
            if(a[i]==key)
            {
                count++;
                last=i;
            }
            else
                break;
        }

    }
    printf("start index : %d\nend index : %d\ncount : %d",first,last,count);
}
