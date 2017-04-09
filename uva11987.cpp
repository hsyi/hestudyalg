#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2e5+11;
int pa[MAXN],sz[MAXN],sum[MAXN];
int n,m;
int Find(int x){
    return pa[x]==x?x:pa[x]=Find(pa[x]);
}
void Union(int x,int y){
    int rtx=Find(x),rty=Find(y);
    if(rtx==rty) return;
    if(rand()&1) pa[rtx]=rty,sz[rty]+=sz[rtx],sum[rty]+=sum[rtx];
    else pa[rty]=rtx,sz[rtx]+=sz[rty],sum[rtx]+=sum[rty];
}
void Move(int x,int y){
    int rtx=Find(x),rty=Find(y);
    if(rtx==rty) return;
    sz[rtx]--,sum[rtx]-=x,sz[rty]++,sum[rty]+=x,pa[x]=rty;
}
int main(){
    while(cin>>n>>m){
        for(int i=1;i<=n;i++) {pa[i]=i+n;sz[i+n]=1;sum[i+n]=i;}
        for(int i=n+1;i<=n+n;i++) pa[i]=i;
        for(int Query=0;Query<m;Query++){
            int type;
            cin>>type;
            int p,q;
            if(type==3){
                cin>>p;
                cout<<sz[Find(p)]<<" "<<sum[Find(p)]<<endl;
            }
            else{
                cin>>p>>q;
                if(type==1){
                    Union(p,q);
                }
                else {
                    Move(p,q);
                }
            }
        }
    }
    return 0;
}
                
