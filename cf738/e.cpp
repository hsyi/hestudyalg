#include<iostream>
using namespace std;
const int MAXN=2e5+11;
int a[MAXN];
int flag[MAXN];
int n,s;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++) {cin>>a[i];if(i!=s && a[i]==0) a[i]=n;}
    int ans=0;
    if(a[s]!=0) {a[s]=0;ans++;}
    for(int i=1;i<=n;i++) flag[a[i]]++;
    int p=n;
    int cnt=0;
    for(int i=0;cnt<n;i++) {
        if(flag[i]==0){
            while(flag[p]==0) p--;
            flag[i]=1;
            flag[p]--;
            ans++;
        }
        cnt+=flag[i];
    }
    cout<<ans;
}
    
