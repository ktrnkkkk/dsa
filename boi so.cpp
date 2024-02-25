#include<bits/stdc++.h>
using namespace std;
vector<long long>res;
void init(){
	queue<string>q;
	res.push_back(9);
	q.push("9");
	while(1){
		string top=q.front();q.pop();
		if(top.size()==15) break;
		res.push_back(stoll(top+"0"));
		res.push_back(stoll(top+"9"));
		q.push(top+"0");
		q.push(top+"9");
	}
}
int main(){
	int t;cin>>t;
	init();
	while(t--){
	    int n;cin>>n;
		for(long long x:res){
			if(x%n==0){
				cout<<x<<endl;
				break;
			}
		}
		
	}
}

