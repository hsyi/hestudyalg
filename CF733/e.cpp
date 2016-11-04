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
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAXN=1000011;

ll sumu[MAXN],sumd[MAXN];
int pu,pd;
int n;
char s[MAXN];
int ucnt[MAXN],dcnt[MAXN];
ll ans[MAXN];
int main(){
#ifndef ONLINE_JUDGE
    //freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    RD(n);
    scanf("%s",s);
    pu=pd=1;
    sumu[0]=sumd[0]=ucnt[0]=dcnt[0]=0;
    REP(i,n){
        if(s[i]=='U'){
            sumu[pu]=sumu[pu-1]+i+1;
            pu++;
            ucnt[i+1]=ucnt[i]+1;
            dcnt[i+1]=dcnt[i];
        }
        else if(s[i]=='D'){
            sumd[pd]=sumd[pd-1]+i+1;
            pd++;
            ucnt[i+1]=ucnt[i];
            dcnt[i+1]=dcnt[i]+1;
        }
    }
    rep(i,n){
        if(s[i-1]=='U'){
            ll  rd=pd-1-dcnt[i];ll lu=ucnt[i]-1;//这里也要用ll因为rd会和i相乘会超int,10**10就超int了;
            if(lu>=rd){
                ans[i]=2*(-rd*i+sumd[pd-1]-sumd[dcnt[i]]);
                ans[i]+=2*((rd)*i-sumu[ucnt[i]-1]+sumu[ucnt[i]-1-rd]);
                ans[i]+=n-i+1;
            }
            else {
                ans[i]=2*(lu*i-sumu[ucnt[i]-1]);
                ans[i]+=2*(-(lu+1)*i+sumd[dcnt[i]+lu+1]-sumd[dcnt[i]]);
                ans[i]+=i;
            }
        }
        else{
            ll rd=pd-1-dcnt[i];ll lu=ucnt[i];
            if(rd>=lu){
                ans[i]=2*(lu*i-sumu[ucnt[i]]);
                ans[i]+=2*(-lu*i+sumd[dcnt[i]+lu]-sumd[dcnt[i]]);
                ans[i]+=i;
            }
            else{
                ans[i]=2*(-rd*i+sumd[pd-1]-sumd[dcnt[i]]);
                ans[i]+=2*((rd+1)*i-sumu[ucnt[i]]+sumu[ucnt[i]-rd-1]);
                ans[i]+=n-i+1;
            }
        }
    }

    rep(i,n){
        printf("%I64d ",ans[i]);

    }


    

    return 0;
}
