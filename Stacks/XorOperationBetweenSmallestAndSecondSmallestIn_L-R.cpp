/*
  Created By : Sonu Sharma
  3-11-19      18:35
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans=0,n;cin>>n;
    vector<int64_t>V(n);
    for(int i=0;i<n;i++)cin>>V[i];
    stack<int64_t>S;
    for(int i=0;i<n;i++){
        while(!S.empty()){
            int mx=S.top()^V[i];
            if(mx>ans){        // Checking the Yield Condition
                ans=mx;
            }
            if(S.top()>V[i]){  // Removing the current max and adding the current min 
                S.pop();
            }
            else break;
        }
        S.push(V[i]);
    }
    cout<<ans;
}
