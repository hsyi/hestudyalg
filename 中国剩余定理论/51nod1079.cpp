#include <iostream>
using namespace std;
const int maxn=11;
typedef long long ll;
ll M[maxn];
ll MOD=1;
int p[maxn];
int a[maxn];
ll getinv(ll x,ll mod){
    int mi=mod-2;
    ll temp=1;
    ll mul=x;
    while(mi){
        if(mi&1) temp=(temp*mul)%mod;
        mul=(mul*mul)%mod;
        mi>>=1;
    }
    return temp;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i]>>a[i];
        MOD*=p[i];
    }
    for(int i=0;i<n;i++){
        M[i]=MOD/p[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        cout<<getinv(M[i],p[i])<<endl;
        ans=(ans+getinv(M[i],p[i])*a[i]*M[i])%MOD;
    }
    cout<<ans<<endl;

}