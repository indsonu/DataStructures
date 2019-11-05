/*
  Created By : Sonu Sharma
  5-11-19      16:27
*/

// NGE(Next Greater Element) in an circular Array
#include<bits/stdc++.h>
using namespace std;
void NGE();
int main(){
    // NGE();
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
    int ans[n]={0};
    stack<int>S;
    // I use 2 twice the size of the array because
    // First scan may fill wrong entries
    // But second will definitely give me
    // right entries
    for(int i=2*n-1;i>=0;i--){
        while(!S.empty() && a[S.top()]<=a[i%n]){
            S.pop();
        }
        ans[i%n]=(S.empty())?-1:a[S.top()];
        S.push(i%n);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
void NGE(){
      int a[]={10,9,8,7,5,6,7,8};
      int n=sizeof(a)/sizeof(a[0]);
      stack<int>S;
      for(int i=0;i<n;i++){
          while(!S.empty()&& a[S.top()]<a[i]){
              cout<<a[S.top()]<<" NGE-> "<<a[i]<<endl;
              S.pop();
          }
          S.push(i);
      }
      while(!S.empty()){
          cout<<a[S.top()]<<" NGE-> "<<(-1)<<endl;
          S.pop();
      }
}

