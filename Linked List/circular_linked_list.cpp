#include<bits/stdc++.h>
using namespace std;
#define ll long long;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
class node {
public:
  int data;
  node*next;
  node(int d) {
    data = d;
    next = NULL;
  }
};
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
node* kthnodefromend(node*head, int k) {
  int jump = 1;
  node* curr = head;
  node* now = head;
  while (jump <= k) {
    curr = curr->next;
    jump++;
  }
  while (curr != NULL) {
    curr = curr->next;
    now = now->next;
  }
  return now;
}
node* kappend(node* head, int k) {
  node*papa = kthnodefromend(head, k);
  node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = head;
  node*curr = head;
  while (curr->next != papa) {
    curr = curr->next;
  }
  curr->next = NULL;
  return papa;
}
void insertattail(node*&head, int data) {
  if (head == NULL) {
    node*n = new node(data);
    head = n;
  }
  else {
    node*temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    node*n = new node(data);
    temp->next = n;
  }
}
void print(node*head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;

  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int j = n;
  node*head = NULL;
  while (n--) {
    int data; cin >> data;
    insertattail(head, data);
  }
  int k;
  cin >> k;
  if (k > j) {
    k = k % j;
  }
  if (j == k) {
    reverselinkedlist(head);
    print(head);
  }
  else if (k == 0) {
    print(head);
  }
  else {
    node*c = kappend(head, k);
    print(c);
  }
}