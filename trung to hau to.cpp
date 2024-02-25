#include<bits/stdc++.h>
using namespace std;
int uutien(char c){
	if(c=='^') return 3;
	if(c=='*'||c=='/') return 2;
	if(c=='+'||c=='-') return 1;
	return 0;
}
int main(){
	int t;cin>>t;
	while(t--){
	string s;cin>>s;
	stack<char> st;
	string res="";
	for(int i=0;i<s.size();++i){
		if(s[i]=='('){
			st.push(s[i]);
		}else if(isalpha(s[i])){
			res+=s[i];
		}else if(s[i]==')'){
			while(st.top()!='('){
				res+=st.top();
				st.pop();
			}st.pop();
		}else{
			while(!st.empty()&&uutien(st.top())>=uutien(s[i])){
				res+=st.top();
				st.pop();
			}st.push(s[i]);
		}
	}while(!st.empty()){
		res+=st.top();
		st.pop();
	}stack<long long>st1;
		for(int i=0;i<res.size();++i){
			if(res[i]=='+'||res[i]=='-'||res[i]=='*'||res[i]=='/'||res[i]=='%'){
				long long fi=st1.top();st1.pop();
				long long se=st1.top();st1.pop();
				long long tmp;
				if(res[i]=='+') tmp=fi+se;
				else if(res[i]=='-') tmp=se-fi;
				else if(res[i]=='*') tmp=se*fi;
				else if(res[i]=='/') tmp=se/fi;
				else if(res[i]=='%') tmp=se%fi;
				else if(res[i]=='^'){
					tmp=se;
					for(int i=1;i<=fi;++i){
						tmp*=se;
					}
				}st1.push(tmp);
			}else st1.push((long long)(res[i]-'0'));
		}cout<<st1.top()<<endl;
}}
