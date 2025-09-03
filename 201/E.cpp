#include<cstdio>
#include<vector>
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
template<typename T,typename...Args>
void read(T &x,Args &...args){read(x);read(args...);}
typedef long long ll;
constexpr int N=2e5+10,mod=1e9+7;
int n,ans;
ll dis[N];
struct edge{int v;ll w;};
vector<edge> e[N];
void dfs(int u,int fa){
    for(auto [v,w]:e[u]){
        if(v==fa) continue;
        dis[v]=dis[u]^w;
        dfs(v,u);
    }
}
int main(){
    read(n);
    for(int i=1,u,v;i<n;i++){
        ll w;
        read(u,v,w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,0);
    for(int i=0;i<60;i++){
        int cnt=0;
        for(int j=1;j<=n;j++)
            cnt+=dis[j]>>i&1;
        ans=(ans+(1ll<<i)%mod*cnt%mod*(n-cnt))%mod;
    }
    printf("%d\n",ans);
    return 0;
}
