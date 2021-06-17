#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2) {
	return p1.first > p2.first;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<int, int> > v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;
		priority_queue<int> pq;
		int D, F;
		cin >> D >> F;
		sort(v.begin(), v.end(), compare);
		for (int i = 0; i < n; i++)
			v[i].first = D - v[i].first;
		int ans = 0, x = 0, prev = 0, flag = 0;
		while (x < n) {
			if (F >= (v[x].first - prev)) {
				F = F - (v[x].first - prev);
				pq.push(v[x].second);
				prev = v[x].first;
			}
			else {
				if (pq.empty()) {
					flag = 1;
					break;
				}
				F += pq.top();
				pq.pop();
				ans++;
				continue;
			}
			x++;
		}
		if (flag) {
			cout << -1 << endl;
			continue;
		}
		D = D - v[n - 1].first;
		if (F >= D) {
			cout << ans << endl;
			continue;
		}
		while (F < D) {
			if (pq.empty()) {
				cout << -1 << endl;
				flag = 1;
				break;
			}
			F += pq.top();
			pq.pop();
			ans++;
		}
		if (flag) {
			cout << -1 << endl;
			continue;
		}
		cout << ans << endl;
	}
}