#include<iostream>
#include<queue>
using namespace std;
string s;
queue<int> q;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<(int)s.length();i++){
        if(s[i]=='#'){
            q.push(i+1);
        }
    }
    while(q.size()){
        int x=q.front();q.pop();
        int y=q.front();q.pop();
        cout<<x<<','<<y<<'\n';
    }
    
    return 0;
}
