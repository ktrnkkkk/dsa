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
void dfs2(int u,int s,int t,vector<int>adj[]){
    visited[u]=true;
    for(int v:adj[u]){
        if((u==s&&v==t)||(u==t&&v==s))continue;
        if(!visited[v]){
            dfs2(v,s,t,adj);
        }
    }
}
int canhcau(vector<int>adj[],vector<pair<int,int>>dscanh){
    int tplt=0,cnt=0;
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            ++tplt;
            dfs(i,adj);
        }
    }for(auto it:dscanh){
        int x=it.first,y=it.second;
        memset(visited,false,sizeof(visited));
        int dem=0;
        for(int i=1;i<=n;++i){
            if(!visited[i]){
                ++dem;
                dfs2(i,x,y,adj);
            }
        }if(dem>tplt){
            ++cnt;
        }
    }return cnt;
}
int main(){
        cin>>n>>m;
        memset(visited,false,sizeof(visited));
        vector<int>adj[n+5];
        vector<pair<int,int>>dscanh;
        for(int i=1;i<=m;++i){
            int x,y;cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            dscanh.push_back({x,y});
        }cout<<canhcau(adj,dscanh)<<endl;
}


