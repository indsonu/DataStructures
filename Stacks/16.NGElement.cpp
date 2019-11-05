/*
   Created By : Sonu Sharma
   5-11-19      10:55
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    stack<int>S;
    vector<int>V(n);
    for(int i=0;i<n;i++)cin>>V[i];
    S.push(V[0]);
    for(int i=1;i<n;i++){
        if(S.empty()){
            S.push(V[i]);
            continue;
        }
        // if Stack Not empty then
        // Keep checking and popping
        // until you will find the ans:
        while(!S.empty() && S.top()<V[i]){
            cout<<S.top()<<" "<<V[i]<<endl;
            S.pop();
        }
        S.push(V[i]);
    }
    while(!S.empty()){
        cout<<S.top()<<" "<<"-1"<<endl;
        S.pop();
    }
}
