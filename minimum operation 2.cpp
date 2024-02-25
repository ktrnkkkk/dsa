#include<bits/stdc++.h>
using namespace std;
int bfs(int s){
	queue<pair<int,int>>q;
	set<int>se;
	q.push({s,0});
	se.insert(s);
	while(!q.empty()){
		pair<int,int> top=q.front();
		q.pop();
		int x=top.first,y=top.second;
		if(x==1) return y;
		if(!se.count(x-1)&&x-1>0){
			q.push({x-1,y+1});
			se.insert(x-1);
		}for(int i=2;i<=sqrt(x);++i ){
			if(x%i==0){
				if(!se.count(max(i,x/i))){
					q.push({max(i,x/i),y+1});
					se.insert(max(i,x/i));
				}
			}
		}
	}return -1;
}
int main(){
	int t;cin>>t;
	while(t--){
	    int s;
		cin>>s;
		cout<<bfs(s)<<endl;	
	}
}
