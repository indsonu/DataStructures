/*
  Created By : Sonu Sharma  
  9-11-19      8:51
*/
//  Basic idea is to put all the elements from one 
//  stack into the other than do ? toping : poping

// One more thing to care about is : if queries is 
// of type 10^5 then time complexity may go preety
// bad so what else can we do is , whenever we
// encountered the pop or top operation we fill 
// our stack at that moment so that overall 
// complexity not reach to worst part 


#include<bits/stdc++.h>
using namespace std;
struct MyQueue{
    stack<int>S1;
    stack<int>S2;
    void push(int x){
        S1.push(x);
    }
    void pop(){
       if(S2.empty()){
           while(!S1.empty()){
               S2.push(S1.top());
               S1.pop();
           }
           S2.pop();
       }
       else{
           S2.pop();
       }
    }
    int top(){
        int t;
        if(S2.empty()){
           while(!S1.empty()){
               S2.push(S1.top());
               S1.pop();
           }
           t=S2.top();
       }
       else{
           t=S2.top();
       }
       return t;
    }    
};

int main(){
    int q;cin>>q;
    MyQueue S;
    while(q--){
        int type;cin>>type;
        switch(type){
        case 1:{int x;cin>>x;S.push(x);break;}
        case 2:{S.pop();break;}
        case 3:{cout<<S.top()<<'\n';break;}
        }
    }
}
