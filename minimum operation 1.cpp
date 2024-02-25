#include<bits/stdc++.h>
using namespace std;
int d[1000001]={0};
int bfs(int s,int t){
	queue<int>q;
	set<int>se;
	q.push(s);
	d[s]=0;
	se.insert(s);
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(top==t) return d[t];
		if(!se.count(top*2)){
			q.push(top*2);
			se.insert(top*2);
			d[top*2]=d[top]+1;
		}if(!se.count(top-1)&&top-1>0){
			q.push(top-1);
			se.insert(top-1);
			d[top-1]=d[top]+1;
		}
	}return -1;
}
int main(){
	int t;cin>>t;
	while(t--){
	    int u,v;
		cin>>u>>v;
		cout<<bfs(u,v)<<endl;	
	}
}
