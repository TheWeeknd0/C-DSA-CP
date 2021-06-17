#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
int make_change(int *arr, int n, int money) {
	int ans = 0;
	while (money > 0) {
		int idx = upper_bound(arr, arr + n, money) - 1 - arr;
		cout << arr[idx] << " ";
		money -= arr[idx];
		ans++;
	}
	cout << endl;
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	int arr[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	cout << "Money Change " << make_change(arr, 10, n);
}