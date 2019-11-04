/*
  Created By : Sonu Sharma
  4-11-19      11:09
*/
// Key Concept : Consider the maximum height by including the current block if some smaller element 
//               occur . Try to spend some time on this problem and practise the implementation by 
//               yourself and eventually you will get the intuition by urself

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>V(n);
    stack<int>S;
    int ans=0;
    for(int i=0;i<n;i++)cin>>V[i];
    int i;
    for(i=0;i<n;i++){
        if(S.empty()){
            S.push(i);
        }
        else{
            if(V[i]<V[S.top()]){
                while(!S.empty() && V[i]<V[S.top()]){
                    int j=S.top();
                    S.pop();
                    if(S.empty()){
                        ans=max(ans,V[j]*i);
                    }
                    else{
                        ans=max(ans,V[j]*(i-S.top()-1));
                    }
                }
            }
            S.push(i);
        }
    }
    while(!S.empty()){
        int j=S.top();
        S.pop();
        if(S.empty()){
            ans=max(ans,V[j]*i);
        }
        else{
            ans=max(ans,V[j]*(i-S.top()-1));
        }
    }
    cout<<ans;
}
