#include<bits/stdc++.h>
using namespace std;
int a[10][10],n;
void input(){
    int c=0,b=0;
    cout<<"enter no. of tasks \n";
    cin>>n;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    while(c!= -1 || b!=-1){
        cout<<"enter dependencies [b:c]........[-1,-1] to stop\n";
        cin>>b;
        cin>>c;
        if(c!= -1 || b!=-1){
            a[c][b]=1;}
        }
}
void findorder(){
    int indegree[10],k,s[10],top=-1;
    for(int i=0;i<n;i++){
        indegree[i]=0;
        for(int j=0;j<n;j++){
            indegree[i] +=a[j][i];
        }
    }
    for(int i=0;i<n;i++){
            if(indegree[i]==0){
                s[++top]=i;
            }
    }
    while(top!=-1 ){
            k=s[top--];
            cout<<k<<",";
            indegree[k]=-1;
            for(int r=0;r<n;r++){
                if(a[k][r]==1){
                    indegree[r] -=1;
                    if(indegree[r]== 0){
                        s[++top]=r;
                    }
                }
           
            }
    }
}
int main(){
    input();
    findorder();
}