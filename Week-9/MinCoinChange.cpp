#include<bits/stdc++.h>
using namespace std; 
#define INF 999
//#define N 3
//#define A 8
int N,A;
void coinChange(int d[], int C[], int S[]) {
  int i, p, min, coin;
  
  //when amount is 0
  //then min coin required is 0
  C[0] = 0;
  S[0] = 0;
  
  for(p = 1; p <= A; p++) {
    min = INF;
    for(i = 1; i <= N; i++) {
      if(d[i] <= p) {
        if(1 + C[p - d[i]] < min) {
          min = 1 + C[p - d[i]];
          coin = i;
        }
      }
    }
    C[p] = min;
    S[p] = coin;
  }
}

void coinSet(int d[], int S[]) {
  int a = A;
  while(a > 0) {
        cout<<"Use coin of denomination: "<< d[S[a]];
    a = a - d[S[a]];
  }
}

void display(int arr[]) {
  int c;
  for(c = 0; c <= A; c++) {
    printf("%5d", arr[c]);
  }
  cout<<"\n";
}
int main() {
    
    cout<<"enter no.of denominations=";
    cin>>N;
    int d[N+1];
    d[0]=0;
cout<<"enter the denominations\n";
for(int i=1;i<=N;i++){
    cin>>d[i];
}
cout<<"enter the amount";
cin>>A;
  int C[A+1];
  int S[A+1];
  coinChange(d, C, S);
        
  cout<<"\nC[p]\n";
  display(C);
  
  cout<<"\nS[p]\n";
  display(S);

  cout<<"\nMin. no. of coins coin required to make change for amount "<<A<<" = "<< C[A]<<"\n";
  
  cout<<"\nCoin Set\n";
  coinSet(d, S);
    
  return 0;
}
