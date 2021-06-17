#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
template<typename T>
class node {
public:
	string key;
	T value;
	node<T> *next;   // as node is also a templated class
	node(string getkey, T val) {
		key = getkey;
		value = val;
		next = NULL;
	}
	~node() {
		if (next != NULL)
			delete next;
	}
};

template<typename T>
class Hashtable {
	Hashtable<T>** table; //pointer to an array of pointers
	int current_size;
	int table_size;
	int hashfn(string key) {
		int idx = 0;
		int p = 1;
		for (int j = 0; j < key.length(); j++) {
			idx = idx + (key[j] * p) % table_size;
			idx = idx % table_size;   // we are doing mod again and again
			p = (p * 31) % table_size; //so that the idx and p doent go out of bounds
		}
		return idx;
	}
public:
	Hashtable(int ts = 7) {
		table_size = ts;
		table = new node<T>[table_size];
		current_size = 0;
		for (int i = 0; i < table_size; i++) {
			table[i] = NULL;
		}
	}
	void insert(string key, T value) {
		int idx = hashfn(key);
		node<T>* n = new node<T>(key, value);
		n->next = table[idx];
		table[idx] = n;
		current_size++;
		//rehash..in later videos
	}
	void print() {
		for (int i = 0; i < table_size; i++) {
			cout << "Bucket " << i << "->";
			node*<T> temp = table[i];
			while (temp != NULL) {
				cout << temp->key << "->";
				temp = temp->next;
			}
		}
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}