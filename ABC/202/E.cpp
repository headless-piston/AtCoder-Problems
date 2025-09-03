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
constexpr int N=2e5+10;
int n,dep[N],q,b[N],ans[N];
vector<int> e[N];
struct query{int x,id;};
vector<query> ask[N];
void dfs(int u,int fa){
    for(auto [x,id]:ask[u]) ans[id]=-b[x];
    dep[u]=dep[fa]+1;
    ++b[dep[u]];
    for(int v:e[u]) dfs(v,u);
    for(auto [x,id]:ask[u]) ans[id]+=b[x];
}
int main(){
    read(n);
    for(int i=2,p;i<=n;i++){
        read(p);
        e[p].push_back(i);
    }
    read(q);
    for(int i=1,u,d;i<=q;i++){
        read(u,d);
        ask[u].push_back({d,i});
    }
    dep[0]=-1;
    dfs(1,0);
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}
