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
const int MAXN=101;
int n,w;
int u[MAXN];
int f[MAXN][MAXN];
bool vis[MAXN][MAXN];
int asum[MAXN];

int dp(int i,int w){
    if(vis[i][w]) return f[i][w];
    vis[i][w]=true;
   // if(i==w==0) return f[i][w]=0;
    int &ans=f[i][w];
    if(i<w) return ans=INF;
    int tans=INF;
     if(w==1) return ans=i*asum[i];
    for(int k=w-1;k<i;k++){
        tans=min(dp(k,w-1)+i*(asum[i]-asum[k]),tans);
    }
    return ans=tans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&w);
        asum[0]=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%d",&u[i]);
        }
        sort ( u,u+n,greater<int>());
        for(int i=0;i<n;i++)
            asum[i+1]=asum[i]+u[i];
        double ans=(double)dp(n,w)/(double)asum[n];
        printf("%.4lf\n",ans);

    }
    return 0;
}
