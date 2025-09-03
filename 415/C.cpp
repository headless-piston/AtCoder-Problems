#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;
typedef long long ll;
int t,n;
string s;
bool flag;
void check(int x){
    for(int i=0;i<n;i++)
        cout<<(x>>i&1);
    cout<<'\n';
}
bitset<1<<18> vis;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>s;
        s=" "+s;
        vis[0]=1;
        for(int i=1;i<(1<<n);i++){
            if(s[i]=='1') continue;
            for(int j=0;j<n;j++){
                if(~i>>j&1) continue;
                bool a=vis[i],b=vis[i^(1<<j)];
                vis[i]=a|b;
            }
        }
        if(vis[(1<<n)-1]) cout<<"Yes\n";
        else cout<<"No\n";
        vis.reset();
    }
    return 0;
}
/*
1
3
0010000
*/
