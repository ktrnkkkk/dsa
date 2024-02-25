#include<bits/stdc++.h>
using namespace std;
int n,m,s,h;
const int maxn=1001;
vector<pair<int,int>>adj[maxn];
void nhap(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;++i){
		int x,y,z;cin>>x>>y>>z;
		adj[x].push_back({y,z});
		adj[y].push_back({x,z});
	}
}
int pre[maxn];
void dijkstra(int s,int t){
	// mang luu khoang cach duong di
	vector<long long> d(n+1,1e9);
	d[s]=0;
	pre[s]=s;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int>top=q.top();q.pop();
		int u=top.second;
		int kc=top.first;
		if(kc>d[u]) continue;
		for(auto it:adj[u]){
			int v=it.first;
			int w=it.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				q.push({d[v],v});
				pre[v]=u;
			}
		}
	}for(int i=1;i<=n;++i){
		cout<<d[i]<<" ";
	}cout<<endl;
	cout<<d[t]<<endl;
	vector<int>path;
	while(1){
		path.push_back(t);
		if(t==s) break;
		t=pre[t];
	}reverse(path.begin(),path.end());
	for(auto x:path){
		cout<<x<<" ";
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		for(int i=0;i<1001;++i) adj[i].clear();
		nhap();
		dijkstra(s,h);
	}
}
