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
constexpr int N=2e5+10;
int n,l,r,premin[N],premax[N],nxtmin[N],nxtmax[N];
struct node{
    int x,y;
    bool operator<(const node &a)const{return x<a.x;}
}a[N];
bool check(int d){
    for(int i=1,j=1;j<=n;j++){
        while(i<n&&a[j].x-a[i].x>=d) ++i;
        int d1=premax[i-1]-nxtmin[j];
        int d2=nxtmax[j]-premin[i-1];
        if(max(d1,d2)>=d) return 1;
    }
    return 0;
}
int main(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i].x,a[i].y);
    sort(a+1,a+1+n);
    premin[0]=nxtmin[n+1]=1e9;
    for(int i=1;i<=n;i++){
        premin[i]=premax[i]=a[i].y;
        nxtmin[i]=nxtmax[i]=a[i].y;
    }
    for(int i=2;i<=n;i++){
        premin[i]=min(premin[i],premin[i-1]);
        premax[i]=max(premax[i],premax[i-1]);
    }
    for(int i=n-1;i;i--){
        nxtmin[i]=min(nxtmin[i],nxtmin[i+1]);
        nxtmax[i]=max(nxtmax[i],nxtmax[i+1]);
    }
    l=0,r=1e9;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",r);
    return 0;
}
