#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void printkmaximum(int array[], int n, int k) {
  deque<int> q;
  for (int i = 0; i < k; i++) {
    while (!q.empty() and array[i] > array[q.back()])
      q.pop_back();
    q.push_back(i);
  }
  for (int i = k; i < n; i++) {
    cout << array[q.front()] << ' ';
    while (!q.empty() and q.front() + k <= i)
      q.pop_front();
    while (!q.empty() and array[i] > array[q.back()])
      q.pop_back();
    q.push_back(i);
  }
  cout << array[q.front()];
}
int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int array[n];
  for (int i = 0; i < n; i++)
    cin >> array[i];
  int k; cin >> k;
  printkmaximum(array, n, k);
  return 0;
}