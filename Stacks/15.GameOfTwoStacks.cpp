/*
  Created By : Sonu Sharma
  4-11-19      15:26
*/


// First Consider the case when we add all the element of single stack
// Then add element from the second stack and remove from first one 
// Keep a track of max Count


#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int ct=0,n,m,x;cin>>n>>m>>x;
        vector<int>V1(n),V2(m);
        for(int i=0;i<n;i++)cin>>V1[i];
        for(int i=0;i<m;i++)cin>>V2[i];
        int i=0,j=0,sum=0;
        while(i<n && sum+V1[i]<=x){
            sum+=V1[i++];
        }
        ct=i;
        while(j<m && i>=0){
            sum+=V2[j++];
            while(sum>x && i>0){
                sum-=V1[--i];
            }
            if(sum<=x && i+j>ct){
                ct=i+j;
            }
        }
        cout<<ct<<'\n';
    }
}
