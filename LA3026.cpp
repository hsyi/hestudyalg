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
const int MAXN=1000000+11;
char s[MAXN];
int f[MAXN];
void getfail(){
    f[0]=0;
    f[1]=0;
    int n=strlen(s);
    for(int i=2;i<=n;i++){
        int j=f[i-1];
        while(j && s[i-1]!=s[j]) j=f[j];
        if(s[i-1]==s[j]) j++;
        else j=0;
        f[i]=j;
        if(f[i]>0 && i%(i-f[i])==0 )
            printf("%d %d\n",i,i/(i-f[i]));
    }
   // for(int i=0;i<=n;i++) printf("%d ",f[i]);
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int n;
    int kas=0;
    while(~scanf("%d",&n) && n){
        scanf("%s",s);
        printf("Test case #%d\n",++kas);
        getfail();
        printf("\n");
    }

    return 0;
}
