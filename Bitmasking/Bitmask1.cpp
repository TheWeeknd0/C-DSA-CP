#include<iostream>
using namespace std;
int main()
{
	 long long n,m,k;
	cin>>n>>m;
	if(m%n==0)
	k=m/n;
    else
    {   cout<<-1;
    	return 0;
    }
	int sum=0;
	while(k!=1)
	{
		if(k%2==0)
		{
			sum++;
			k/=2;
		}
		else if(k%3==0)
		{
			sum++;
			k/=3;
		}
		else
			break;
	}
	if(k==1)
		cout<<sum;
	else
		
			cout<<-1;
	

}