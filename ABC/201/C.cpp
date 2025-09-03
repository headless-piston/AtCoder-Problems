#include<cstring>
#include<iostream>
using namespace std;
char s[20];
bool f[20];
bool check(int x){
    string n=to_string(x);
    while(n.length()<4) n.push_back('0');
    memset(f,0,sizeof(f));
    for(char c:n) f[c-'0']=1;
    for(int i=0;i<=9;i++)
        if(f[i]&&s[i]=='x') return 0;
        else if(!f[i]&&s[i]=='o') return 0;
    return 1;
}
int ans;
int main(){
    cin>>s;
    for(int i=0;i<10000;i++)
        ans+=check(i);
    cout<<ans<<'\n';
    return 0;
}
