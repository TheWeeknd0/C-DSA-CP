#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
	sync
    int n;
    cin>>n;
    int cnt[64]={0};
    int no;
    for(int i=0;i<n;i++){
    	cin>>no;
    	int o=0;
    	while(no){
    		int j=(no&1);
    		cnt[o]+=j;
    		no=no>>1;
    		o++;
    	}
    }
    for(auto i=0;i<64;i++){
    	cnt[i]%=2;
    }
    int p=1,sum=0;
    for(int i=0;i<64;i++){
      sum+=(cnt[i]*p);
      p<<=1;
  }
  cout<<sum;
}