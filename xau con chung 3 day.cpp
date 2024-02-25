#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2,s3;
	cin>>s1>>s2>>s3;;
	int n=s1.size(),m=s2.size(),p=s3.size();
	s1="0"+s1;s2="0"+s2;s3="0"+s3;
	int f[n+1][m+1][p+1];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			for(int k=1;k<=p;++k){
				if(s1[i]==s2[i]&&s1[i]==s3[i]) f[i][j][k]=max(f[i-1][j-1][k-1]+1,max(f[i-1][j][k],max(f[i][j-1][k],f[i][j][k-1])));
				else f[i][j][k]=max(f[i-1][j][k],max(f[i][j-1][k],f[i][j][k-1]));
			}
		}
	}cout<<f[n][m][p]<<endl;
}
