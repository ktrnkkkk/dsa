#include<bits/stdc++.h>
using namespace std;
vector<int> trai (vector<int>a){
	vector<int>res(6);
	res[0]=a[3];res[1]=a[0];res[2]=a[2];
	res[3]=a[4];res[4]=a[1];res[5]=a[5];
	return res;
}
vector<int> phai (vector<int>a){
	vector<int>res(6);
	res[0]=a[0];res[1]=a[4];res[2]=a[1];
	res[3]=a[3];res[4]=a[5];res[5]=a[2];
	return res;
}
bool check(vector<int>a,vector<int>b){
	for(int i=0;i<6;++i){
		if(a[i]!=b[i]) return false;
	}return true;
}
int bfs(vector<int>a,vector<int>b){
	queue<pair<vector<int>,int>>q;
	q.push({a,0});
	set<vector<int>>se;se.insert(a);
    while(!q.empty()){
    	pair<vector<int>,int>top=q.front();
    	q.pop();
    	if(check(top.first,b)) return top.second;
    	vector<int> l=trai(top.first);
    	if(!se.count(l)){
    		q.push({l,top.second+1});
    		se.insert(l);
		}vector<int> r=phai(top.first);
    	if(!se.count(r)){
    		q.push({r,top.second+1});
    		se.insert(r);
		}
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		vector<int>a(6),b(6);
		for(int i=0;i<6;++i) cin>>a[i];
		for(int i=0;i<6;++i) cin>>b[i];
		cout<<bfs(a,b)<<endl;
	}
}

