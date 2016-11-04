#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int INF=0x3f3f3f3f;
#define lson l,m,rt<<1
#define rson m+1,r,(rt<<1)+1

const int MAXN=100011;

struct Segtree{
    int sums[MAXN<<2],mins[MAXN<<2],maxs[MAXN<<2];
    int adds[MAXN<<2],sets[MAXN<<2];
    
    void pushdown(int l,int r,int rt){
        if(sets[rt]) {
            sets[rt<<1] = sets[(rt<<1)+1]=sets[rt];
            sets[rt]=0;
            adds[rt<<1]=adds[(rt<<1)+1]=0;
            int lr,rr;
            lr=rt<<1;
            rr=lr+1;
            int m=(l+r)>>1;
            sums[lr] = sets[lr] *(m-l+1);
            sums[rr] = sets[rr] * (r-m);
            mins[lr] =maxs[lr]=mins[rr]=maxs[rr]= sets[lr];
            
        }
        if(adds[rt]){
            adds[rt<<1] +=adds[rt];
            adds[(rt<<1)+1] += adds[rt];
            int lr,rr;
            lr=rt<<1;
            rr=lr+1;
            int m=(l+r)>>1;
            sums[lr] += adds[rt] *(m-l+1);
            sums[rr] += adds[rt] * (r-m);
            mins[lr] +=adds[rt];
            maxs[lr]+=adds[rt];
            mins[rr]+=adds[rt];
            maxs[rr]+=adds[rt];
            adds[rt] =0;
        }
    }
    
    void maintain(int l,int r,int rt){
       
        if(sets[rt]) {
            sums[rt]=sets[rt]*(r-l+1);
            maxs[rt]=mins[rt]=sets[rt];
        }
        else if(l<r){
            int rr=(rt<<1)+1;
            int lr=rt<<1;
            sums[rt]=sums[rr]+sums[lr];
            mins[rt]=min(mins[rr],mins[lr]);
            maxs[rt]=max(maxs[rr],maxs[lr]);
        }
        else {
            sums[rt]=0;
            mins[rt]=0;
            maxs[rt]=0;
        }
        sums[rt]+=adds[rt]*(r-l+1);
        mins[rt]+=adds[rt];
        maxs[rt]+=adds[rt];
    }
    
    
    
    void update(int num,int op,int L,int R,int l,int r,int rt){//
        if(l>=L && r<=R){
            if(op==1) adds[rt]+=num;
            else {
                sets[rt]=num;
                adds[rt]=0;
            }
            maintain(l,r,rt);
            return;
        }
        int m=(r+l)>>1;
        pushdown(l,r,rt);
        if(m>=L) update(num,op,L,R,lson);
        if(m<R) update(num,op,L,R,rson);
        maintain(l,r,rt);
        
    }
    
    void query(int L,int R,int l, int r, int rt, int &rsum,int &rmin,int &rmax){
        if(l>=L && r<=R) {
            rmax=maxs[rt];
            rmin=mins[rt];
            rsum=sums[rt];
            return;
        }
        pushdown(l,r,rt);
        int m=(l+r)>>1;
        int lmx=-INF,rmx=-INF;
        int lmn=INF,rmn=INF;
        int lsm=0,rsm=0;
        if(L<=m) query(L,R,lson,lsm,lmn,lmx);
        if(m<R) query(L,R,rson,rsm,rmn,rmx);
        rsum=lsm+rsm;
        rmax=max(lmx,rmx);
        rmin=min(lmn,rmn);
        
        
    }
} mytree[23];

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
      freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int r,c,m;
    while(~scanf("%d%d%d",&r,&c,&m)){
       // printf("T:\n");
        memset(mytree,0,sizeof(mytree));
        for(int i=0;i<m;i++){
            int op,x1,y1,x2,y2;
            scanf("%d%d%d%d%d",&op,&x1,&y1,&x2,&y2);
            if(op==3){
                int asum=0,amin=INF,amax=-INF;
                //printf("O3\n");
                for(int rows=x1;rows<=x2;rows++){
                    int tsum,tmin,tmax;
                    mytree[rows].query(y1,y2,1,c,1,tsum,tmin,tmax);
                    asum+=tsum;
                    amin=min(amin,tmin);
                    amax=max(amax,tmax);
                }
                printf("%d %d %d\n",asum,amin,amax);
            }
            else{
               // printf("O12\n");
                int v;
                scanf("%d",&v);
                for(int rows=x1;rows<=x2;rows++)
                    mytree[rows].update(v,op,y1,y2,1,c,1);
            }
        }
    }
    return 0;
}
/*
4 4 8
1 1 2 4 4 5
3 2 1 4 4
1 1 1 3 4 2
3 1 2 4 4
3 1 1 3 4
2 2 1 4 4 2
3 1 2 4 4
1 1 1 4 3 3
 */