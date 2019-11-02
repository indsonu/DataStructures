/*
  Created By : Sonu Sharma
  2-11-19      16:47
*/


#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int d){
        data=d;
        next = NULL;
    }
}*last;
void insert(Node *&head, int d){
    if(head==NULL){
        head=last=new Node(d);
        return;
    }
    Node* temp=new Node(d);
    last->next=temp;
    last=temp;
    return;
}
Node* midPoint(Node *head){
    Node *slow=head;
    // When mid point is taken , there will be an ambiguity - if the no. of nodes are even , hence starting the fast pointer
    //with 1 node ahead of slow pointer
    Node *fast=head->next;
    //Also in while loop , we check if slow!=NULL or fast and fast->next instead - fast->next->next
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* merge(Node* &a, Node* &b){
    Node *c=NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    if(a->data < b->data){
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}
Node* mergesort(Node *&head){
    if(head==NULL || head->next==NULL)
        return head;

    Node *mid= midPoint(head);

    Node *a=head;
    Node *b = mid->next;
    mid->next=NULL;

    a=mergesort(a);
    b= mergesort(b);
    return	merge(a,b);
}
void don() {
    int n,k,d;
    Node *head=NULL;
    cin>>n;
    while(n--){
        cin>>d;
        insert(head,d);
    }
    head=mergesort(head);
    // Printing the sorted LINKED LIST
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }

    return;
}
