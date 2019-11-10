/*
  Created By : Sonu Sharma
  10-11-19     11:33
*/
// Here first store all the elements of the stack 
// in the respective recursive call then treat a 
// single element as separate Q which is :
//        -> if you are given a stack then how you will insert an element at the top of the stack - 


#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&S,int x){
    if(S.empty()){
        S.push(x);
        return;
    }
    else{
        int a=S.top();
        S.pop();
        insertAtBottom(S,x);
        S.push(a);
    }
}
void Rev(stack<int>&S){
    if(S.empty()==false){
        int x=S.top();
        S.pop();
        Rev(S);
        insertAtBottom(S,x);
    }
}
void ReverseStackUsingRecursion(){
    int n;cin>>n;
    stack<int>S;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        S.push(a);
    }
    Rev(S);
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
}
int main(){
    ReverseStackUsingRecursion();
}
