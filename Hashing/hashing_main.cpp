#include<bits/stdc++.h>
#include "Hashing.h"
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Hashtable <int> price_menu;
	price_menu.insert("a", 200);
	price_menu.insert("v", 120);
	price_menu.insert("c", 1240);
	price_menu.insert("z", 1205);
	price_menu.insert("io", 12055);
	auto price = price_menu.search("z");
	if (price) {
		cout << "found" << endl;
	}
	else
		cout << "not found" << endl;
	//price_menu.print();
	price_menu["a"] += 10;
	cout << price_menu["a"];
}