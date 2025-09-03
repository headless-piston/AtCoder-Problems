#include<iostream>
#include<cstring>
using namespace std;
constexpr int N=2010;
int h,w,f[N][N],a[N][N];
char c;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>h>>w;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++){
            cin>>c;
            a[i][j]=c=='+'?1:-1;
        }
    memset(f,0x3f,sizeof(f));
    f[h][w]=0;
    for(int i=h;i;i--)
        for(int j=w;j;j--){
            f[i-1][j]=min(f[i-1][j],-(f[i][j]+a[i][j]));
            f[i][j-1]=min(f[i][j-1],-(f[i][j]+a[i][j]));
        }
    if(f[1][1]>0) printf("Aoki\n");
    else if(f[1][1]<0) printf("Takahashi\n");
    else printf("Draw\n");
    return 0;
}
