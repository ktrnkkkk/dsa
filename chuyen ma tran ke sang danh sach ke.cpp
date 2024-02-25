#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>adj[n+1];
	vector<pair<int,int>>v;
	int a[n+1][n+1];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]==1&&i<j){
			     v.push_back({i,j});
			}
		}
	}for(int i=v.size()-1;i>=0;--i){
	    cout<<v[i].second<" "<<v[i].first<<endl;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]==1&&i<j){
			     adj[i].push_back(j);
			     adj[j].push_back(i);
			}
		}
	}for(int i=1;i<=n;++i){
		cout<<i<<" : ";
	   for(auto x:adj[i]){
	   	cout<<x<<" ";
	   	cout<<endl;
	   }
	}

}

