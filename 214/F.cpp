#include<cstdio>
#include<cstring>
using namespace std;
constexpr int N=2e5+10,mod=1e9+7;
char s[N];
int n,f[N][26],ans;
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    f[1][s[1]-'a']=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<26;j++){
            if(s[i]=='a'+j){
                f[i][j]=1;
                for(int k=0;k<26;k++)
                    f[i][j]=(f[i][j]+f[i-2][k])%mod;
            }
            else f[i][j]=f[i-1][j];
        }
    for(int i=0;i<26;i++) ans=(ans+f[n][i])%mod;
    printf("%d\n",ans);
    return 0;
}
