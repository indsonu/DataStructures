/*
  Created By : Sonu Sharma
  9-11-12      17:13
*/
// Using two Queues and some implementation of C++

#include<bits/stdc++.h>
using namespace std;
void SolveTruckTour(){
    int64_t i=0,finale,q;cin>>q;
    queue<pair<pair<int64_t,int64_t>,int>>Q,ans;
    while(q--){
        int a,b;cin>>a>>b;
        Q.push({{a,b},i});
        i++;
    }
    while (!Q.empty()) {
        finale=Q.front().second;
        int64_t sum=0;
        while(!Q.empty() && sum+Q.front().first.first>=Q.front().first.second){
            ans.push(Q.front());
            sum+=Q.front().first.first-Q.front().first.second;
            Q.pop();
        }
        if(Q.empty())break;
        if(ans.empty()){
             ans.push(Q.front());
             Q.pop();
        }
        while(!ans.empty()){
            Q.push(ans.front());
            ans.pop();
        }

    }
    cout<<finale;
}
int main(){
    SolveTruckTour();
}
