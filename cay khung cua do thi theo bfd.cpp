#include<bits/stdc++.h>
using namespace std;
int n,m,u;
vector<int> ke[1001];
vector<pair<int,int>> e;
int ok[1001];
void BFS(int u){
	queue<int> q;
	q.push(u);
	ok[u]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto i:ke[x]){
			if(ok[i]==0){
				e.push_back({x,i});
				ok[i]=1;
				q.push(i);
			}
		}
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		memset(ok,0,sizeof(ok));
		for(int i=1;i<1001;i++) ke[i].clear();
		e.clear();
		cin>>n>>m>>u;
		for(int i=1;i<=m;++i){
			int x,y;cin>>x>>y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		BFS(u);
		if(e.size()==n-1){
			for(auto i:e){
				cout<<i.first<<" "<<i.second<<endl;
			}
		}else cout<<-1<<endl;
	}
}
