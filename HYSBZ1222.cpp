///////////////
//
//神奇的dp 神奇的过了
//
//////////////
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
//const int INF=0x3f3f3f3f;
const int INF=300011;
const int MAXN=6000+11;
int n;
int f[INF],a[MAXN],b[MAXN],c[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    scanf("%d",&n);
    int suma=0;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
       // suma+=max(a[i],c[i]);
        if(a[i]==0) a[i]=INF;
        if(b[i]==0) b[i]=INF;
        if(c[i]==0) c[i]=INF;
        suma+=min(a[i],min(b[i],c[i]));
    }

   // printf("DEBUG");
    memset(f,0,sizeof(f));
   // printf("DEBUG");
    for(int i=1;i<=n;i++){
        for(int j=suma;j>=0;j--){
            int tmp=INF;
            if(j>=a[i-1])
                tmp=min(tmp,f[j-a[i-1]]);
            if(j>=c[i-1])
                tmp=min(tmp,f[j-c[i-1]]+c[i-1]);
            tmp=min(f[j]+b[i-1],tmp);
            f[j]=tmp;
        }
    }
    f[0]=max(0,f[0]);
    for(int i=1;i<=suma;i++){
        f[0]=min(max(f[i],i),f[0]);
    }
    printf("%d\n",f[0]);
            

    return 0;
}
