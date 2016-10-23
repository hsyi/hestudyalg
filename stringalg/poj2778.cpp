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
typedef long long ull;
const int INF=0x3f3f3f3f;
const int MAXN=111;
const int MAXW=4;
const ull  MOD=100000;
int msz;
struct MAT{
    ull  m[MAXN][MAXN];
};
struct AC_auto{
    int ch[MAXN][MAXW];
    int val[MAXN];
    int fail[MAXN];
    int sz;
    void init(){
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
        val[0]=fail[0]=0;
    }
 inline   int idx(char a){
        if(a=='A') return 0;
        if(a=='C') return 1;
        if(a=='T') return 2;
        if(a=='G') return 3;
        else return INF;
    }
    void insert(char *s){
        int p=0;
        int n=strlen(s);
        for(int i=0;i<n;i++){
            int c=idx(s[i]);
            if(c==INF) return;
            if(!ch[p][c]){
                ch[p][c]=sz;
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz++]=0;
            }
            p=ch[p][c];
        }
        val[p]=1;
    }
    void bfs_getf(){
        queue<int> q;
        int u=0;
        fail[u]=0;
        for(int i=0;i<MAXW;i++){
            if(!ch[0][i]) {
                continue;
            }
            else {
                fail[ch[0][i]]=0;
                q.push(ch[0][i]);
            }
        }
        while(!q.empty()){
            u=q.front();
            q.pop();
           // if(val[fail[u]]) val[u]=1;
            for(int i=0;i<MAXW;i++){
                if(!ch[u][i]) {ch[u][i]=ch[fail[u]][i];continue;}
                q.push(ch[u][i]);
                //printf("qpush******%d %d %d\n",ch[u][i],u,i);
                int v=ch[u][i];
                fail[v]=ch[fail[u]][i];
                if(!val[v]) val[v]=val[ch[fail[u]][i]];
            }
        }
    }
    MAT m;   
    void getmat(){//把危险行列删掉，减小矩阵运算规模，速度更快。
        memset(m.m,0,sizeof(m.m));
        int col=0;
        int mymap[sz];
        for(int i=0;i<sz;i++){
            if(val[i]) continue;
            mymap[i]=col++;
        }
        msz=col;
        for(int i=0;i<sz;i++){
            if(val[i]) continue;
            for(int j=0;j<MAXW;j++){
                int u=ch[i][j];
                if(val[u]) continue;
                //printf("-----%d %d-----\n",mymap[i],mymap[u]);
                m.m[mymap[i]][mymap[u]]++;
            }
        }        
    }/*
    void getmat(){ //危险的路径置0，运算规模较上面较大。
        memset(m.m,0,sizeof(m.m));
        msz=sz;
        for(int i=0;i<sz;i++){
            if(val[i]) continue;
            for(int j=0;j<MAXW;j++){
                if(!val[ch[i][j]]) m.m[i][ch[i][j]]++;
            }
        }
    }*/
    void dispmat(){
        //printf("show mat:\n");
        printf("%d\n",msz);
        for(int i=0;i<msz;i++){
            for(int j=0;j<msz;j++){
                printf("%lld ",m.m[i][j]);
            }
            printf("\n");
        }
        //int nsz;
        //for(int i=0;i<msz;i++)
    }
    void disptree(int rt){
        printf("%d %d\n",rt,fail[rt]);
        for(int i=0;i<MAXW;i++){
            if(ch[rt][i]>rt) disptree(ch[rt][i]);
        }
    }
} ac;

MAT operator * (MAT& a,MAT& b){
    MAT c;
   // printf("bug3report\n");
    for(int i=0 ;i<msz;i++){
        for(int j=0;j<msz;j++){
            c.m[i][j]=0;
          for(int k=0;k<msz;k++){
              c.m[i][j]=c.m[i][j]+a.m[i][k]*b.m[k][j];
          }
             c.m[i][j]=c.m[i][j]%MOD;
        }
    }
    return c;
}

MAT operator ^ (MAT &a,int b){
 //   printf("bug2report\n");
    MAT ans;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=0;i<msz;i++) ans.m[i][i]=1;
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b=b>>1;
    }
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
  // freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif

    int m,n;
    char p[20];
    while(~scanf("%d%d",&m,&n)){
        ac.init();
        for(int i=0;i<m;i++){
            scanf("%s",p);
          //  puts(p);
            ac.insert(p);
        //    ac.disptree(0);
        }
        ac.bfs_getf();
        //ac.disptree(0);
        ac.getmat();
      // ac.disptree(0);
        //ac.dispmat();
        MAT ansmat=ac.m^n;
        ull ans=0;
        for(int i=0;i<msz;i++){
            ans=(ans+ansmat.m[0][i])%MOD;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
