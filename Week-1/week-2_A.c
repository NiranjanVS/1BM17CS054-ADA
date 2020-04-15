//program to find the k th smallest element in the unsorted array using Selection sort
#include<stdio.h>
#include<stdlib.h>
int main()
{
   int *a,i,j,minI,n,temp,k;
   printf("Enter the number of elements : ");
   scanf("%d",&n);
   a =malloc(n*sizeof(int));
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   printf("Enter the value of 'k' : ");
   scanf("%d",&k);
   //selection sort algorithm
   for(i=0;i<k;i++)
   {
       minI=i;
       for(j=i;j<n;j++)
       {
           if(a[j]<a[minI])
           {
               minI=j;
           }
       }
       temp=a[minI];
       a[minI]=a[i];
       a[i]=temp;
   }
   //printing the k th smallest element
   printf("%d ",a[k-1]);
}

