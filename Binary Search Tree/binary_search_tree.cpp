#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll long long
using namespace std;
class node {
public:
	int data;
	node*left;
	node* right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
node* insertInBST(node*root, int data) {
	if (root ==  NULL) {
		return new node(data);
	}

	if (data > root->data) {
		root->right = insertInBST(root->right, data);
	}
	else {
		root->left = insertInBST(root->left, data);
	}
	return root;
}

node* buildBST() {
	int d;
	cin >> d;
	node *root = NULL;
	while (d != -1) {
		root = insertInBST(root, d);
		cin >> d;
	}
	return root;
}
void bfs(node*root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node* temp = q.front();
		if (temp == NULL) {
			cout << '\n';
			q.pop();
			if (!q.empty())
				q.push(NULL);
		}
		else {
			cout << temp->data << ' ';
			q.pop();
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
}

void inorderPrint(node* root) {
	if (root == NULL)
		return;
	inorderPrint(root->left);
	cout << root->data << ' ';
	inorderPrint(root->right);
}

node* deleteInBST(node* root, int data) {
	if (root == NULL)
		return NULL;
	else if (data < root->data) {
		root->left = deleteInBST(root->left, data);
		return root;
	}
	else if (data == root->data) {
		// 1. If it is a leaf node
		if (root->left == nullptr and root->right == nullptr) {
			delete root;
			return nullptr;
		}
		//2. Node containing one child
		if (root->left != NULL and root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}
		if (root->left == NULL and root->right != NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		// case 3 (having 2 child)
		node* replace = root->right;
		while (replace->left != nullptr)
			replace = replace->left;
		root->data = replace->data;
		root->right = deleteInBST(root->right, replace->data); // case 1 or 2 will hit for this
		return root;     //we are going in root's right to delete the replace->data
	}
	root->right = deleteInBST(root->right, data);
	return root;
}

bool isBST(node* root, int minV = INT_MIN, int maxV = INT_MAX) {
	if (root == NULL)
		return true;
	if (root->data >= minV and root->data <= maxV and isBST(root->left, minV, root->data) and isBST(root->right, root->data, maxV)) {
		//cout << "max " << maxV << " min " << minV << endl;
		return true;
	}
	return false;
}
class LinkedList {
public:
	node* head;
	node* tail;
};

LinkedList bstToLinkedList(node* root) {
	LinkedList l;
	if (root == NULL) {
		l.head = l.tail = NULL;
		return l;
	}
	// leaf node
	if (root->left == NULL and root->right == NULL) {
		l.head = l.tail = root;
		return l;
	}
	// left is not null
	if (root->left != NULL and root->right == NULL) {
		LinkedList leftll = bstToLinkedList(root->left);
		leftll.tail->right = root;
		l.head = leftll.head;
		l.tail = root;
		return l;
	}
	// right is not null
	if (root->right != NULL and root->left == NULL) {
		LinkedList rightll = bstToLinkedList(root->right);
		root->right = rightll.head;
		l.head = root;
		l.tail = rightll.tail;
		return l;
	}
	// right and left is not NULL
	LinkedList leftll = bstToLinkedList(root->left);
	LinkedList rightll = bstToLinkedList(root->right);

	leftll.tail->right = root;
	root->right = rightll.head;
	l.head = leftll.head;
	l.tail = rightll.tail;
	return l;
}
void llprint(node *head) {
	while (head != NULL) {
		cout << head->data << ' ';
		head = head->right;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sync;
	node* root = buildBST();
	bfs(root);
	cout << "Inorder Print\n";
	inorderPrint(root);
	cout << endl;
	node*ans = deleteInBST(root, 3);
	bfs(ans);
	cout << isBST(root);
	LinkedList h = bstToLinkedList(root);
	cout  << "\nhello\n";
	llprint(h.head);
}