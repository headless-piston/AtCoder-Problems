#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
constexpr int N=5e5+10;
int n,a[N],b[N],cnta,cntb;
ll ans1,ans2;
string s;
int main(){
    cin>>n>>s;
    for(int i=0;i<(int)s.length();i++){
        if(s[i]=='A') a[++cnta]=i+1;
        else b[++cntb]=i+1;
    }
    for(int i=1;i<=n;i++){
        ans1+=abs(a[i]-(i*2-1));
        ans2+=abs(b[i]-(i*2-1));
    }
    cout<<min(ans1,ans2)<<'\n';
    return 0;
}
