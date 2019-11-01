/* Created By Sonu Sharma 
   10:42 Friday 1-11-19
*/

#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int d) {
		data = d;
		next = NULL;
	}
}*head,*last;
void makeNode(int d) {
	Node* n = new Node(d);
	if (head == NULL) {
		head=last=n;
		return;
	}
	last->next = n;
	last = last->next;
	return;
}
int len() {
	Node* temp = head;
	int len = 0;
	while (temp != NULL) {
		len++;
		temp = temp->next;
	}
	return len;
}
Node* reverseK(int k) {
	Node* slow = head;
	Node* fast = head;
	while (k && fast != NULL) {
		k--;
		fast = fast->next;
	}
	while (fast->next != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
int main() {
	int n, k,a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		makeNode(a);
	}
	cin >> k;
	k=k%n;
		Node* temp1=reverseK(k);
		last->next = head;
		head = temp1->next;
		temp1->next = NULL;
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}

