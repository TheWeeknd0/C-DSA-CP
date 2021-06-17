#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,d,maxi=0;
		cin>>n>>d;
		int array[n];
		for(int i=0;i<n;i++)
			{
				cin>>array[i];
				maxi=max(maxi,array[i]);
			}
			if(maxi==d)
				cout<<1<<"\n";
			else
				cout<<max(2,ceil(d/maxi));
    }
}