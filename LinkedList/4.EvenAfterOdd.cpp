/*
    Created By : Sonu Sharma
    1-11-19      11:48
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
Node* EvenAfterOdd(){
    Node* even=NULL,*odd=NULL,*firstLoveEven=NULL,*firstLoveOdd=NULL;
    while(head!=NULL){
        if((head->data)%2==0){
            if(firstLoveEven==NULL){
                firstLoveEven=head;
            }
            if(even==NULL){
                even=head;
            }
            else{
                even->next=head;
                even=head;
            }
        }
        else{
            if(firstLoveOdd==NULL){
                firstLoveOdd=head;
            }
            if(odd==NULL){
                odd=head;
            }
            else{
                odd->next=head;
                odd=head;
            }
        }
        head=head->next;
    }
    head=firstLoveOdd;
    if(odd!=NULL)
    odd->next=firstLoveEven;
    if(even!=NULL)
    even->next=NULL;
    return head;
}
int main(){
    int n,k;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        insertBack(a);
    }
    head=EvenAfterOdd();
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
