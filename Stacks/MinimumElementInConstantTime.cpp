/*
  Created By : Sonu Sharma
  3-11-19      20:32
*/
#include<bits/stdc++.h>
using namespace std;
struct MyStack{
    stack<long int>S;
    int minEle=INT_MAX;
    void push(int x){
        if(!S.empty()){
            if(x<minEle){
                S.push(2*x-minEle);
                minEle=x;
            }
            else{
                S.push(x);
            }
        }
        else{
            S.push(x);
            minEle=x;
        }
    }
    void pop(){
        if(!S.empty()){
            int t=S.top();
            S.pop();
            if(t<minEle){
                minEle=2*minEle-t;
            }
            if(t==minEle){
                minEle=INT_MAX;
            }
        }
    }
    void top(){
        if(!S.empty()){
            if(S.top()<minEle){
                cout<<minEle<<'\n';
            }
            else{
                cout<<S.top()<<'\n';
            }
        }
    }
    bool isEmpty(){
        return S.size()==0;
    }
    int getMin(){

            return minEle;
    }
};

int main(){
    MyStack S;
    int Q; // Queries
    cin>>Q;
    while(Q--){
        int type;cin>>type;
        switch(type){
            case 1:{
                int x;cin>>x;
                S.push(x);
                break;
            }
            case 2:{
                S.pop();
                break;
            }
            case 3:{
                S.top();
                break;
            }
            case 4:{
                cout<<S.isEmpty()<<'\n';
                break;
            }
            case 5:{
                cout<<S.getMin()<<'\n';
            }
        }

    }
}
