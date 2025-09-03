#include<iostream>
using namespace std;
constexpr int N=110;
int n,a[N],x;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>x;
    for(int i=1;i<=n;i++){
        if(a[i]==x){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}
