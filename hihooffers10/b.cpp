#include<iostream>
using namespace std;
const long long mod=1e9+7;
const int maxn=1e5+11;
long long f[maxn]={1,2,4,7,0};
int main(){
    for(int i=4;i<maxn;i++){
        //f[i]=(2*f[i-2]+3*f[i-3])%mod;
        //f[i]=(2*f[i-1]-f[i-4])%mod;
        f[i]=(2*f[i-2]+2*f[i-3]+f[i-4])%mod;
    }
    int a;
    cin>>a;
    long long ans=0;
    ans+=f[a];
    //cout<<"==="<<ans<<endl;
    for(int i=1;i<=a;i++){
        ans=(ans+f[i-1]*f[a-i]%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}

