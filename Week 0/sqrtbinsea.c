#include<stdio.h>
int main()
{
    int start=0,end,mid,x,sqrt;
    printf("Enter the vale of x : ");
    scanf("%d",&x);
    end=x;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(x==mid*mid)
        {
            sqrt=mid;
            break;
        }
        else if(mid*mid<x)
        {
            start=mid+1;
            sqrt=mid;
        }
        else
        {
            end=mid-1;
        }
    }
    printf("%d",sqrt);
}
