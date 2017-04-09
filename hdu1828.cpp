#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXL=2e4+11;
const int MAXN=5e3+11;
struct Seg{
    int y1,y2,x;
    bool in;
    Seg(){}
    Seg(int y1,int y2,int x,bool in):y1(y1),y2(y2),x(x),in(in){}
    bool operator < (const Seg &a) const{ return x<a.x;}
} seg[MAXN<<1];
int len[MAXL<<2],cnt[MAXL<<2],cover[MAXL<<2];
bool lbd[MAXL<<2],rbd[MAXL<<2];
void PushUp(int l,int r,int rt){
    if(cover[rt]) {len[rt]=r-l+1;cnt[rt]=2;lbd[rt]=rbd[rt]=1;}
    else if(l==r) {len[rt]=0;cnt[rt]=0;lbd[rt]=rbd[rt]=0;}
    else{
        len[rt]=len[rt<<1]+len[rt<<1|1];
        cnt[rt]+=cnt[rt<<1]+cnt[rt<<1|1];
        lbd[rt]=lbd[rt<<1];
        rbd[rt]=rbd[rt<<1|1];
        if(rbd[rt<<1] && lbd[rt<<1|1]) cnt[rt]-=2;
    }
}
void update(int l,int r,int add,int L,int R,int rt){
    if(l<=L&&r>=R) {
        cover[rt]+=add;
        PushUp(L,R,rt);
        return;
    }
    int mid=(L+R)/2;
    if(l<=mid) update(l,r,add,L,mid,rt<<1);
    if(r>mid) update(l,r,add,mid+1,R,rt<<1|1);
    PushUp(L,R,rt);
}
int n,sz;
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        seg[sz++]=Seg(y1,y2,x1,true);
        seg[sz++]=Seg(y1,y2,x2,false);
    }
    sort(seg,seg+sz);
    int ans=0;
    int lastx=seg[0].x;
    for(int i=0;i<sz;i++){
        int tmp=len[1];
        ans+=(seg[i].x-lastx)*cnt[1];
        update(seg[i].y1,seg[i].y2-1,seg[i].in?1:-1,-10000,10000,1);
        ans+=abs(tmp-len[1]);
        lastx=seg[i].x;
    }
    cout<<ans<<endl;
    return 0;
}

