/*
  Created By : Sonu Sharma
  2-11-19      13:16
  Stack Approach
  --------------
*/

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
}*head,*last;
void insertBack(int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=last=temp;
        return;
    }
    last->next=temp;
    last=temp;
    return;
}
bool PalindromeSLL(){
    stack<int>S;
    Node* temp=head;
    while(temp!=NULL){
        S.push(temp->data);
        temp=temp->next;
    }
    while(head!=NULL){
        if(head->data!=S.top()){
            return false;
        }
        S.pop();
        head=head->next;
    }
    return true;
}
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int a;cin>>a;
        insertBack(a);
    }
    if(PalindromeSLL()){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}
