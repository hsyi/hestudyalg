#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXK=5e4+11;
const int MAXN=5e4+11;
int k;
int cnt[MAXK<<2];
void build(int l,int r,int rt){
    cnt[rt]=r-l+1;
    if(l==r) {cnt[rt]=1;return;}
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
}
int query(int l,int r,int rt,int k){
    if(l==r) {if(cnt[rt]) { cnt[rt]--;return l;}}
    int mid=(l+r)>>1;
    int ret=0;
    if(cnt[rt<<1]>=k) {ret= query(l,mid,rt<<1,k);}
    else {ret= query(mid+1,r,rt<<1|1,k-cnt[rt<<1]);}
    cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1];
    return ret;
}
int main(){
    int kas=0;
    ios_base::sync_with_stdio(0);
    cin>>kas;
    while(kas--){
        cin>>k;
        build(1,k,1);
   //     cout<<"cnt[1]-- "<<cnt[1]<<endl;
        for(int i=1;i<=k;i++){
            if(i!=1) cout<<" ";
            int s;
            cin>>s;
            int ans= query(1,k,1,s+1);
 //           cout<<"cnt[1] =="<<cnt[1]<<endl;
            cout<<ans;
        }
        cout<<endl;
    }
    return 0;
}
        
