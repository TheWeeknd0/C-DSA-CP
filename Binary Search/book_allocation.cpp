#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool canfuck(int array[], int size, int studs, int k) {
  int current_pages = 0;
  int students = 1;
  for (int i = 0; i < size; i++) {
    if (current_pages + array[i] > k) {
      students++;
      current_pages = array[i];
      if (students > studs)
        return false;
    }
    else {
      current_pages += array[i];
    }
  }
  return true;
}
int noofpages(int array[], int n, int m) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += array[i];
  int s = array[n - 1];
  int e = sum;
  int mid;
  int ans = 0;
  while (s <= e) {
    mid = (s + e) / 2;
    if (canfuck(array, n,  m, mid)) {
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
    int n, m;
    cin >> n >> m;
    int pages[n];
    for (int &i : pages)cin >> i;
    cout << noofpages(pages, n, m) << "\n";

  }
}
