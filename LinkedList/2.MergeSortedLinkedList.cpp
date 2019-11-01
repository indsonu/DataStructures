/*
  Created By: Sonu Sharma
  1-11-19       11:01
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
};
Node* insertBack(int data,Node* &head,Node* &last){
    Node* temp=new Node(data);
    if(head==NULL){
       head=last=temp;
       return head;
    }
    last->next=temp;
    last=temp;
    return head;
}
Node* mergeSorted(Node* a,Node* b){
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    Node* c=NULL;
    if(a->data>b->data){
        c=b;
        c->next=mergeSorted(a,b->next);
    }
    else{
        c=a;
        c->next=mergeSorted(a->next,b);
    }
    return c;
}
int main(){
    int t;cin>>t;
    while(t--){
        Node* head1=NULL,*last1=NULL;
        Node* head2=NULL,*last2=NULL;
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            head1=insertBack(a,head1,last1);
        }
        cin>>n;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            head2=insertBack(a,head2,last2);
        }
        Node* head3=mergeSorted(head1,head2);
        while(head3){
            cout<<head3->data<<" ";
            head3=head3->next;
        }
    }
}
