#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
class node {
public:
	char data;
	unordered_map<char, node*> children;
	bool terminal;
	node(char d) {
		data = d;
		terminal = false; //by default
	}
};

class Trie {
	node* root;
	int cnt;
public:
	Trie() {
		root = new node('\0');
		cnt = 0;
	}

	void insert(char* w) {
		node* temp = root;
		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];
			if (temp->children.count(ch)) { // gives 1 if ch is present else 0
				temp = temp->children[ch];  //children[ch] gives out address as it a map<char,node*>
			}
			else {
				node*n = new node(ch);    //creates a new node and joins it with the current node we are at
				temp->children[ch] = n;   //the new node's address is stored in the map of the previous node
				temp = n;                 //for further iteration temp is made out be n
			}
		}
		temp->terminal = true;      // finally we have read our whole word ..now mark the end of that
	}                             // node's terminal as true

	bool find(char *w) {
		node *temp = root;
		for (int i = 0; w[i] != '\0'; i++) {
			char ch = w[i];
			if (temp->children.count(ch) == 0)
				return false;
			else
				temp = temp->children[ch];
		}
		return temp->terminal;  // this is important ...if the users want to search for NO but there is
	}        // no word like NO but NOT is present ..if we simply return true..it will be a wrong answer
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sync;
	Trie T;
	int n; cin >> n;
	char words[][10] = {"NO", "NOT", "NEVER", "HI", "HELLO"};
	for (int i = 0; i < n; i++) {
		T.insert(words[i]);
	}
	char w[10];
	cin >> w;
	cout << w << endl;
	if (T.find(w))
		cout << "Present\n";
	else
		cout << "Absent" << endl;

}