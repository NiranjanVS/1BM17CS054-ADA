#include<bits/stdc++.h>
using namespace std;
void knapsack(int weights[],int values[],int n,int W)
{
    int V[n+1][W+1];
    for(int i=0;i<=n;i++)
        V[i][0]=0;
    for(int j=1;j<=W;j++)
        V[0][j]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if((j-weights[i-1])>=0)
                V[i][j]=max(V[i-1][j],values[i-1]+V[i-1][j-weights[i-1]]);
            else
                V[i][j]=V[i-1][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Max value : "<<V[n][W];
}
int main()
{
    int n;
    int Wei;
    cout<<"Number of items : ";
    cin>>n;
    int w[n],v[n];
    cout<<"Enter the values and weights"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        cin>>w[i];
    }
    cout<<"Enter the max weight of the knapsack : ";
    cin>>Wei;
    knapsack(w,v,n,Wei);
}
