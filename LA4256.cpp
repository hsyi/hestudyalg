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
const int MAXA=203;
int f[MAXA][MAXN];
int A[MAXA];
int n1,n2,n3;
vector<int> node[MAXN];

int dp(int i,int j){
    if(f[i][j]!=-1) return f[i][j];
    int &ans=f[i][j];
    ans=INF;
    int rear=(A[i]==j?0:1);
    if(i==0)return ans=rear;
    for(int k=0;k<node[i].size();k++){
        ans=min(dp(i-1,node[i][k]),ans);
    }
    return ans=ans+rear;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        memset(f,-1,sizeof(f));
        scanf("%d%d",&n1,&n2);
        for(int i=0;i<n1;i++){
            node[i].clear();
            node[i].push_back(i);
        }
        for(int i=0;i<n2;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            node[a].push_back(b);
            node[b].push_back(a);
        }
        scanf("%d",&n3);
        for(int i=0;i<n3;i++){
            scanf("%d",&A[i]);
            A[i]--;
        }
        int ans=INF;
        for(int i=0;i<n1;i++){
            ans=min(ans,dp(n3-1,i)+(i==A[n3-1]?0:1));
        }
        printf("%d\n",ans);
    }
    return 0;
}
