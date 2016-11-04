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
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAXN=100+11;
char s[MAXN];
char sp[]={'A','E','I','O','U','Y'};


int main(){
#ifndef ONLINE_JUDGE
    //freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    scanf("%s",s);
    int n=strlen(s);
    int p=-1;
    int ans=0;
    REP(i,n){
        REP(j,6){
            if(s[i]==sp[j]){
                ans=max(ans,i-p);
                p=i;
                break;
            }
        }
    }
    ans=max(ans,n-p);
    printf("%d",ans);

    return 0;
}
