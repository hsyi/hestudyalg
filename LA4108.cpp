#include<iostream>
#include<cstring>
using namespace std;
const int MAXL=1e5+11;
int n;
int cov[MAXL<<2];
int highest[MAXL<<2];
int  update(int L,int R,int H,int l,int r,int rt){
    int ret=0;
    if(cov[rt]>H) return 0;
    if(l>=L && r<=R){ if(H>=highest[rt]) {ret=r-l+1;cov[rt]=H;highest[rt]=H;return ret;}}
    if(l==r) {return ret;}
    int mid = (l+r)>>1;
    if(cov[rt]) {if(cov[rt]>cov[rt<<1]) {cov[rt<<1]=cov[rt];highest[rt<<1]=max(highest[rt<<1],cov[rt<<1]);}if(cov[rt]>cov[rt<<1|1]) {cov[rt<<1|1]=cov[rt];highest[rt<<1|1]=max(cov[rt],highest[rt<<1|1]);}}
    if(mid>=L) ret+=update(L,R,H,l,mid,rt<<1);
    if(mid<R) ret+=update(L,R,H,mid+1,r,rt<<1|1);
    if(highest[rt<<1]>highest[rt]) highest[rt]=highest[rt<<1];
    if(highest[rt<<1|1]>highest[rt]) highest[rt]=highest[rt<<1|1];
    return ret;
}   
int main(){
    int kas;
    cin>>kas;
    while(kas--){
        cin>>n;
        memset(cov,0,sizeof(cov));
        memset(highest,0,sizeof(highest));
        int ans=0;
        for(int building=0;building<n;building++){
            int L,R,H;
            cin>>L>>R>>H;
            int tmp=update(L,R-1,H,0,1e5,1);
            //cout<<tmp<<endl;
            ans+=tmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
            
