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
typedef long long ll;
constexpr int N=2e5+10;
int n,h[N],st[N],top;
ll f[N];
int main(){
    read(n);
    for(int i=1;i<=n;i++) read(h[i]);
    for(int i=1;i<=n;i++){
        while(top&&h[st[top]]<=h[i]) --top;
        if(top) f[i]=f[st[top]]+ll(i-st[top])*h[i];
        else f[i]=ll(i)*h[i];
        st[++top]=i;
    }
    for(int i=1;i<=n;i++) printf("%lld ",f[i]+1);
    return 0;
}
