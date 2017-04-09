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
const int dir[8][2]={{0,1},{0,-1},{1,1},{1-1},{-1,-1},{-1,1},{1,0},{-1,0}};
const int INF=0x3f3f3f3f;
char ans[2][14];
char path[28];
int myhash[26];
int rep;
int l1,l2,l3;
int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    scanf("%s",path);
    rep=-1;
    REP(i,27){
        if(~rep) l1++;
        else l3++;
        if(myhash[path[i]-'A']) {rep=i;l2=l1-myhash[path[i]-'A'];l1=myhash[path[i]-'A']+1;}
        else myhash[path[i]-'A']=i;
    }
    return 0;
}
