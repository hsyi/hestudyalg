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
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define REP(i, n) for (int i=0;i<n;++i)
#define clr(x,a) memset(x,a,sizeof(x))
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const int MAXN=200011;
const int MAXM=200011;

int n,m;
struct edge{
    int w,c,u,v;
    int id;
    bool operator < (const edge &b) const{ return w<b.w;}
} E[MAXM];
vector<edge> MST;
vector<int> G[MAXN];
int par[MAXN];
void myinit(int n){
    for(int i=1;i<=n;i++)
        par[i]=i;
}
int myfind(int x){return x==par[x]?x:par[x]=myfind(par[x]);}
void myunion(int u,int v){int x=myfind(u),y=myfind(v);if(rand()&1) par[x]=y;else par[y]=x;}

ll Mst(int m){
    myinit(n);
    sort(E,E+m);
    ll res=0;
    REP(i,m){
        if(myfind(E[i].u) != myfind(E[i].v)){
            myunion(E[i].u,E[i].v);
            MST.push_back(E[i]);
            G[E[i].u].push_back(i);
            G[E[i].v].push_back(i);
            res+=E[i].w;
        }
    }
    return res;
}

int fa[MAXN][20],mm[MAXN][20];
int deep[MAXN];

void dfs(int rt,int dep){
    deep[rt]=dep;
    for(int i=1;i<20;i++){
        if(!fa[rt][i-1]) break;
        fa[rt][i]=fa[fa[rt][i-1]][i-1];
        mm[rt][i]=max(mm[rt][i-1],mm[fa[rt][i-1]][i-1]);
    }
    for(int i=0;i<(int)G[rt].size();i++){
        int u=E[G[rt][i]].u;
        if(u==rt) u=E[G[rt][i]].v;
        if(deep[u]) continue;
        fa[u][0]=rt;
        mm[u][0]=E[G[rt][i]].w;
        dfs(u,dep+1);
    }
}

int lca(int u,int v){
    if(deep[u]<deep[v]) swap(u,v);
    if(deep[u]!=deep[v]){
        for(int i=19;i>=0;i--) if(deep[u]-(1<<i)>=deep[v]) u=fa[u][i];
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--) if(fa[u][i] != fa[v][i]){ u=fa[u][i],v=fa[v][i];}
    return fa[u][0];
}

int climb(int u,int l){
    int hh=deep[u]-deep[l];
    int res=0;
    for(int i=0;i<20;i++){
        if(hh&(1<<i)){
            res=max(res,mm[u][i]);
            u=fa[u][i];
        }
    }
    return res;
}

int maxinuv(int u,int v){
    int l=lca(u,v);
    int res=climb(u,l);
    res=max(res,climb(v,l));
    return res;
}
int  S;
void gao(){
    ll mst=Mst(m);
    int ansid;
    ll anssum=INFL;
    int answ;
    dfs(1,1);
    for(int i=0;i<m;i++){
        int u=E[i].u,v=E[i].v;
        int tominus=maxinuv(u,v);
        ll tmp=mst-(ll)tominus;
        int toadd=E[i].w-S/E[i].c;
        tmp+=(ll)toadd;
        if(tmp<anssum){anssum=tmp;ansid=i;answ=toadd;}
    }
    E[ansid].w=answ;
    MST.push_back(E[ansid]);
    sort(MST.begin(),MST.end());
    myinit(n);
    vector<pair<int,int> > ansv;
    //cout<<anssum<<endl;
    ll outans=0;
    for(int i=0;i<n;i++){
        if(myfind(MST[i].u) != myfind(MST[i].v)){
            //cout<<MST[i].id<<" "<<MST[i].w<<endl;
            outans+=MST[i].w;
            ansv.push_back(mp(MST[i].id,MST[i].w));
            myunion(MST[i].u,MST[i].v);
        }
    }
    cout<<outans<<endl;
    REP(i,n-1){
        cout<<ansv[i].first<<" "<<ansv[i].second<<endl;
    }
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin>>n>>m;
    REP(i,m) cin>>E[i].w;
    REP(i,m) cin>>E[i].c;
    REP(i,m) cin>>E[i].u>>E[i].v;
    REP(i,m) E[i].id=i+1;
    cin>>S;
    gao();

    return 0;
}
