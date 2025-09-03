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
constexpr int N=5e5+10;
int q,op,nxt[N],x,y,l,r;
ll sx,sy;
int main(){
    read(q);
    nxt[0]=-1;
    for(int i=1;i<=q;i++){
        read(op);
        if(op==1){
            read(x);
            nxt[i]=nxt[x];
            nxt[x]=i;
        }
        else{
            read(x,y);
            l=x,r=y;
            sx=sy=0;
            while(1){
                if(nxt[l]!=-1){
                    l=nxt[l];
                    if(l==y){
                        printf("%lld\n",sx);
                        nxt[x]=y;
                        break;
                    }
                    else sx+=l;
                }
                if(nxt[r]!=-1){
                    r=nxt[r];
                    if(r==x){
                        printf("%lld\n",sy);
                        nxt[y]=x;
                        break;
                    }
                    else sy+=r;
                }
            }
        }
    }
    return 0;
}
