/*
  Created By : Sonu Sharma
  10-11-19     16:22
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>V(n);
        for(int i=0;i<n;i++){
            cin>>V[i];
        }
        int k;cin>>k;
        deque<int>Q;
        for(int i=0;i<k;i++){
            if(V[i]<0){
                Q.push_back(i);
            }
        }
        for(int i=k;i<n;i++){
            if(Q.empty()){
                cout<<0<<" ";
            }
            else{
                cout<<V[Q.front()]<<" ";
            }
            while(!Q.empty() && Q.front()<=i-k){
                Q.pop_front();
            }
            if(V[i]<0){
                Q.push_back(i);
            }
        }
        if(Q.empty()){
            cout<<0<<" ";
        }
        while(!Q.empty()){
            cout<<V[Q.front()]<<" ";
            Q.pop_front();
            break;
        }
        cout<<'\n';
    }
}
