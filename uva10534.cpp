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
const int MAXN=10011;
int dp1[MAXN],dp2[MAXN];
int A1[MAXN],A2[MAXN];
int s[MAXN];
int n;

void gao(){
    for(int i=0;i<n;i++){
        int k=lower_bound(A1+1,A1+n+1,s[i])-A1;
        A1[k]=s[i];
        dp1[i]=k;
        int k2=lower_bound(A2+1,A2+n+1,s[n-i-1])-A2;
        A2[k2]=s[n-i-1];
        dp2[n-i-1]=k2;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,2*min(dp1[i],dp2[i])-1);
    }
    printf("%d\n",ans);
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            scanf("%d",&s[i]);
        fill(A1,A1+n+1,INF);
        fill(A2,A2+n+1,INF);
        gao();
    }

    return 0;
}
