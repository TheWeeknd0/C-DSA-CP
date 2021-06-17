#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void filterchars(char a[],int n){
    int j=0;
    while(n>0){
     int lastbit=(n&1);
     if(lastbit>0)
        cout<<a[j];
       j++;
       n=n>>1;
    }
    cout<<endl;
}
void printsubsets(char a[]){
    int len=strlen(a);
    for(int i=0;i<(1<<len);i++){
        filterchars(a,i);
    }
}
int main(){
	sync
    char a[100];
    cin>>a;
    printsubsets(a);
   

}