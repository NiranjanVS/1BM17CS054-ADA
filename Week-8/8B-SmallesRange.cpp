#include<bits/stdc++.h>
using namespace std;
int heap[20];
int n;
bool h;
int minHeap()
{
    for(int i=n/2;i>0;i--)
    {
        int k = i;
        int j;
        int v = heap[k];
        h = false;
        while(!h && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(heap[j]>heap[j+1])
                {
                    j+=1;
                }
                if(v<=heap[j])
                {
                    h = true;
                }
                else
                {
                    heap[k]=heap[j];
                    k=j;
                }   
            }
            heap[k]=v;
        }
        
    }
    return 0;
}
int main()
{
    cout<<"Enter size : ";
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>heap[i];
    minHeap();
    for(int i=1;i<=n;i++)
        cout<<heap[i];
    return 0;
}