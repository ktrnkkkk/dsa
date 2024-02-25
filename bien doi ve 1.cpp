#include<bits/stdc++.h>
using namespace std;
int solve(int s){
	queue<pair<int,int>>q;
	set<int>se;
	se.insert(s);
	q.push({s,0});
	while(!q.empty()){
		pair<int,int> top=q.front();q.pop();
		if(top.first==1) return top.second;
		if(top.first%2==0){
			if(se.find(top.first/2)==se.end()&&top.first>0){
			q.push({top.first/2,top.second+1});
			se.insert(top.first/2);
		  }
		}
		if(top.first%3==0){
			if(se.find(top.first/3)==se.end()&&top.first>0){
			q.push({top.first/3,top.second+1});
			se.insert(top.first/3);
		 }
	    }
		if(se.find(top.first-1)==se.end()&&top.first>0){
			q.push({top.first-1,top.second+1});
			se.insert(top.first-1);
		}
	}return -1;
}
int main(){
	int t;cin>>t;
	while(t--){
		int s;cin>>s;
		cout<<solve(s)<<endl;
	}
}

