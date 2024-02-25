#include<bits/stdc++.h>
using namespace std;
int main(){
	int s;cin>>s;
	int f[s+1];
	f[0]=1,f[1]=1;
	for(int i=1;i<=s;++i){
		for(int j=1;j<=k;++i){
			if(i>=j) f[i]+=f[i-j];
			f[i]%=mod;
		}
	}cout<<f[s]<<endl;
}
