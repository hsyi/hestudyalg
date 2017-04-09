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
const int MAXN=200000+11;
char s[MAXN];
bool xiao=false;
bool da=false;
bool hx[MAXN];
bool hd[MAXN];
int n,m;
int main(){
#ifndef ONLINE_JUDGE
    //freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    scanf("%d",&n);
    scanf("%s",s);
    int cnt=0;
    REP(i,n){ if(s[i]=='>') da=true; hd[i]=da;}
    for(int i=n-1;i>=0;i--) {if(s[i]=='<') xiao=true;hx[i]=xiao;}
    REP(i,n){if(s[i]=='>'&& !hx[i]) cnt++;else if(s[i]=='<' && !hd[i]) cnt++;}
    printf("%d\n",cnt);

    return 0;
}
