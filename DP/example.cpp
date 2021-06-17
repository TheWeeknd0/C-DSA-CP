#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOS;
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s;
		cin >> s;
		int lose = 0, points = 1 + 2 * (n - 1);
		int maxpoints = 1 + 2 * (n - 1);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L')
				lose++;
		}
		cout << abs(points - 2 * (k - lose)) << endl;
	}
}