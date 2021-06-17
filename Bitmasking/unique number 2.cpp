#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main(){
	sync
   int n;
   cin>>n;
   int array[n];
   int res=0;
   for(int i=0;i<n;i++){
   	cin>>array[i];
   	res=res^array[i];
   }
   int temp=res;
   int pos=0;
   while((temp&1)!=1){
   	pos++;
   	temp=temp>>1;
   }
   int chk=(1<<pos);
   int des=0;
   for(int i=0;i<n;i++){
   	if((array[i]&chk)>0)
   		des=des^array[i];
   }
   int q=(res^des);
   cout<<min(q,des)<<" "<<max(q,des);
  
}