//bubbleSort
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a,n,i,j,temp,k;
    printf("n : ");
    scanf("%d",&n);
    a = malloc(n*sizeof(int));
    printf("Enter the elements of the array : \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("k : ");
    scanf("%d",&k);
    //bubbleSort algorithm
    for(i=0;i<k;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=n-1;i>=n-k;i--)
        printf("%d ",a[i]);
}

