/*
Kth smallest element in row and col wise sorted array - in this we take the
first array row completely and its first element is the smallest as we know
after that we have two choices of next smallest element either a[row+1][col]
and a[row][col+1] as if row available we push a[row+1][col] and as per priority
queue property which ever we got on top we print it these loop goes k times as we want kth element.
*/
#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll long long
#define node pair<int,pair<int,int>>
using namespace std;

int kthelement(vector<vector<int>> v, int k) {
	priority_queue<node, vector<node>, greater<node>> pq;
	int row = 0;
	int col = 0;
	if (k == 1) {
		return v[0][0];
	}
	for (int i = 0; i < v.size(); i++) {
		pq.push({v[0][i], {0, i}});
	}
	int count = 0;
	node curmin;
	while (count < k) {
		count++;
		curmin = pq.top();
		pq.pop();
		int x = curmin.second.first;  //row
		int y = curmin.second.second; // column
		if ( x + 1 < v.size()) {
			pq.push({v[x + 1][y], {x + 1, y}});
		}
	}
	return curmin.first;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<vector<int>> v {{1, 4, 9}, {10, 13, 14}, {11, 15, 23}};
	int x = kthelement(v, 5);
	cout << x << endl;
}