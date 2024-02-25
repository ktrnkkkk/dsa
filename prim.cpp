#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int n,m;
vector<pair<int,int>>adj[maxn];
bool used[maxn];
struct canh{
	int u,v,w;
};
void inp(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int x,y,w;cin>>x>>y>>w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}memset(used,false,sizeof(used));
}
void prim(int u){
	vector<canh>mst;
	int d=0;
    used[u]=true;
	while(mst.size()<n-1){
		int w1=INT_MAX;
	    int x,y;
	    for(int i=1;i<=n;++i){
	    	if(used[i]){
	    		for(pair<int,int> it:adj[i]){
	    			int j=it.first,trongso=it.second;
	    			if(!used[j]&&trongso<w1){
	    				w1=trongso;
	    				x=j;y=i;
					}
				}
			}
		}mst.push_back({x,y,w1});
		d+=w1;
	}cout<<d<<endl;
	for(auto it:mst){
		cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
	}
}
int main(){
	inp();
	prim(1);
}
