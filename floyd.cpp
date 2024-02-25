#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int mt[n+1][n+1];
	for(int i=1;i<=n;++i){
 	    for(int j=1;j<=n;++j){
		   if(i==j) mt[i][j]=0;
		   else mt[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;++i){
		int x,y,w;cin>>x>>y>>w;
		mt[x][y]=w;
		mt[y][x]=w;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int t=1;t<=n;++t){
				mt[j][t]=min(mt[j][t],mt[j][i]+mt[i][t]);
			}
		}
	}int t;cin>>t;
	while(t--){
		int u,v;cin>>u>>v;
		cout<<mt[u][v]<<endl;
	}
}
