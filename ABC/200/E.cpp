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
constexpr int N=1e6+10;
int n,ans,sum;
ll k;
inline ll C(int x){
    if(x<2) return 0;
    return ll(x)*(x-1)/2;
}
inline ll tot(int i){
    return C(i-1)-3*C(i-n-1)+3*C(i-2*n-1)-C(i-3*n-1);
}
signed main(){
    read(n,k);
    for(int i=3;i<=3*n;i++){
        ll p=tot(i);
        if(k>p) k-=p;
        else{
            sum=i;
            break;
        }
    }
    for(int i=1;i<=sum-2;i++){ 
        int l=max(1,sum-i-n),r=min(n,sum-1-i);
        if(l>r) continue;
        if(k>r-l+1) k-=r-l+1;
        else{
            printf("%d %lld %lld\n",i,l+k-1,sum-i-(l+k-1));
            break;
        }
    }
    return 0;
}
