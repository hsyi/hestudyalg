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
#include <assert.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=2000;
char s[MAXN];
int sa[MAXN],t[MAXN],t2[MAXN],c[MAXN],n,*ranks;//c需要不同的rank那么大
int height[MAXN];
void build_sa(int m){
    int *x=t,*y=t2;
    for(int i=0;i<m;i++) c[i]=0;
    for(int i=0;i<n;i++) c[x[i]=s[i]]++;//x是按第一关键词给的rank
    for(int i=1;i<m;i++) c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(int i=n-k;i<n;i++) y[p++]=i;//y时按第二关键词排的序:控制第一关键字的读入顺序：因：基数排序是稳定排序
        for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
        
        for(int i=0;i<m;i++) c[i]=0;
        for(int i=0;i<n;i++) c[x[y[i]]]++;
        for(int i=1;i<m;i++) c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];

        swap(x,y);
        p=1;x[sa[0]]=0;
        for(int i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k] ? p-1:p++;
        if(p>=n) break;
        m=p;
    }
    /*
    for(int i=0;i<n;i++){
        assert(x[sa[i]]==i);//成立
        assert(x==t);//不一定成立了，因为中间swap了x与y
    }
    */
    ranks=x;
}

void calcuh(){ //h[i]=height[rank[i]];h[i]>=h[i-1]-1;
    //height[ranks[0]]=0;
    //for(int i=0;i<n;i++) assert(ranks[sa[i]]=i);
    int k=0;
    for(int i=0;i<n;i++){
        if(k) k--;
        //if(ranks[i]==0) {height[ranks[i]]=0;k=0;continue;} 不被使用的答案数组越界也不要管他.
        int j=sa[ranks[i]-1];
        while( k+i<n && s[j+k]==s[i+k]) k++;
        height[ranks[i]]=k;

    }
}
int main(){
#ifndef ONLINE_JUDGE
   // freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
   // freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    scanf("%s",s);
    n=strlen(s);
    printf("%d\n",n);
    build_sa(MAXM);
    calcuh();
    for(int i=0;i<(int)strlen(s);i++){
        printf("%d height:%d",sa[i],height[i]);
        for(int j=sa[i];j<(int)strlen(s);j++){
            printf("%c",s[j]);
        }
        putchar(10);
    }
    return 0;
}
