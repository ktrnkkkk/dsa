#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int n,m,parent[maxn],sz[maxn];
struct edge{
	int u,v;
};
vector<edge> canh;
void make_set(){
	for(int i=1;i<=n;++i){
		parent[i]=i;
		sz[i]=1;
	}
}
int find(int v){
	if(v==parent[v]) return v;
	return parent[v]=find(parent[v]);
}
void Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b) {
		if(sz[a]<sz[b]) swap(a,b);
		parent[b]=a;
	    sz[a]+=sz[b];
	}
}
void inp(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int x,y; cin>>x>>y;
		edge e;
		e.u=x;e.v=y;
		canh.push_back(e);
	}
}
void ketban(){
	for(int i=0;i<m;++i){
		edge e=canh[i];
		Union(e.u,e.v);
	}
	int ok=0,node=find(canh[0].u);
	for(int i=1;i<=n;++i){
		if(node!=find(i)){
			ok=0;
			break;
		}
	}if(ok) cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	int t;cin>>t;
	while(t--){
		memset(parent,0,sizeof(parent));
		memset(sz,0,sizeof(sz));
		canh.clear();
		inp();
		make_set();
		ketban();
	}
}
