/*#include<stdio.h>
int main()
{
    int a[15];
    int i,n;
    int max=-999;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    printf("Enter the elements of the Array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    printf("%d",max);
}*/



#include<stdio.h>
int FindMax(int a[],int n)
{
    int max=-999;
    int i;
     for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
int main()
{
       int a[15];
    int i,n;
    int max=-999;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    printf("Enter the elements of the Array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    max = FindMax(a,n);
    printf("%d",max);
    return 0;
}