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
const int MAXN=400011;
char s[MAXN];
int f[MAXN];//f[i] 是s[0..i-1]的次长相同前后缀长度。
int ans[MAXN];
int n;
inline void getfail(){
    f[0]=0;
    f[1]=0;
    n=strlen(s);
    int j=f[0];
    for(int i=2;i<=n;i++){
        while(j && s[j]!=s[i-1]) j=f[j];//因为这里是匹配 匹配用到的是s[0..i-1]
        f[i]=s[j]==s[i-1]?++j:0;
    }
    //for(int i=0;i<=n+1;i++)
      //  printf("%d ",f[i]);
   // printf("\n");
}
int cnt;
inline void disans(){
    cnt=1;
    ans[0]=n;
    while(f[ans[cnt-1]]){
        ans[cnt]=f[ans[cnt-1]];
        cnt++;
    }
    for(int i=cnt-1; i>=0;i--){
        printf("%d",ans[i]);
        if(i!=0) printf(" ");
    }
   // printf("%d",cnt);
}
/*
void disans(int l){
    if(f[l]) disans(f[l]-1);
    printf("%d ",l+1);
}
*/
int main(){
#ifndef ONLINE_JUDGE
    //freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    while(~scanf("%s",s)){
        getfail();
        disans();
        printf("\n");
    }
    return 0;
}
