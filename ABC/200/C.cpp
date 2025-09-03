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
int n,a[N];
ll ans,b[210];
int main(){
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);
        ++b[a[i]%200];
    }
    for(int i=0;i<200;i++)
        ans+=b[i]*(b[i]-1)/2;
    printf("%lld\n",ans);
    return 0;
}
