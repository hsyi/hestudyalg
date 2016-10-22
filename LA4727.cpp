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
const int MAXN=500011;
int f[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    //freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int n;int k;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        f[0]=0;
        printf("bug1\n");
        for(int i=1;i<=n;i++)
            f[i]=(f[i-1]+k)%(n-i);
        printf("bug\n");
        for(int i=n;i>=n-2;i--){
            printf("%d ",f[i]);
        }
        printf("\n");
    }
    return 0;
}
