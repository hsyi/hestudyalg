#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=2e5+11;
int b[MAXN],c[MAXN],a[MAXN];
int n;
bool check(){
    vector<int> cntk;
    for(int bit=0;bit<32;bit++){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]&(1<<bit)) cnt++;
        }
        cntk.push_back(cnt);
    }
    vector<vector<int> > B(n),C(n);
    for(int i=0;i<n;i++){
        B[i].resize(32);
        C[i].resize(32);
        for(int bit=0;bit<32;bit++){
            if(a[i]&(1<<bit)) {B[i][bit]=cntk[bit];C[i][bit]=n;}
            else {B[i][bit]=0;C[i][bit]=cntk[bit];}
        }
    }
    for(int i=0;i<n;i++){
        int tmpb=0,tmpc=0;
        for(int bit=0;bit<32;bit++){
            tmpb+=B[i][bit]<<bit;
            tmpc+=C[i][bit]<<bit;
        }
        if(tmpb!=b[i] || tmpc !=c[i]) return false;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];
    long long sumbc=0;;
    for(int i=0;i<n;i++) sumbc+=b[i]+c[i]; 
    sumbc=sumbc/(2*n);
    for(int i=0;i<n;i++) a[i]=(b[i]+c[i]-sumbc)/n;
    if(!check()) cout<<"-1\n";
    else {
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
    }
    return 0;
}


