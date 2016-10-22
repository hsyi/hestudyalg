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
const int MAXN=1011;
char s[MAXN];
int dp[MAXN][MAXN];

int getdp(int i,int j){
    if(dp[i][j]!=-1)return dp[i][j];
    int &ans = dp[i][j];
    int l=i;int r=j;
    while(l<=j){
        if(s[i]!=s[j])
            goto PARTI;
    }
    return ans=1;
PARTI:
    for(int k=i;k<j;k++){
        ans=min(getdp(i,k),getdp(k+1,j))+1;
    }
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        printf("%d",T);
        char a=getchar();
        while(a=='\n') a=getchar();
        scanf("%s",s);
        printf("%d %s",T,s);
        memset(dp,-1,sizeof(dp));
        printf("bug1");
        int n=strlen(s)-1;
        printf("bug2 %d",n );
        printf("%d\n",getdp(0,n));
    }

    return 0;
}
