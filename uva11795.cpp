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
const int MAXN=18;
int n;
int g[MAXN][MAXN];
int f[MAXN][1<<MAXN];
bool vis[MAXN][1<<MAXN];
int dp(int i,int s){
    if(vis[i][s]) return f[i][s];
    vis[i][s]=true;
    int &ans =f[i][s];
    if(((1<<i) & s) == 0 ) return ans=0;
    if(i==0 ) {
        if(s-1==0) return ans=1;
        else return ans= 0;
    }
    ans=0;
    int s1=s-(1<<i);
    for(int j=0;j<n;j++){
        if(s1 &( 1<<j) && g[j][i]){
        ans+=dp(j,s1);
        }
    }
    return ans;

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
//    freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int T;
    int kase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        n++;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            char tmp;
            for(int j=1;j<n;j++){
                tmp=getchar();
               // putchar(tmp);
                if(tmp=='1') g[i][j]=1;
                else if(tmp=='0') g[i][j]=0;
            }
           // printf("\n");
        }

        for(int i=0;i<n;i++){
            g[i][0]=0;
        }
        int ALL=(1<<n)-1;
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=dp(i,ALL);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
