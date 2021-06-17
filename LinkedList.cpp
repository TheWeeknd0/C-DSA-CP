#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class node {
public:
  int data;
  node* next;
  node(int d) {
    data = d;
    next = NULL;
  }
};
node* midpoint(node*head) {
  node*fast = head;
  node*slow = head;
  while (fast != NULL and fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}
node* kthnodefromend(node*head, int k) {
  int jump = 1;
  node* curr = head;
  node* now = head;
  while (jump <= k) {
    curr = curr->next;
    jump++;
  }
  while (curr->next != NULL) {
    curr = curr->next;
    now = now->next;
  }
  return now;
}
node* mergesortedll(node*a, node*b) {
  if (a == NULL)
    return b;
  if (b == NULL)
    return a;
  node*c;
  if (a->data > b->data) {
    c = b;
    c->next = mergesortedll(a, b->next);
  }
  else {
    c = a;
    c->next = mergesortedll(a->next, b);
  }
  return c;
}
node* reverserecusrion(node*head) {
  if (head->next == NULL) {
    return head;
  }
  node*smallhead = reverserecusrion(head->next);
  node*n = head;
  n->next->next = n;
  n->next = NULL;
  cout << smallhead->data << endl;
  return smallhead;
}
void reverselinkedlist(node*&head) {
  node*prev = NULL;
  node*curr = head;
  while (curr != NULL) {
    node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  head = prev;
}
void insertathead(node* &head, int data) {
  node *n = new node(data);
  n->next = head;
  head = n;
}
void print(node *head) {
  node *temp = head;
  while (temp != NULL) {          //To read the the last element,
    cout << temp->data << "->";   //Had it been temp->next!=NULL..it wouldve not printed the last node
    temp = temp->next;
  }
}
void insertattail(node* head, int data) {
  if (head == NULL) {
    insertathead(head, data);
  }
  node* temp = head;
  while (temp->next != NULL) {  //temp->next so that temp doesnt goes out of linked list
    temp = temp->next;
  }
  temp->next = new node(data);
}
void deleteinmiddle(node*&head, int p) {
  if (p == 1) {
    head = head->next;
    delete head;
    return;
  }

  node * prev = NULL;
  node *temp = head;
  int jump = 0;
  while (jump != p - 1) {
    prev = temp;
    temp = temp->next;
    jump++;
  }
  prev->next = temp->next;
  delete temp;
}

int main() {
  sync
  node* head = NULL;
  insertathead(head, 12);
  insertathead(head, 11);
  insertathead(head, 10);
  insertathead(head, 9);
  insertathead(head, 8);
  insertathead(head, 7);
  print(head);
  node *head2 = NULL;
  cout << endl;
  insertathead(head2, 77);
  insertathead(head2, 74);
  insertathead(head2, 66);
  insertathead(head2, 61);
  insertathead(head2, 44);
  insertathead(head2, 21);
  print(head2);
// node* newhead = reverserecusrion(head);
  //print(newhead);
  node* mid = mergesortedll(head, head2);
  cout << endl;
  print(mid);



}
