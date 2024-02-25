#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int k;cin>>k;
    vector<pair<char,int>>st;
    for(int i=0;i<s.size();++i){
        if(st.empty()){
            st.push_back({s[i],1});
        }else{
            pair<char,int> x=st.back();
            if(x.first==s[i]&&x.second+1==k){
                st.pop_back();
            }else{
                if(x.first==s[i]){
                    st.back().second++;
                }else{
                    st.push_back({s[i],1});
                }
            }
        }
    }if(st.empty()) cout<<"EMPTY\n";
    else{
        for(auto x: st){
            for(int i=0;i<x.second;++i)
            cout<<x.first;
        }
    }
}
