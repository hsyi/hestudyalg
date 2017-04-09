#include<iostream>
#include<cstring>
using namespace std;
const int maxn=20011;
int sg[maxn];
bool vis[maxn];
int main(){
    sg[0]=0;
    for(int i=1;i<maxn;i++){
        memset(vis,0,sizeof(vis));
        for(int j=0;j<i;j++){
            vis[sg[j]]=true;
        }
        for(int j=1;j<i;j++){
            vis[sg[j]^sg[i-j]]=true;
        }
        for(int j=0;j<=i+1;j++){
            if(!vis[j]) {
                sg[i]=j;
                break;
            }
        }
        cout<<i<<":"<<sg[i]<<"  "<<i%4<<endl;
    }
    int n;
    cin>>n;
    int ans=0;
    while(n--){
        int t;
        cin>>t;
        ans^=sg[t];
    }
    if(ans) cout<<"Alice\n";
    else cout<<"Bob\n";
    return 0;
}


