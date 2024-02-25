#include<bits/stdc++.h>
using namespace std;
int n,m;
bool visited[1001];
void dfs(int u,vector<int>adj[]){
	visited[u]=true;
	for(int v:adj[u]){
		if(!visited[v]){
			dfs(v,adj);
		}
	}
}
void dinhtru(vector<int>adj[]){
	int tplt=0;
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			++tplt;
			dfs(i,adj);
		}
	}for(int i=1;i<=n;++i){
		memset(visited,false,sizeof(visited));
		visited[i]=true;
		int dem=0;
		for(int j=1;j<=n;++j){
			if(!visited[j]){
				++dem;
				dfs(j,adj);
			}
		}if(dem>tplt){
			cout<<i<<" ";
		}
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		memset(visited,false,sizeof(visited));
	    vector<int>adj[n+5];
	    for(int i=1;i<=m;++i){
		    int x,y;cin>>x>>y;
		    adj[x].push_back(y);
		    adj[y].push_back(x);
        }dinhtru(adj);
        cout<<endl;
	}
}

