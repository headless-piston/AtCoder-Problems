#include<iostream>
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
constexpr int N=5e5+10;
char s[N];
int n,P,q;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
struct node{
    int lc,rc,maxl,maxr,maxn,len;
    friend node operator+(const node &a,const node &b){
        if(a.lc==0) return b;
        if(b.lc==0) return a;
        node res;
        res.lc=a.lc,res.rc=b.rc;
        res.maxn=max(a.maxn,b.maxn);
        res.maxl=a.maxl,res.maxr=b.maxr;
        res.len=a.len+b.len;
        if(a.rc==b.lc){
            res.maxn=max(res.maxn,a.maxr+b.maxl);
            if(a.len==a.maxl) res.maxl+=b.maxl;
            if(b.len==b.maxr) res.maxr+=a.maxr;
        }
        return res;
    }
}tree[N<<2];
inline void modify(int x,int k){
    x+=P;
    tree[x]={k,k,1,1,1,1};
    for(x>>=1;x;x>>=1) tree[x]=tree[ls(x)]+tree[rs(x)];
}
inline node query(int l,int r){
    l+=P-1,r+=P+1;
    node resl={},resr={};
    while(l^1^r){
        if(~l&1) resl=resl+tree[l^1];
        if(r&1) resr=tree[r^1]+resr;
        l>>=1,r>>=1;
    }
    return resl+resr;
}
int op,x,y;
char ch;
int main(){
    read(n,q);
    scanf("%s",s+1);
    P=1;
    while(P<=n+1) P<<=1;
    for(int i=1;i<=n;i++) tree[i+P]={s[i],s[i],1,1,1,1};
    for(int i=P-1;i;i--) tree[i]=tree[ls(i)]+tree[rs(i)];
    while(q--){
        read(op,x);
        if(op&1){
            scanf(" %c",&ch);
            modify(x,ch);
        }
        else{
            read(y);
            printf("%d\n",query(x,y).maxn);
        }
    }
    return 0;
}
