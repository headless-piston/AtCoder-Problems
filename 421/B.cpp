#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int x,y;
ll f(ll a,ll b){
    long long c=a+b,res=0;
    string s=to_string(c);
    reverse(s.begin(),s.end());
    for(int i=0;i<(int)s.size();i++)
        res=res*10+s[i]-'0';
    return res;
}
ll fi[20];
int main(){
    cin>>x>>y;
    fi[1]=x,fi[2]=y;
    for(int i=3;i<=10;i++)
        fi[i]=f(fi[i-1],fi[i-2]);
    cout<<fi[10]<<'\n';
    return 0;
}
