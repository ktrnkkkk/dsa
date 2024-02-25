#include<bits/stdc++.h>
using namespace std;

bool visited[1001];
int parent[1001];
bool DFS(int u,vector<int>adj[]){
	visited[u]=true;
	for(int v:adj[u]){
		if(!visited[v]){
			parent[v]=u;
			if(DFS(v,adj)) return true;
		}else if(v!=parent[u]) return true;
	}return false;
}
int main(){
	int t;cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		memset(parent,0,sizeof(parent));
		memset(visited,false,sizeof(visited));
	    vector<int>adj[n+5];
	    for(int i=1;i<=m;++i){
		    int x,y;cin>>x>>y;
		    adj[x].push_back(y);
		    adj[y].push_back(x);
    	}int ok=0;
		for(int i=1;i<=n;++i){
    		if(!visited[i]){
    			if(DFS(i,adj)){
    				cout<<"YES\n";
    				ok=1;
    				break;
				}
			}
		}
		if(ok==0)cout<<"NO\n";
	}
}

