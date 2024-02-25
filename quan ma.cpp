#include<bits/stdc++.h>
using namespace std;
int d[10][10];
int visited[10][10];
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
int bfs(int s,int t,int u,int v){
	queue<pair<int,int>>q;
	q.push({s,t});
	d[s][t]=0;
	visited[s][t]=1;
	while(!q.empty()){
		pair<int,int>top=q.front();
		q.pop();
		if(top.first==u&&top.second==v) return d[u][v];
		int i=top.first,j=top.second;
		for(int k=0;k<8;++k){
			int i1=i+dx[k],j1=j+dy[k];
			if(i1>=1&&i1<=8&&j1>=1&&j1<=8&&!visited[i1][j1]){
				q.push({i1,j1});
				d[i1][j1]=d[i][j]+1;
				visited[i1][j1]=1;
			}
		}
	}return -1;
}
int main(){
	int t;cin>>t;
	while(t--){
		string st,en;cin>>st>>en;
		int s,t,u,v;
		t=st[0]-'a'+1;
		s=8-(st[1]-'0')+1;
		v=en[0]-'a'+1;
		u=8-(en[1]-'0')+1;
		cout<<bfs(s,t,u,v)<<endl;
		memset(d,0,sizeof(d));
		memset(visited,0,sizeof(visited));
	}
}
