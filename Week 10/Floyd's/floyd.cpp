#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n;
int floyd(int **a)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				//a[i,j] = min(a[i][j],a[i][j]+a[k][j]);
				int mn = a[i][k]+a[k][j];
				if(mn < a[i][j])
				{
					a[i][j]=mn;
				}
			}
		}
	}
	cout<<"The resultant matrix is "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
int main()
{
	int **adjmat;
	cout<<"Enter the number of Vertices : ";
	cin>>n;
	cout<<n<<endl;
	adjmat = new int* [n];
	cout<<"Enter the adjacent matrix "<<endl;
	for(int i=0;i<n;i++)
	{
		adjmat[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			cin>>adjmat[i][j];
			cout<<adjmat[i][j]<<" ";
		}
		cout<<endl;
	}
	floyd(adjmat);
	return 0;
}