#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
class Trie {
public:
	Trie* left;
	Trie* right;
	Trie() {
		left = right = NULL;
	}
};
void insert(int a, Trie *root) {
	Trie* temp = root;
	for (int i = 31; i >= 0; i--) {
		int bit = (a >> i) & 1;
		if (bit == 0) {
			if (temp->left != NULL)
				temp = temp->left;
			else {
				temp->left = new Trie();
				temp = temp -> left;
			}
		}
		else {
			if (temp->right != NULL)
				temp = temp->right;
			else {
				temp->right = new Trie();
				temp = temp->right;
			}
		}
	}
}

int MaxXor(Trie *root, int element) {
	int sum = 0;
	Trie * temp = root;
	for (int i = 31; i >= 0; i--) {
		int bit = (element >> i) & 1;
		if (bit == 0) {
			if (temp->right != NULL) {
				sum += (int)pow(2, i);
				temp = temp->right;
			}
			else
				temp = temp->left;
		}
		else {
			if (temp->left != NULL) {
				sum += (int)pow(2, i);
				temp = temp->left;
			}
			else
				temp = temp->right;
		}
	}
	if (sum < 0)
		return 0;
	return sum;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Trie * root = new Trie();
	int n; cin >> n;
	vector<int> v(n);
	int mx = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		insert(v[i], root);
		int m = MaxXor(root, v[i]);
		mx = max(mx, m);
	}
	cout << mx << endl;
}
