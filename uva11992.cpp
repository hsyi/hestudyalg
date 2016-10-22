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

    void pushdown(int rt){
        if(sets[rt]) {
            sets[rt<<1] = sets[(rt<<1)+1]=sets[rt];
            sets[rt]=0;
            adds[rt<<1]=adds[(rt<<1)+1]=0;
        }
        if(adds[rt]){
            adds[rt<<1] +=adds[rt];
            adds[(rt<<1)+1] += adds[rt];
            adds[rt]=0;
        }
    }

    void maintain(int l,int r,int rt){
        if(sets[rt]) {
            sums[rt]=sets[rt]*(r-l+1)+adds[rt]*(r-l+1);
            maxs[rt]=mins[rt]=sets[rt]+adds[rt];
        }
        if(l<r){
            int m=(l+r)>>1;
            int rr=(rt<<1)+1;
            int lr=rt<<1;
            sums[rt]=sums[rr]+sums[lr];
            mins[rt]=min(mins[rr],mins[lr]);
            maxs[rt]=max(maxs[rr],maxs[lr]);
        }
        sums[rt]+=adds[rt]*(r-l+1);
        mins[rt]+=adds[rt];
        maxs[rt]+=adds[rt];
    }
        


    void update(int num,int op,int L,int R,int l,int r,int rt){
        if(l>=L && r<=R){
            if(op==1) adds[rt]+=num;
            else {
                sets[rt]=num;
                adds[rt]=0;
            }
            return;
        }
        int m=(r+l)>>1;
        pushdown(rt);
        if(m>=L) update(num,op,L,m,lson);
        else maintain(lson);
        if(m<R) update(num,op,m+1,R,rson);
        else maintain(rson);
        maintain(l,r,rt);

    }

    void query(int L,int R,int l, int r, int rt, int &rsum,int &rmin,int &rmax){
        if(l>=L && r<=R) {
                rmax=max(rmax,maxs[rt]);
                rmin=min(rmin,mins[rt]);
                rsum+=sums[rt];
         }
        
        pushdown(rt);
        int m=(l+r)>>1;
        if(l<=m) query(L,m,lson,rsum,rmin,rmax);
        else maintain(lson);
        if(m<R) query(m+1,R,rson,rsum,rmin,rmax);
        else maintain(rson);
        maintain(l,r,rt);
    }
} mytree[20];

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
 //   freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int r,c,m;
    while(~scanf("%d%d%d",&r,&c,&m)){
        printf("T:\n");
        memset(mytree,0,sizeof(mytree));
        for(int i=0;i<m;i++){
            int op,x1,y1,x2,y2;
            scanf("%d%d%d%d%d",&op,&x1,&y1,&x2,&y2);
            if(op==3){
                int asum=0,amin=INF,amax=-INF;
                printf("O3\n");
                for(int rows=x1;rows<=x2;rows++)
                    mytree[rows].query(y1,y2,1,c,1,asum,amin,amax);
                printf("%d %d %d\n",asum,amin,amax);
            }
            else{
                printf("O12\n");
                int v;
                scanf("%d",&v);
                for(int rows=x1;rows<=x2;rows++)
                   mytree[rows].update(v,op,y1,y2,1,c,1);
            }        
        }
    }
    return 0;
}
