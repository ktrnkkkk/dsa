#include<bits/stdc++.h>
using namespace std;
/* 50 70 25 4 10
f[4] lay: 4+f[2],khong lay: f[3]
f[5] lay:10+f[3],khong lay: f[4]
*/
int main(){
	int n;cin>>n;
	int a[n+1];
	for(int i=1;i<=n;++i) cin>>a[i];
	int f[n+1];
	f[1]=a[1];
	for(int i=2;i<=n;++i){
		f[i]=max(a[i]+f[i-2],f[i-1]);
	}cout<<f[n];
	
}
