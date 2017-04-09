//杨氏矩阵，钩子公式，扩展欧几里德求逆元
#include<iostream>
using namespace std;
const long long  mod=1e9+7;
const int maxm=1e5+11;
const int maxn=3;
long long fac[maxm*maxn];
void getfac(){
    int e=maxm*maxn;
    fac[0]=1;
    for(int i=1;i<e;i++){
        fac[i]=(i*fac[i-1])%mod;
    }
}
long long  exgcd(int a,int b,int &x,int &y){
    if(b==0){x=1;y=0;return a;}
    long long d=exgcd(b,a%b,x,y);
    int t=x;x=y;y=t-a/b*y;
    return d;
}
long long getinv(int a){
    long long ret;
    int x,y;
    exgcd(a,mod,x,y);
    ret=x;
    return ret;
}
int main(){
    int n,m;
    cin>>n>>m;
    getfac();
    long long  ans=fac[n*m];
   // cout<<"\\\\ "<<ans<<endl;
    long long  tmp=1;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++){
            tmp=(tmp*(x+y-1))%mod;
      //      cout<<"===="<<(x+y-1);
        }
    }
    //cout<<"\n\\\\\\ "<<tmp<<endl;
    tmp=getinv(tmp);
 //   cout<<"\\\\\\\\\\="<<tmp<<endl;
    tmp=(tmp+mod)%mod;
    ans=(ans*tmp)%mod;
    cout<<ans;
    return 0;
}




