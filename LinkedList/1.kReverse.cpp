/* Created By Sonu Sharma 
   10:42 Friday 1-11-19
   
   
   
In here basically recursion is doing is own work.
I am just reversing the list k times and managing the pointers

The key point to notice is after revering the first k times then
next pointer will move to k+1 pointer and prev will refer to kth 
pointer and head will remains the same. Calling the recursion to
head->next=Krevese(next,k) will return the next prev pointer to next
of current head
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
Node* kReverse(int k,Node* head){
    Node* curr=head;
    Node* nt=NULL;
    Node* prev=NULL;
    int ct=0;
    while(ct<k && curr!=NULL){
        nt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nt;
        ct++;
    }
    if(nt!=NULL){
        head->next=kReverse(k,nt);
    }
    return prev;
}
int main(){
    int n,k,a;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a;
        insertBack(a);
    }
    head=kReverse(k,head);
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
	return 0;
}
