#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n,m,ok=1;
		cin>>n>>m;
		vector<int>adj[n+5];
		for(int i=1;i<=m;++i){
			int x,y;cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i=1;i<=n;++i){
			for(auto x:adj[i]){
				if(adj[i].size()!=adj[x].size()){
					ok=0;
					cout<<"NO"<<endl;
					break;
				}
			}if(!ok) break;
		}if(ok) cout<<"YES"<<endl;
	}
}
