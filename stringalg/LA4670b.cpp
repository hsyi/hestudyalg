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
const int MAXN=200*71;
const int Max_Sigma=26;
const int MAXL=1000011;

int id[151];

struct AC_auto{
    int ch[MAXN][Max_Sigma];
    int val[MAXN];
    int last[MAXN];
    int f[MAXN];
    int sz;
    int cnt[MAXN];
    void init(){
        val[0]=0;
        memset(cnt,0,sizeof(cnt));
        memset(ch[0],0,sizeof(ch[0]));
        f[0]=0;
        last[0]=0;
        sz=1;

    }
    void insert(char *s,int v){
        int n=strlen(s);
        int p=0;
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            if(ch[p][c]==0){
                ch[p][c]=sz;
                memset(ch[sz],0,sizeof(ch[sz]) );
                val[sz++]=0;
            }
            p=ch[p][c];
        }
        if(val[p]){
            id[v]=val[p];
        }
        else {
            val[p]=v;
            id[v]=val[p];
        }
    }
    void afterpipei(int i){
        cnt[val[i]]++;
        if(last[i]) afterpipei(last[i]);
    }
    void query(char *s){
        int n=strlen(s);
        int j=0;
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            //while(j && !ch[j][c]) j=f[j];
            j=ch[j][c];
            if(val[j]) afterpipei(j);
            else if(last[j]) afterpipei(last[j]);
        }
    }

    void bfs_getf(){
        queue<int> mq;
        f[0]=0;
        for(int i=0;i<Max_Sigma;i++){
            if(ch[0][i] == 0 ) continue;
            f[ch[0][i]]=last[ch[0][i]]=0;
            mq.push(ch[0][i]);
        }
        while(!mq.empty()){
            int p=mq.front();
            mq.pop();
            for(int i=0;i<Max_Sigma;i++){
                if(!ch[p][i]){
                    ch[p][i]=ch[f[p]][i];
                    continue;
                }
                int v=ch[p][i];
                mq.push(v);
                int  u=f[p]; //注意循环啊！！！
                //while(u && !ch[u][i]) u=f[u];
                if(ch[u][i]){
                    f[v]=ch[u][i];
                    if(val [ch[u][i]] ) last[v]=ch[u][i];
                    else last[v]=last[ch[u][v]];
                }
                else {
                    f[v]=0;
                    last[v]=0;
                }
            }
        }
    }

    void debug (int rt){
        printf("%d %d %d\n" ,rt , f[rt],last[rt]);
        for(int i=0;i<Max_Sigma;i++){
            if(ch[rt][i]) debug(ch[rt][i]);
        }
    }
} ac_a;
char ps[151][73];
char text[MAXL];
int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Documents/algorithmsleran/mycodes/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Documents/algorithmsleran/mycodes/out.txt","w",stdout);
#endif
    int n;
    while(~scanf("%d",&n) && n){
        ac_a.init();
        for(int i=0;i<n;i++){
            scanf("%s",ps[i]);
            ac_a.insert(ps[i],i+1);
        }
        ac_a.bfs_getf();
        scanf("%s",text);
        ac_a.query(text);
        int maxcnt=0;
        for(int i=1;i<=n;i++){
            maxcnt=max(ac_a.cnt[i],maxcnt);
        }
        printf("%d\n",maxcnt);
        for(int i=0;i<n;i++){
                if(ac_a.cnt[i+1]==maxcnt) 
                printf("%s\n",ps[i]);
        }


    }
    return 0;
}
