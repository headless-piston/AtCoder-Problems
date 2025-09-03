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
constexpr int N=5010,mod=998244353;
int n,m,k,f[N][N],sum;
vector<int> e[N];
int main(){
    read(n,m,k);
    for(int i=1,u,v;i<=m;i++){
        read(u,v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    f[0][1]=1;
    for(int i=1;i<=k;i++){
        sum=0;
        for(int j=1;j<=n;j++)
            sum=(sum+f[i-1][j])%mod;
        for(int u=1;u<=n;u++){
            f[i][u]=sum-f[i-1][u];
            if(f[i][u]<0) f[i][u]+=mod;
            for(int v:e[u]){
                f[i][u]-=f[i-1][v];
                if(f[i][u]<0) f[i][u]+=mod;
            }
        }
    }
    printf("%d\n",f[k][1]);
    return 0;
}
