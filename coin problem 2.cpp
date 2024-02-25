#include<bits/stdc++.h>
using namespace std;
int f[105][105];
int main(){
	int n,s;cin>>n>>s;
	int a[n+1];
	for(int i=1;i<=n;++i) cin>>a[i];
	int dp[n+1][s+1]={};
	for(int i=1;i<=n;++i) f[i][0]=0;
	for(int i=1;i<=s;++i){
		for(int j=1;j<=n;++j){
			if(i>=a[j]){
				dp[i][j]+=(dp[i-1][j-a[i]],dp[i-1][j]);
				dp[i][j]%=1e9+7;
			}else {
			    dp[i][j]=dp[i-1][j];
			    dp[i][j]%=1e9+7;
			}
		}
	} cout<<dp[n][s]<<endl;
	
}
