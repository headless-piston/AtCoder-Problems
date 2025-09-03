#include<cstdio>
#include<algorithm>
#include<map>
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
int T,n;
map<int,int> fa;
int find(int x){
    if(!fa.count(x)) fa[x]=x;
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct node{
    int l,r;
    bool operator<(const node &x)const{
        if(r==x.r) return l<x.l;
        return r<x.r;
    }
}a[N];
int main(){
    read(T);
    while(T--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i].l,a[i].r);
        sort(a+1,a+1+n);
        bool f=1;
        for(int i=1;i<=n;i++){
            int p=find(a[i].l);
            if(p>a[i].r){f=0;break;}
            fa[p]=p+1;
        }
        printf(f?"Yes\n":"No\n");
        fa.clear();
    }
    return 0;
}
