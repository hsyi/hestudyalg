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
const int MAXN=54;
const int MAXW=26;

typedef  unsigned long long ull;

struct MAT{
    ull m[MAXN][MAXN];
    static int sz;
};
int MAT::sz =0 ;

MAT operator * (MAT &a,MAT &b){
    MAT c;
    memset(c.m,0,sizeof(c.m));
    for(int i=0;i<a.sz;i++){
        for(int j=0;j<a.sz;j++){
            for(int k=0;k<a.sz;k++){
                c.m[i][j]+=a.m[i][k]*b.m[k][j];
            }
        }
    }
    return c;
}
ull quike(ull l){
    ull ans=1;
    ull tmp=26;
    while(l){
        if(l&1) ans=ans*tmp;
        tmp=tmp*tmp;
        l>>=1;
    }
    return ans;
}

ull sumall(int l){
    if(l==1) return 26;
    ull sn_2=sumall(l/2);
    if((l&1)==0){
        return sn_2*quike(l/2)+sn_2;
    }
    else {
        return sn_2*quike(l/2)+quike(l)+sn_2;
    }
}



    
MAT operator ^ (MAT const &a,ull b){
    MAT ans;
    MAT tmp=a;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=0;i<ans.sz;i++){
        ans.m[i][i]=1;
    }
    while(b){
        if(b&1) ans=ans*tmp;
        tmp=tmp*tmp;
        b>>=1;
    }
    return ans;
}
MAT operator + (MAT const  &a,MAT const  &b){
    MAT ans;
    for(int i=0;i<ans.sz;i++){
        for(int j=0;j<ans.sz;j++){
            ans.m[i][j]=a.m[i][j]+b.m[i][j];
        }
    }
    return ans;
}

/*
MAT thisum( MAT const &a,ull b){ //二分求等比矩阵的和
    if(b==1) return a;
    MAT ans;
    MAT tmp;
    ull tmpull;
    MAT sn_2=thisum(a,b/2);
    if(b%2==0){

        tmpull=b/2;
        tmp=a^tmpull;
        tmp=sn_2*tmp;
        ans=tmp+sn_2;
    }
    else {
        tmpull=b/2;
        tmp=a^tmpull;
        tmp=sn_2*tmp;
        ans=tmp+sn_2;
        tmp=a^b;
        ans=ans+tmp;
        //ans=(ans*(a^(b/2)))+ans+(a^b);
    }
    return ans;
}*/

MAT thisum(MAT const  &a,ull b){// 构造法求等比矩阵n项和 速度比二分快4倍
    if(b==1) return a;
    int nsz=a.sz*2;
    MAT c;
    for(int i=0;i<nsz;i++){
        for(int j=0;j<nsz;j++){
            if(i<a.sz && j<a.sz) c.m[i][j]=a.m[i][j];
            else if(j>=a.sz && ((j-a.sz==i) || (j-a.sz==i-a.sz))) c.m[i][j]=1;
            else {
                c.m[i][j]=0;
            }
          //  printf("%llu ",c.m[i][j]);
        }
        //printf("\n");
    }
    b=b+1;
    a.sz=nsz;
    c=c^b;
    MAT ans;
    a.sz=nsz/2;
    for(int i=0;i<a.sz;i++)
        for(int j=0;j<a.sz;j++){
            ans.m[i][j]=c.m[i][j+a.sz];
            if(i==j) ans.m[i][j]--;
        }
    return ans;
}

struct AC_M{
    int ch[MAXN][MAXW];
    int val[MAXN];
    int fail[MAXN];
    int sz;
    void init(){
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
        val[0]=fail[0]=0;
    }
    inline int idx(char a){
        return a-'a';
    }
    void insert( char *s){
        int n=strlen(s);
        int p=0;
        for(int i=0;i<n;i++){
            int c=idx(s[i]);
            if(!ch[p][c]){
                ch[p][c]=sz;
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz++]=0;
            }
            p=ch[p][c];
        }
        val[p]=1;
    }
    void bfs_gf(){
        queue<int> q;
        int u=0;
        fail[u]=0;
        for(int i=0;i<MAXW;i++){
            if(!ch[0][i]) continue;
            fail[ch[0][i]]=0;
            q.push(ch[0][i]);
        }
        while(!q.empty()){
            u=q.front();
            q.pop();
            for(int i=0;i<MAXW;i++){
                if(!ch[u][i]) {
                    ch[u][i]=ch[fail[u]][i];
                    continue;
                }
                int v=ch[u][i];
                q.push(v);
                fail[v]=ch[fail[u]][i];
                val[v]=(val[v] || val[fail[v]]);
            }
        }
    }
    MAT m;
    void disptree(int rt){
        printf("-----%d %d %d------\n",rt,fail[rt],val[rt]);
        for(int i=0;i<MAXW;i++){
            if(ch[rt][i]<=rt) continue;
            disptree(ch[rt][i]);
        }
    }
    void getmat(){
        MAT::sz=sz;
        memset(m.m,0,sizeof(m.m));
        for(int i=0;i<m.sz;i++){
            if(val[i]) continue;
            for(int j=0;j<MAXW;j++){
                if(val[ch[i][j]]) continue;
                m.m[i][ch[i][j]]++;
            }
        }
    }
    void dispmat(){
        for(int i=0;i<m.sz;i++){
            for(int j=0;j<m.sz;j++){
                printf("%llu ",m.m[i][j]);
            }
            printf("\n");
        }
    }
} ac;
                
int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
   // freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    int  n;
    ull l;
    char p[9];
    while(~scanf("%d%llu",&n,&l)){
        ac.init();
       // printf("n:%d l:%llu\n",n,l);
        for(int i=0;i<n;i++){
            scanf("%s",p);
        //   puts(p);
            ac.insert(p);
        }
       // printf("sz:%d\n",ac.sz);
        ac.bfs_gf();
        ac.getmat();
        //ac.dispmat();
        //ac.disptree(0);
        MAT ansmat;
        ansmat=thisum(ac.m,l);
        ull ans=sumall(l);
       /* for(int i=0;i<ansmat.sz;i++){
            for(int j=0;j<ansmat.sz;j++){
                printf("%llu ",ansmat.m[i][j]);
            }
            printf("\n");
        }*/
        for(int i=0;i<ansmat.sz;i++){
            ans-=ansmat.m[0][i];
        }
        printf("%llu\n",ans);
    }

    return 0;
}
