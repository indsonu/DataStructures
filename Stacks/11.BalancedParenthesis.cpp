/*
  Created By : Sonu Sharma
  3-11-19      18:46
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        stack<char>S;
        int flg=0;
        for(int i=0;s[i];i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                S.push(s[i]);
            }
            else{
                if(!S.empty()){
                    if(s[i]==')' && S.top()=='(' || s[i]=='}' && S.top()=='{' || s[i]==']' && S.top()=='['){
                        S.pop();
                    } 
                    else{
                        flg=1;break;
                    }
                }
                else{
                    flg=1;break;
                }
            }
        }
        if(!flg && S.empty())cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
