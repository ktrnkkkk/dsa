#include<bits/stdc++.h>
using namespace std;
bool visited[1001];
int n,m;
void dfs(int u,vector<int>adj[]){
    visited[u]=true;
    for(int v:adj[u]){
        dfs(v,adj);
    }
}

int main(){
    cin>>n>>m;
    vector<int>adj[n+5];
    for(int i=1;i<=m;++i){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }memset(visited,false,sizeof(visited));
    int tplt=0;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            ++tplt;
            dfs(i,adj);
        }
    }if(tplt==1) cout<<1<<endl;
    else cout<<0<<endl;
}
