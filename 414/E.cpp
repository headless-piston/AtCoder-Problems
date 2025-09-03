#include<cstdio>
#include<algorithm>
using namespace std;
template<typename T>
inline void read(T &x){
    bool f=0;x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    if(f) x=~x+1;
}
typedef long long ll;
constexpr int mod=998244353;
ll n,m,ans;
int main(){
    read(n);
    m=n%mod;
    ans=m*(m+1)%mod*499122177%mod;
    ll l=1,r=0;
    for(;l<=n;l=r+1){
        r=min(n/(n/l),n);
        ans=(ans-(r-l+1)%mod*(n/l)%mod)%mod;
    }
    printf("%lld\n",(ans+mod)%mod);
    return 0;
}
