#include <bits/stdc++.h>
using namespace std;

struct minHeapNode{
   
   int val;
   int listIdx;
   int nextListIdx;
};

void heapify(minHeapNode* harr, int k, int i){

   int smallest = i;
   int left = 2*i + 1;
   int right = 2*i + 2;

   if (left < k && harr[left].val < harr[smallest].val){
      smallest = left;
   }

   if (right < k && harr[right].val < harr[smallest].val){
      smallest = right;
   }

   if (smallest != i){
      swap(harr[i], harr[smallest]);
      heapify(harr, k, smallest);
   }
}

void buildHeap(minHeapNode* harr, int k){

   int i = k/2 - 1;
   while(i >= 0){
      heapify(harr, k, i);
      i--;
   }
}

void replace(minHeapNode* harr, int k, minHeapNode node){
   harr[0] = node;
   heapify(harr, k, 0);
}

void smallestRange(int** arr, int n, int k){

   int max = INT_MIN, min = INT_MAX;
   int range = INT_MAX;
   int start, end;
   
   minHeapNode* harr = new minHeapNode[k];
   
   for (int i = 0; i < k; i++){
      harr[i].val = arr[i][0];
      harr[i].listIdx = i;
      harr[i].nextListIdx = 1;

      if (max < harr[i].val){
         max = harr[i].val;
      }
   }

   buildHeap(harr, k);

   while(true){
      minHeapNode temp = harr[0];
      min = temp.val;
      if (range > max - min + 1){
         range  = max - min + 1;
         start = min;
         end = max;
      }

      if (temp.nextListIdx < n){
         temp.val = arr[temp.listIdx][temp.nextListIdx];
         temp.nextListIdx += 1;

         if (max < temp.val){
            max = temp.val;
         }
      }else{
         break;
      }

      replace(harr, k, temp);
   }

   cout << "Smallest Range : ["<< start<<" : "<< end<<"]"<< endl;
}

int main(){
   int k, n;
   cin >> k >> n;
   int** arr = new int* [k];
   for(int i = 0; i < k; i++){
      arr[i] = new int[n];
      for (int j = 0; j < n; j++){
         cin >> arr[i][j];
      }
   }

   smallestRange(arr, n, k);
}