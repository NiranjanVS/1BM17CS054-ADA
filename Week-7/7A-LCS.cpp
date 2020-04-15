#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void lcs(string x,string y,int m,int n)
{
    int l[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                l[i][j]=0;
            else if(x[i-1]==y[j-1])
                l[i][j]=(int)l[i-1][j-1]+1;
            else
                l[i][j]= max((int)l[i-1][j],(int)l[i][j-1]);
        }
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            cout<<l[i][j]<<" ";
        }
        cout<<"\n";
    }
    int idx = l[m][n];
    char lcs[idx];
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            lcs[idx-1] = x[i-1];
            i--;
            j--;
            idx--;
        }
        else if(l[i-1][j]>l[i][j-1])
            i--;
        else
            j--;
    }
    for(i=0;i<l[m][n];i++)
        cout<<lcs[i];
    cout<<endl;
}
int main()
{
    string st1,st2;
    int m,n;
    cout<<"Enter the String(1) : ";
    cin>>st1;
    cout<<"Enter the String(2) : ";
    cin>>st2;
    m = st1.length();
    n = st2.length();
    lcs(st1,st2,m,n);
}