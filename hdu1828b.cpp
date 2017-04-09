#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int  MAXN=5e3+11;
const int MAXL=2e4+11;
int cov[MAXL<<2],len[MAXL<<2],cnt[MAXL<<2];
bool lbd[MAXL<<2],rbd[MAXL<<2];
struct Seg{
    int y1,y2,x;
    bool in;
    Seg(int y1,int y2,int x,bool in):y1(y1),y2(y2),x(x),in(in){}
    Seg(){};
    bool operator < (const Seg &b) const{return x<b.x;}
} seg[MAXN<<1];
int n,sz;
void PushUp(int l,int r,int rt){
    if(cov[rt]){
        len[rt]=r-l+1;
        cnt[rt]=2;
        lbd[rt]=true;
        rbd[rt]=true;
    }
    else if(l==r) {
        len[rt]=cnt[rt]=lbd[rt]=rbd[rt]=0;
    }
    else {
        len[rt]=len[rt<<1]+len[rt<<1|1];
        cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1];
        lbd[rt]=lbd[rt<<1];
        rbd[rt]=rbd[rt<<1|1];
        if(lbd[rt<<1|1] && rbd[rt<<1]) cnt[rt]-=2;
    }
}
void update(int L,int R,int add,int l,int r,int rt){
    if(l>=L&&r<=R){
        cov[rt]+=add;
        PushUp(l,r,rt);
        return ;
    }
    int mid=(l+r)>>1;
    if(mid>=L) update(L,R,add,l,mid,rt<<1);
    if(mid<R) update(L,R,add,mid+1,r,rt<<1|1);
    PushUp(l,r,rt);
}
int main(){
    ios_base::sync_with_stdio(false);
    while(cin>>n){
        sz=0;
        for(int i=0;i<n;i++){
            int y1,y2,x1,x2;
            cin>>x1>>y1>>x2>>y2;
            seg[sz++]=Seg(y1,y2,x1,1);
            seg[sz++]=Seg(y1,y2,x2,0);
        }
        sort(seg,seg+sz);
        int ans=0;
        int lastl=0;
        for(int i=0;i<sz;i++){
            update(seg[i].y1,seg[i].y2-1,seg[i].in?1:-1,-10000,10000,1);
            int tmp=len[1];
            ans+=abs(tmp-lastl);
            ans+=(seg[i+1].x-seg[i].x)*cnt[1];
            lastl=tmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}

            
