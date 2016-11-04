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
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define REP(i, n) for (int i=0;i<n;++i)
#define clr(x,a) memset(x,a,sizeof(x))
#define RD(x) scanf("%d",&x)
#define mmin(a,b,c) min(a,min(b,c))
#define fi first
#define se second
typedef long long ll;
const int INF=0x3f3f3f3f;
int a[3];
int ans[2];
int mmax;
int n;
map<pair<int,int>,pair<int,int> > mmap;
/*inline int mmin(int a,int b,int c){
    return min(a,min(b,c));
}*/
int main(){
#ifndef ONLINE_JUDGE
   // freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    RD(n);
    ans[0]=-1;
    ans[1]=-1;
    mmax=-INF;
    REP(i,n){
        RD(a[0]);RD(a[1]);RD(a[2]);
        sort(a,a+3);
        if(a[0]>mmax) {ans[0]=i;ans[1]=-1;mmax=a[0];}
        if(mmap[mp(a[1],a[2])].first){
            int t=min(a[0]+mmap[mp(a[1],a[2])].first,a[1]);
            if(t>mmax) {ans[0]=mmap[mp(a[1],a[2])].se;ans[1]=i;mmax=t;}
        }
        if(mmap[mp(a[0],a[1])].fi<a[2]) 
            mmap[mp(a[0],a[1])]=mp(a[2],i);
        if(mmap[mp(a[0],a[2])].fi<a[1]) 
            mmap[mp(a[0],a[2])]=mp(a[1],i);
        if(mmap[mp(a[1],a[2])].fi<a[0]) 
            mmap[mp(a[1],a[2])]=mp(a[0],i);
    }
    if(ans[1]==-1){
        printf("1\n%d",ans[0]+1);
    }
    else printf("2\n%d %d",ans[0]+1,ans[1]+1);
            



    return 0;
}
