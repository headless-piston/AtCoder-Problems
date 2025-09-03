#include<cstdio>
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
int n,q,fa[N],siz[N],op,u,v;
bool vis[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
    read(n,q);
    for(int i=1;i<=n;i++) fa[i]=i;
    while(q--){
        read(op);
        if(op==1){
            read(u,v);
            u=find(u),v=find(v);
            if(u==v) continue;
            fa[u]=v;
            siz[v]+=siz[u];
        }
        else if(op==2){
            read(v);
            if(vis[v]) --siz[find(v)];
            else ++siz[find(v)];
            vis[v]^=1;
        }
        else{
            read(v);
            printf(siz[find(v)]?"Yes\n":"No\n");
        }
    }
    return 0;
}
