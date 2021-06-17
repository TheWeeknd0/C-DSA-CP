#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sync
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		char str[n];
		for (auto i = 0; i < n; i++) cin >> str[i];
		queue<char> q;
		map<char, int> m;
		for (int i = 0; i < n; i++) {
			m[str[i]]++;
			q.push(str[i]);
			while (!q.empty() and m[q.front()] > 1) {
				q.pop();
			}
			if (!q.empty()) cout << q.front() << ' ';
			else cout << -1 << ' ';
		}
		cout << '\n';
	}
}