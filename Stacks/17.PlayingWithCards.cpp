/*
    Created By : Sonu Sharma
    5-11-19      12:11
*/

/*  Problem Stat: You are at a casino. There are N stacked cards on pile . Each card has a number written on it.
    Then there will be Q iterations. In ith iteration, you start picking up the cards in Ai-1th pile from the top
    one by one and check whether the number written on the card is divisible by the ith prime number. If the number 
    is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai. After Q iterations, 
    cards can only be on pile B1, B2, B3, . . . BQ, AQ . Output numbers on these cards from top to bottom of each piles
    in order of B1, B2, B3, . . . BQ, AQ .
*/
// More Efficient Sol can be done 
// I come up with the idea of 2 stacks 
// But I will Leave that to you.


#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
bool isPrime[MAX];
set<int>S;
void sieve(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i*i<=MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=0;i<MAX;i++){
        if(isPrime[i]){
            S.insert(i);
        }
    }
}
int main(){
    sieve();
    int n,q;cin>>n>>q;
    stack<int>A,B;
    vector<int>V(n);
    for(int i=0;i<n;i++)cin>>V[i];
    auto itr=S.begin();
    int p=n;
    for(int i=1;i<=q;i++){
        int k=0;
        for(int j=0;j<V.size();j++){
            if(V[j]%(*itr)==0){
                B.push(V[j]);
            }
            else{
                A.push(V[j]);
            }
        }
        V.clear();
        while(!A.empty()){
            V.push_back(A.top());
            A.pop();
        }
        itr++;
    }
    vector<int>pool;
    while(!B.empty()){
        pool.push_back(B.top());
        B.pop();
    }
    for(int i=pool.size()-1;i>=0;i--){
        cout<<pool[i]<<'\n';
    }
    for(int i=V.size()-1;i>=0;i--){
        cout<<V[i]<<'\n';
    }
}
