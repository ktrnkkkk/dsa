#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	stack<string>st;
	for(int i=s.size()-1;i>=0;--i){
		if(isalpha(s[i])){
			st.push(string(1,s[i]));
		}else{
			string op1=st.top();st.pop();
			string op2=st.top();st.pop();
			string tmp=op1+op2+s[i];
			st.push(tmp);
		}
	}cout<<st.top()<<endl;
}
