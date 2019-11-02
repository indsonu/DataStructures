/*
  Created By : Sonu Sharma
  2-11-19      13:34
  
  One Wrong thing about this approach is that 
  (List get reversed at the end)
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
int countNode(Node* a,Node* b){
    int ct=0;
    for(;a&&b;a=a->next,b=b->next){
        if(a->data==b->data)ct++;
        else break;
    }
    return ct;
}
int LongestPalindromeInLinkedList(){
    int res=0;
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL){
        Node* temp=curr->next;                                // For both case
        curr->next=prev;                            
        res=max(res,2*countNode(prev,temp)+1);              // For Odd Length
        res=max(res,2*countNode(curr,temp));                // For Even Length
        prev=curr;
        curr=temp;
    }
    return res;
}
void don(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int a;cin>>a;
        insertBack(a);
    }
    cout<<LongestPalindromeInLinkedList();
}
