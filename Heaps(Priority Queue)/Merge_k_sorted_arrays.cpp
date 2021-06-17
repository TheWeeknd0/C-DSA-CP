#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define ll long long
#define node pair<int,pair<int,int>>
using namespace std;
vector<int> mergeksorted(vector<vector<int>> v) {
	vector<int> result;
	priority_queue<node, vector<node>, greater<node>> pq;
	for (int i = 0; i < v.size(); i++) {
		pq.push({v[i][0], {i, 0}});
	}
	while (!pq.empty()) {
		node current = pq.top();
		pq.pop();
		int element = current.first;  //element (minimum)
		int x = current.second.first; // row number of the minimum number
		int y = current.second.second; // column number of the minimum number
		result.push_back(element);
		if (y + 1 < v[x].size()) {     // y+1 (the next element of the minimum element found in heap)
			pq.push({v[x][y + 1], {x, y + 1}});
		}
	}
	return result;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
		vector<int> v1;
		for (int j = 0; j < m; j++) {
			int a; cin >> a;
			v1.push_back(a);
		}
		v.push_back(v1);
	}
	vector<int> r = mergeksorted(v);
	for (auto i : r)
		cout << i << ' ';
}