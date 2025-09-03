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
constexpr int N=210;
int n,a[N],ans[N][10],now[10],len[N];
void dfs(int x,int sum,int cnt){
    if(x==9||x>n){
        if(ans[sum][1]){
            printf("Yes\n");
            printf("%d ",len[sum]);
            for(int i=1;i<=len[sum];i++)
                printf("%d ",ans[sum][i]);
            printf("\n%d ",cnt);
            for(int i=1;i<=cnt;i++)
                printf("%d ",now[i]);
            printf("\n");
            exit(0);
        }
        len[sum]=cnt;
        for(int i=1;i<=cnt;i++)
            ans[sum][i]=now[i];
        return;
    }
    dfs(x+1,sum,cnt);
    now[++cnt]=x;
    dfs(x+1,(sum+a[x])%200,cnt);
}
int main(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]),a[i]%=200;
    dfs(1,0,0);
    printf("No\n");
    return 0;
}
