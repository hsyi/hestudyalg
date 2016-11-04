#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i=0;i<n;++i)
#define bug printf("-------debug-------\n");
#define clr(x,a) memset(x,a,sizeof(x))
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const int MAXN=200111;
const int MAXM=200111;

struct edge{
    int w,c;
    int u,v;
    int id;
} ;
int n,m;
int S;
vector<edge> E(MAXM);
bool inmst[MAXM];
vector<int> G2[MAXN];
template<int nm> 
struct  findset{
    int pa[nm];
    void init(){for(int i=1;i<=n;i++) pa[i]=i;}
    int find(int x) { return x==pa[x]?x:pa[x]=find(pa[x]);}
    void unio(int x,int y){int u=find(x);int v=find(y);int rd=rand();if(rd&1) pa[u]=v;else pa[v]=u;}
} ;

findset<MAXN> fs;

bool operator < (const edge &a ,const edge &b){
    return a.w<b.w;
}

ll krukal(){
    sort(E.begin(),E.begin()+m);
    ll msum=0;
    fs.init();
    int cnt=0;
    //printf("m:%d\n",m);
    for(int i=0;i<m;i++){
        if(fs.find(E[i].u) != fs.find(E[i].v)){
            inmst[i]=true;
            G2[E[i].u].push_back(i);
            G2[E[i].v].push_back(i);
            msum+=E[i].w;
            fs.unio(E[i].u,E[i].v);
            if(++cnt==n-1) break;
        }
    }
    return msum;
}
/*pair<ll,int>  dfs (int src,int dec,int fa){
    ll  tpm=0;
    int maxid;
    //bug
    //printf("-----%d %d-----\n",src,dec);
    pair<ll,int> ans;
    for(int i=0;i<(int)G2[src].size();i++){
        int v;
        if(E[G2[src][i]].u==src) v=E[G2[src][i]].v;else v=E[G2[src][i]].u;
        if(v==fa) continue;
        if(v==dec) return mp((ll)E[G2[src][i]].w,E[G2[src][i]].id);
        ans=dfs(v,dec,src);
        ll tmp=ans.first;
        int tmpid=ans.second;
        if(tmp>0) {
            if(tmp>tpm) {
                tpm=tmp;
                maxid=tmpid;
            }
        }
    }
    return mp(tpm,maxid);
}*/
int curtime=0;
int last=INF;
int fa[MAXN][19];
int depth[MAXN];
pair<int,int> mm[MAXN][19];

void dfs(int rt,int faa,int dep){
    depth[rt]=dep;
    fa[rt][0]=faa;
    for(int k=1;k<19;k++){
        if(fa[fa[rt][k-1]][k-1]<1) break;
        fa[rt][k]=fa[fa[rt][k-1]][k-1];
        if(mm[fa[rt][k-1]][k-1].first>mm[rt][k-1].first) mm[rt][k]=mm[fa[rt][k-1]][k-1];
        else mm[rt][k]=mm[rt][k-1];
    }
    REP(i,(int)G2[rt].size()){
        int u=E[G2[rt][i]].v;
        if(u==rt) u=E[G2[rt][i]].u;
        if(depth[u]>0) continue;
        dfs(u,rt,dep+1);
        mm[u][0].first=E[G2[rt][i]].w;
        mm[u][0].second=G2[rt][i];
    }
}

int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    for(int i=18;i>=0;i--) if(depth[u]-(1<<i) >=depth[v]) u=fa[u][i];
    int i;
    //printf("u:%d,v:%d dep:%d %d %d\n",u,v,depth[u],depth[v],fa[u][1]);
    assert(depth[u]==depth[v]);
    for(i=18;i>=0;i--) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}

pair<int,int> climtolca(int u,int l){
    if(u==l) return mp(0,0);
    int dd=depth[l]-depth[u];
    pair<int,int> res;
    res.first=0;
    for(int i=0;i<19;i++){
        if(dd&(1<<i)) {
            if(mm[u][i].first>res.first) res=mm[u][i];
            u=fa[u][i];
        }
    }
    return res;
}

pair<int,int> getans(int u,int v){
    int la=lca(u,v);
    pair<int,int> res=climtolca(u,la);
    pair<int,int> res2=climtolca(v,la);
    if(res.first<res2.first) return res2;
    return res;
}

/*
pair<int,int> getmaxw(int u,int v){
    //if(u==19 && v==14) {bug  printf("%d %d",pre[u],pre[v]);}
    if(u==v) return mp(0,0);
    int x=pre[u]<pre[v]?v:u;
    int ot=u+v-x;
    pair<int,int>  tmp;
    REP(e,(int)G2[x].size()){
        int f=E[G2[x][e]].u;
        if(f==x) f=E[G2[x][e]].v;
        if(pre[f]<x) {
            tmp=getmaxw(f,ot);
            if(E[G2[x][e]].w>tmp.first) tmp=mp(E[G2[x][e]].w,E[G2[x][e]].id);
            return tmp;
        }
    }
    return tmp;
}*/

void gao(){
    const ll mst=krukal();
    int ansid=-1;
    for(int i=0;i<m;i++) if(inmst[i] && E[i].c<last) last=E[i].c,ansid=i;
    //printf("mst: %I64d\n",mst);
    ll answ=0;
    pair<ll,int>  ans=mp(INFL,-1);
    pair<int,int> mytmp;
    dfs(1,0,1);
    ans=mp(mst-S/last,ansid);
    answ=E[ansid].w-S/E[ansid].c;
    //printf("%d %d------u19v14\n",pre[19],pre[14]);
    for(int i=0;i<m;i++){
        int u=E[i].u,v=E[i].v;
        if(E[i].c>=last) continue;
        if(inmst[i]) continue; 
        mytmp=getans(u,v);
        //bug printf("----%d %d  %d----\n",u,v,E[i].w);
        ll tmp=mst-mytmp.first;
        tmp+=E[i].w-S/E[i].c;
        if(tmp<ans.first){ answ=E[i].w-S/E[i].c;ans.first=tmp;ansid=i;ans.second=mytmp.second;}
    }
    printf("%I64d\n",ans.first);
 //   printf("%d\n",(int)Mst.size());
    for(int i=0;i<m;i++){
        if(!inmst[i] || i==ans.second) continue;
        printf("%d %d\n",E[i].id,E[i].w);
    }
    printf("%d %I64d\n",E[ansid].id,answ);
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    scanf("%d%d",&n,&m);
    REP(i,m){
        scanf("%d",&E[i].w);
        E[i].id=i+1;
    }
    REP(i,m){
        scanf("%d",&E[i].c);
    }
    REP(i,m){
        scanf("%d%d",&E[i].u,&E[i].v);
      //  printf("%d-%d-%d-%d-%d\n",E[i].id,E[i].u,E[i].v,E[i].w,E[i].v);
    }
    scanf("%d",&S);
    gao();
    //pair<ll,int> debug=getmaxw(3,4);printf("----%I64d %d---\n",debug.first,debug.second);
    return 0;
}
