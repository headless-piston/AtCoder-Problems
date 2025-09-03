#include<cstdio>
#include<queue>
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
priority_queue<ll,vector<ll>,greater<ll>> q;
int Q,op,x;
ll tag;
int main(){
    read(Q);
    while(Q--){
        read(op);
        if(op==1){
            read(x);
            q.push(x-tag);
        }
        else if(op==2){
            read(x);
            tag+=x;
        }
        else{
            printf("%lld\n",q.top()+tag);
            q.pop();
        }
    }
    return 0;
}
