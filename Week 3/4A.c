#include<stdio.h>
#include<stdlib.h>
int adjacent[20][20];
int visited[20];
int n;
void DFS(int vtx)
{
    int i;
    printf("%d ",vtx);
    visited[vtx]=1;
    for(i=0;i<n;i++)
    {
        if(adjacent[vtx][i] && !visited[i])
            DFS(i);
    }
}

void connected()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            DFS(i);
            printf("\n");
        }
    }
}

int main()
{   
    int i,j;
    //printf("n : ");
    scanf("%d",&n);//printf("Enter the adjacent matrix : ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&adjacent[i][j]);
        }
        visited[i]=0;
    }
    connected();
}