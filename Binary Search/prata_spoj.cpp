#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
bool cancookinless(int array[], int n, int time, int pratas) {
	int timetaken = 0, currpratas = 0;
	for (int i = 0; i < n; i++) {
		timetaken = 0;
		for (int j = 1; j <= pratas; j++) {
			timetaken += array[i] * j;
			currpratas++;
			if (timetaken > time) {
				currpratas--;
				break;
			}
		}
		if (currpratas >= pratas)
			return true;
	}
	return false;
}
int binary_cooks(int array[], int n, int pratas) {
	int sum = 0;
	for (int i = 1; i <= pratas; i++)
		sum += array[0] * i;
	int s = 0;
	int e = sum;
	int ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (cancookinless(array, n, mid, pratas)) {
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sync
	int t; cin >> t;
	while (t--) {
		int pratas, cooks;
		cin >> pratas >> cooks;
		int ranks[cooks];
		for (auto &i : ranks) cin >> i;
		sort(ranks, ranks + cooks);
		cout << binary_cooks(ranks, cooks, pratas) << "\n";
	}
}