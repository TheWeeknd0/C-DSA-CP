#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool candoinlesstime(ll times[], ll mid, ll painters, ll boards) {
	ll currtime = times[0];
	ll currpainters = 1;
	for (ll i = 1; i < boards; i++) {
		if (currtime + times[i] > mid) {
			currpainters++;
			currtime = times[i];
			if (currpainters > painters)
				return false;
		}
		else
			currtime += times[i];
	}
	return true;
}
ll minimum_time(ll times[], ll painters, ll boards, ll mx) {
	ll sum = 0;
	for (auto i = 0; i < boards; i++) sum += times[i];
	ll s = mx;
	ll e = sum;
	ll ans = 0;
	while (s <= e) {
		ll mid = s + (e - s) / 2;
		if (candoinlesstime(times, mid, painters, boards)) {
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	return ans;
}
int main() {
	sync
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, k, t;
	cin >> n >> k >> t;
	ll array[n];
	ll mx = 0;
	for (ll i = 0; i < n; i++) {
		cin >> array[i];
		mx = max(array[i], mx);
	}
	ll newnew = minimum_time(array, k, n, mx) * t;
	cout << newnew % (ll)10000003;
}