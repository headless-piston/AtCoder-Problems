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
template<typename T,typename...Args>
void read(T &x,Args &...args){read(x);read(args...);}
typedef long long ll;
int a,b,cnta,cntb;
ll k;
ll binom(int n,int m){
    if(n<m) return 0;
    if(n-m<m) m=n-m;
    ll res=1;
    for(int i=1;i<=m;i++)
        res*=(n-m+i),res/=i;
    return res;
}
int main(){
    read(a,b,k);
    cnta=a,cntb=b;
    for(int i=a+b;i;i--){
        ll sum=binom(cnta+cntb-1,cntb);
        if(k>sum) printf("b"),k-=sum,--cntb;
        else printf("a"),--cnta;
    }
    return 0;
}
