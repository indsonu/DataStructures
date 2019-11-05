/*
  Created By : Sonu Sharma
  5-11-19      12:36
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>V(n),ans(n);
    for(int i=0;i<n;i++){
        cin>>V[i];
    }
    stack<int>S;
    for(int i=0;i<n;i++){
        while (!S.empty() && V[S.top()]<V[i]) {
            S.pop();
        }
        if(S.empty()){
            ans[i]=i+1;
        }
        else{
            ans[i]=i-S.top();
        }
        S.push(i);
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
	cout<<"END";
}
