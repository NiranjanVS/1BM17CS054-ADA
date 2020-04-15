#include<stdio.h>
#include<stdlib.h>
int mtrx[20][20];
int visited[20][20];
int r,c;
int icount=0;

int isSafe(int row,int col)
{
    return ((row>=0)&&(row<r)&&(col>=0)&&(col<c)&&(mtrx[row][col] && !visited[row][col]));
}

void DFS(int row,int col)
{
    int nrows[]={-1,-1,-1,0,0,1,1,1};
    int ncols[]={-1,0,1,-1,1,-1,0,1};
    int i;
    visited[row][col]=1;
    for(i=0;i<8;i++)
    {
        if(isSafe(row+nrows[i],col+ncols[i]))
        {
            DFS(row+nrows[i],col+ncols[i]);
        }
    }
}

int islandCount()
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(mtrx[i][j] && !visited[i][j])
            {
                DFS(i,j);
                ++icount;
            }

        }
    }
    return icount;
}
int main()
{
    int i,j;
    scanf("%d",&r);
    scanf("%d",&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
           scanf("%d",&mtrx[i][j]);
           visited[i][j]=0; 
        }
    }
    islandCount();
    printf("%d",icount);
}