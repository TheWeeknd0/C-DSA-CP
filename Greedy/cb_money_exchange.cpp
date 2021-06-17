#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b){
	return a<=b;
}

int main(){
	int arr[]={1,2,5,10,20,50,100,200,500,2000};
	int money;
	cin>>money;
	while(money){
		auto b=lower_bound(arr,arr+10,money,compare)-arr-1;
		cout<<arr[b]<<" ";
		money=money-arr[b];
	}

}
