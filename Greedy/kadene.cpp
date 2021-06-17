#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum = 0, current = 0;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		current += arr[i];
		if (current <= 0)
			current = 0;
		sum = max(sum, current);
	}
	cout << sum;
}