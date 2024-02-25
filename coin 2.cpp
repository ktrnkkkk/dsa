using namespace std;
int main(){
	int n,s; cin>>n>>s;
	int coin[n];
	for(int &x:coin) cin>>x;
	int f[s+1]={0};
	f[0]=1;
	for(int i=1;i<=s;++i){
		for(int c:coin){
			if(i>=c){
				f[i]+=f[i-c];
				f[i]%=1e9;
			}
		}
	}cout<<f[s]<<endl;
}
