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
const int MAXN=4000 * 1000+11;
struct {
   int head[MAXN];
   int next[MAXN];
   char ch[MAXN];
   int tot[MAXN];
   long long cnt; 
   int  sz;
   long long  sm;
    void init(){
        sz=1;head[0]=next[0]=0;cnt=0;sm=0;tot[0]=0;
    }
    void display(int rt){
        printf("%c %d\n",ch[rt]+'z',tot[rt]);
        for(int son=head[rt];son;son=next[rt]){
         //   printf("bug");
            display(son);
        }
    }
    void insert(char *s){
        int v=0;int u=0;int n=strlen(s);
        cnt+=tot[0];
        tot[0]++;
        for(int i=0;i<=n;i++){
            bool found=false;

            for(v=head[u];v!=0;v=next[v]){
                if(ch[v]==s[i]){
                    found=true;
                    break;
                }
            }
            if(!found){
                v=sz++;
                ch[v]=s[i];
                head[v]=0;
                tot[v]=0;
                next[v]=head[u];
                head[u]=v;
            }
         //   printf("tfb: %d\n", v);
            cnt+=2*tot[v];
           // if(tot[v] && found) printf("bug %c\n" ,ch[v]);
            if(ch[v]=='\0') {
                sm+=tot[v];
            }
            tot[v]++;
            u=v;
        }
    }
    
} Trie;

int main(){
#ifndef ONLINE_JUDGE
 //   freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
   // freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int n;
    int Kas=1;
    while(~scanf("%d",&n) && n ) {
        Trie.init();
        for(int i=0;i<n;i++){
            char stmp[1011];
            scanf("%s",stmp);
            Trie.insert(stmp);
        }
        long long  ans=Trie.cnt-Trie.sm;
        printf("Case %d: %lld\n",Kas++,ans);
        //Trie.display(0);
        //puts(Trie.ch+1);
    }
    return 0;
}
