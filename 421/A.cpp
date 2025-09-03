#include<iostream>
using namespace std;
constexpr int N=110;
int n,x;
string s[N],y;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    cin>>x>>y;
    if(s[x]==y) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
