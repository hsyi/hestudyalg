#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXM=2e5+11;
const int MAXK=2e5+11;
typedef long long ll;
ll a[MAXM],b[MAXM],c[MAXK],d[MAXK];
int n,m,k;
int x,s;
int main(){
    cin>>n>>m>>k;
    cin>>x>>s;
    a[0]=x;
    b[0]=0;
    c[0]=0;
    d[0]=0;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
    }
    for(int i=1;i<=k;i++){
        cin>>d[i];
    }
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<=m;i++){
        ll points=s-b[i];
        if(points<0) continue;
        int p=upper_bound(d,d+k+1,points)-d;
        if(p>k) p=k;
        else p=p-1;
        ll tmp=n-c[p];
        ans=min(ans,tmp*a[i]);
    }
    cout<<ans;
    return 0;
}
