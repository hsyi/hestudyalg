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
const int MAXT='z'-'a'+1;
int f[MAXN][MAXT];
int x[MAXN];
char str[MAXN];
int n;
int myk;
int dp(int i,int j){
    if(f[i][j]<INF) return f[i][j];
    int &ans=f[i][j];
    bool flag=false;
    for(int ii=i*myk;ii<i*myk+myk;ii++){
        if(str[ii]-'a'==j) flag=true;
    }
    if(!flag) return ans=INF;
    if(i==0) return ans=x[i];
    for(int k=0;k<MAXT;k++){
        int myx=x[i];
        if(j!=k){
            for(int ii=i*myk;ii<i*myk+myk;ii++){
                if(str[ii]-'a'==k) {
                    myx--;
                    break;
                }
            }
        }
        else {
            for(int ii=i*myk;ii<i*myk+myk;ii++){
                if(str[ii]-'a'!=k) {
                    goto RESULT;
                }
            }
            myx--;
        }
RESULT:
        ans=min(dp(i-1,k)+myx,ans);
    }
    return ans;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%s",&myk,str);
        for(int i=0;i<MAXN;i++)
            fill(f[i],f[i]+MAXT,INF);
        int l=strlen(str);
        for(int i=0;i<l/myk;i++){
            set<int> myset;
            for(int j=i*myk;j<i*myk+myk;j++){
                myset.insert(str[j]-'a');
                //printf("%c",str[j]);
            }
            x[i]=myset.size();
            //printf("bug %d",x[i]);
        }
        int ans=INF;
        for(int i=0;i<MAXT;i++){
            ans=min(ans,dp(l/myk-1,i));
        }
        printf("%d\n",ans);
    }
    return 0;
}
