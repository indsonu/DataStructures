/*
  Created By : Sonu Sharma
  2-11-19      12:12

 I am not sure that this approach will definitely work everywhere 
 instead you can use hashing if the platform is good related to pointers and other stuffs.

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
Node* insertBack(int data,Node* head){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        return head;
    }
    Node* poop=head;
    while(poop->next!=NULL){
        poop=poop->next;
    }
    poop->next=temp;
    return head;
}
int count_list(Node* a){
	int t=0;
	while(a){t++;
		a=a->next;
	}
	return t;
}
int intersection(Node *a,Node *b)
{
    int len1=count_list(a);
    int len2=count_list(b);
    int diff;
    diff=abs(len2-len1);
    if(len2>len1)
    {
    for(int i=0;i<diff;i++)
    {
     b=b->next;             // In Here i m first reaching to the equal height then traversing both
    }                       // If i find the element then they are merged
    }
    else
    {
    for(int i=0;i<diff;i++)
    {
     a=a->next;   
    }
    }
 while(a!=NULL && b!=NULL)
    {
        if(a->data!=b->data)
        {
            a=a->next;
            b=b->next;
        }
        else if(a->data==b->data)
        {
          return a->data;
        }
    }
    return -1;
}
int main(){
    int n,m;
    cin>>n;
    Node* head1=NULL,*head2=NULL;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        head1=insertBack(a,head1);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int a;cin>>a;
        head2=insertBack(a,head2);
    }
    cout<<intersection(head1,head2);
}
