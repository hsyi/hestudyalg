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
const int MAXN=100011;
int ab[MAXN];
int main(){
#ifndef ONLINE_JUDGE
    //freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    int l,r;
    int msum=0,mid=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l,&r);
        ab[i]=l-r;
        msum+=ab[i];
    }
    ans=abs(msum);
    for(int i=1;i<=n;i++){
        if(abs(msum-ab[i]-ab[i])>ans) {
		mid=i;
		ans=abs(msum-ab[i]-ab[i]);
	}
    }
    printf("%d",mid);
}