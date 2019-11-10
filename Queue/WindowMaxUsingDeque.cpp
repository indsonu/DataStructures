/*
  Created By : Sonu Sharma
  10-11-19     12:05
*/

// 2 things are needed for this problem 
//    1. is our element present in the 
//    window or not.
//    2. is front element maximum in the window
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n;
    vector<int>V(n);
    for(int i=0;i<n;i++){
        cin>>V[i];
    }
    cin>>k;
    deque<int>Q(k);
    for(int i=0;i<k;i++){
        while (!Q.empty() && V[i]>V[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    for(int i=k;i<n;i++){
        cout<<V[Q.front()]<<" ";
        while(!Q.empty() && Q.front()<=i-k){
            Q.pop_front();
        }
        while(!Q.empty() && V[Q.back()]<V[i]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    while(!Q.empty()){
        cout<<V[Q.front()]<<" ";
        Q.pop_front();
    }
}
