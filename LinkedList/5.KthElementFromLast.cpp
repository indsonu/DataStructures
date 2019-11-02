/*
  Created By : Sonu Sharma
  2-11-19      11:21
  In QT Creator
  -------------
  
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
Node* insertBack(int data){
    Node* temp=new Node(data);
    if(head==NULL){
       head=last=temp;
       return head;
    }
    last->next=temp;
    last=temp;
    return head;
}
int kElement(int k){
    Node* fast=head;
    Node* slow=head;
    int ct=0;
    while(ct<k && fast!=NULL){
        fast=fast->next;
        ct++;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow->data;
}
int main(){
   int t,k;cin>>t;
   while(t!=-1){
       insertBack(t);
       cin>>t;
   }
   cin>>k;
   cout<<kElement(k);
}
