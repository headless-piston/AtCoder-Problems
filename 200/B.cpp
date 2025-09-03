#include<iostream>
using namespace std;
typedef long long ll;
int k;
ll n;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        if(n%200==0) n/=200;
        else n=n*1000+200;
    }
    cout<<n<<'\n';
    return 0;
}
