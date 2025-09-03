#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
constexpr int N=2e5+10;
ll n,ans;
int m;
struct node{
    ll a,b;
    bool operator<(const node &x)const{return a-b<x.a-x.b;}
}p[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>p[i].a>>p[i].b;
    sort(p+1,p+1+m);
    for(int i=1;i<=m;i++){
        if(p[i].a>n) continue;
        ll k=(n-p[i].a)/(p[i].a-p[i].b)+1;
        ans+=k;
        n-=(p[i].a-p[i].b)*k;
    }
    printf("%lld\n",ans);
    return 0;
}
