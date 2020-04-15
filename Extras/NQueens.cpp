#include<bits/stdc++.h>
using namespace std;
int x[10];
bool flag=false;
bool place(int k,int i){
    for(int j=1;j<=k-1;j++){
        if((x[j]==i) || (abs(x[j]-i)==abs(j-k))){
            return false;
        }
    }
    return true;
}
void Nqueen(int k,int n){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
            if(k==n){
                for(int r=1;r<=n;r++){
                    cout<<x[r];
                    cout<<",";
                }
                flag=true;
                cout<<"\n";
            }
            else{
                Nqueen(k+1,n);
            }
        }
    }
}
int main(){
    int n;
    cout<<"enter number of queens";
    cin>>n;
    for(int i=0;i<n;i++){
        x[i]=0;
    }
    Nqueen(1,n);
    if(!flag){
        cout<<"No solution";
    }
}