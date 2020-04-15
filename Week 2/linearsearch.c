#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a;
    int n;
    int i,j,key;
    int flag,ntc;
    FILE *testcase;
    testcase = freopen("linseatestcase.txt","r",stdin);
    scanf("%d",&ntc);
    for(j=0;j<ntc;j++)
    {
        scanf("%d",&n);
        a=(int*) malloc(n*sizeof(int));
        scanf("%d",&key);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==key)
            {
                flag=1;
                break;
            }
            else
            {
                flag=-1;
            }
        }
        printf("%d\n",flag);
    }
    fclose(testcase);
}

