//cdAeBghCpD
//lkuABzzuuCxzD
//f[8][10] lay: 1+f[7][9],khong lay: f[8][9],f[7][10]
//f[4][4]
//f[i][j]: x�t i ki tu dau cua s1 v� j k� tu dau cua s2
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size(),m=s2.size();
	s1="0"+s1;s2="0"+s2;
	int f[n+1][m+1];
	f[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s1[i]==s2[i]){
				f[i][j]=max(f[i-1][j-1]+1,f[i-1][j],f[i][j-1]);
			}else f[i][j]=max(f[i-1][j],f[i][j-1]);
		}
	}cout<<f[n][m]<<endl;
}
