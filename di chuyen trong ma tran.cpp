#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int d[1005][1005];
int visited[1005][1005];
int n,m;
void nhap(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
}
int bfs(int i,int j){
	queue<pair<int,int>>q;
	q.push({i,j});
	d[i][j]=0;
    while(!q.empty()){
    	pair<int,int>top=q.front();
    	q.pop();
    	int i=top.first,j=top.second;
    	if(i==n&&j==m) return d[n][m];
    	if(j+a[i][j]<=m&&!visited[i][j+a[i][j]]){
    		q.push({i,j+a[i][j]});
    		visited[i][j+a[i][j]]=1;
    		d[i][j+a[i][j]]=d[i][j]+1;
		}if(i+a[i][j]<=n&&!visited[i+a[i][j]][j]){
    		q.push({i+a[i][j],j});
    		visited[i+a[i][j]][j]=1;
    		d[i+a[i][j]][j]=d[i][j]+1;
		}
	}return -1;
}
int main(){
	int t;cin>>t;
	while(t--){
		nhap();
		memset(visited,0,sizeof(visited));
		memset(d,0,sizeof(d));
		cout<<bfs(1,1)<<endl;
	}
}
