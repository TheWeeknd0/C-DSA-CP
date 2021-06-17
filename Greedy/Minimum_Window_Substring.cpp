#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n';
#define ll  long long
using namespace std;
string minsubstring(string str, string pat) {
	int f_p[256] = {0}, f_s[256] = {0};
	int len1 = str.length();
	int len2 = pat.length();
	if (len2 > len1) {
		return "No Window";
	}
	for (int i = 0; i < len2; i++) {
		f_p[pat[i]]++;
	}
	int start = 0, start_index = -1, min_length = INT_MAX;
	int count = 0;
	for (int i = 0; i < len1; i++) {
		f_s[str[i]]++;
		if (f_p[str[i]] != 0 and f_s[str[i]] <= f_p[str[i]])
			count++;
		if (count == len2) {
			while (f_p[str[start]] == 0 or f_s[str[start]] > f_p[str[start]]) {
				if (f_s[str[start]] > f_p[str[start]]) {
					f_s[str[start]]--;
				}
				start++;
			}
			int len_current = i - start + 1;
			if (len_current < min_length) {
				min_length = len_current;
				start_index = start;
			}
		}
	}
	if (start_index == -1)
		return "No Window";
	else
		return str.substr(start_index, min_length);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sync;
	string str, pat;
	cin >> str >> pat;
	string ok = minsubstring(str, pat);
	cout << ok << endl;
}