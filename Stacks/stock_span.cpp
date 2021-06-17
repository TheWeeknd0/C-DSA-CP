#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int array[n];
	for (int i = 0; i < n; i++)
		cin >> array[i];
	stack< pair<int, int> > s;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (s.empty())
			v.push_back(-1);
		else if (!s.empty() and s.top().first >= array[i]) {
			v.push_back(s.top().second);
		}
		else {
			while (!s.empty() and s.top().first < array[i])
				s.pop();
			if (s.empty())
				v.push_back(-1);
			else
				v.push_back(s.top().second);
		}
		s.push({array[i], i});
	}
	for (int i = 0; i < n; i++) {
		cout << i - v[i] << " ";
	} cout << "END";
	int c = 4;
}
