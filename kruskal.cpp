#include<bits/stdc++.h>
using namespace std;
int n,m,parent[101],sz[101];

struct edge{
	int u,v,dd;
};
vector<edge> canh;
bool cmp(edge a,edge b){
	return a.dd<b.dd;
}
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
bool Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b) return false;
	if(a!=b) swap(a,b);
	parent[b]=a;
	sz[a]+=sz[b];
	return true;
}
void inp(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int x,y,z; cin>>x>>y>>z;
		edge e;
		e.u=x;e.v=y;e.dd=z;
		canh.push_back(e);
	}
}
void kruskal(){
	vector<edge>mst;
	int d=0;
	sort(canh.begin(),canh.end(),cmp);
	for(int i=0;i<m;++i){
		edge e=canh[i];
		if(Union(e.u,e.v)){
			mst.push_back(e);
			d+=e.dd;
		}
	}
	if(mst.size()==n-1){
		cout<<d<<endl;
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		memset(parent,0,sizeof(parent));
		memset(sz,0,sizeof(sz));
		canh.clear();
		inp();
		make_set();
		kruskal();
	}
}
