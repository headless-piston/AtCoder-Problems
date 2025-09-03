#include<iostream>
#include<cmath>
using namespace std;
int a;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a;
    a=ceil(a/100.0);
    cout<<a;
    return 0;
}
