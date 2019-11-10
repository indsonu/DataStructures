/*
  Created By : Sonu Sharma
  10-11-19     15:30
*/

#include<bits/stdc++.h>
using namespace std;
void GenerateBinary(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        queue<string>Q;
        Q.push("1");
        while(n--){
            string s1=Q.front();
            Q.pop();
            cout<<s1<<" ";
            Q.push(s1+"0");
            Q.push(s1+"1");
        }
        cout<<'\n';
    }
}
int main(){
    GenerateBinary();
}
