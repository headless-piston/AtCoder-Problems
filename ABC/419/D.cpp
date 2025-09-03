#include<iostream>
using namespace std;
constexpr int N=5e5+10;
int n,m,a[N],l,r;
string s,t;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>s>>t;
    while(m--){
        cin>>l>>r;
        ++a[l],--a[r+1];
    }
    for(int i=1;i<=n;i++) a[i]+=a[i-1];
    for(int i=0;i<n;i++)
        if(a[i+1]&1) cout<<t[i];
        else cout<<s[i];
    return 0;
}
