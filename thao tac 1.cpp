#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    stack<int>st;
    while(t--){
        string s;cin>>s;
        if(s=="push"){
            int n;cin>>n;
            st.push(n);
        }else if(s=="show"){
            vector<int>v;
            if(st.empty()) {
               cout<<"EMPTY\n";
               continue;
            }
            while(!st.empty()){
                v.push_back(st.top());
                st.pop();
            }reverse(v.begin(),v.end());
            for(int i=0;i<v.size();++i){
                cout<<v[i]<<" ";
                st.push(v[i]);
            }cout<<endl;
        }
    }
}

