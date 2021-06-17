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
	deque<int> q;
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		while (!q.empty() and array[i] >= array[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	for (int i = k; i < n; i++) {
		cout << array[q.front()] << ' ';
		while (!q.empty() and q.front() <= i - k)
			q.pop_front();
		while (!q.empty() and array[i] >= array[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	cout << array[q.front()];
}