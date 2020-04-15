#include<bits/stdc++.h>
using namespace std;
int c[20][20];
void primsAlgo(int n){
    int ne=0,mini;
    int mincost=0,u,v;
    int elec[n];
    for(int i=1;i<=n;i++)
    {
        elec[i]=1;
    }
    elec[1]=1;
    while(ne!=n-1)
    {
        mini=9999;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
            if(elec[j]==1)
            {
                if(c[i][j]<mini)
                {
                    mini=c[i][j];
                    u=i;
                    v=j;
                }
            }
        }
    }
    if(elec[v]==1){
        cout<<u<<"->"<<v<<" = "<<mini<<endl;
        elec[v]=0;
        ne=ne+1;
        mincost=mincost+mini;
    }
    c[u][v]=9999;
    c[v][u]=9999;
    }
    cout<<"Minimum Cost = "<<mincost<<endl;

}
int main(){
   int n;
   cout<<"Enter the number of Vertices : ";
   cin>>n;
   cout<<"enter cost matrix : "<<endl;
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=n;j++)
    {
        cin>>c[i][j];
    }
   }
   primsAlgo(n);
   return 0;
}
