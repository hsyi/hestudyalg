#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=2e5+11;
const int MAXQ=2*105+11;
vector<int> G[MAXN];
int n,Q;
struct Query{int x,y,c;} q[MAXQ];
int t[MAXN];
int cnt,cnt2;
int sz[MAXN],fa[MAXN],top[MAXN],son[MAXN],deep[MAXN],id[MAXN],rh[MAXN],root[MAXN];
struct {int l,r,sum;} T[MAXN*40];
void dfs(int x,int y){
    sz[x]=1;fa[x]=y;
    for(int i=0;i<(int)G[x].size();i++){
        int v=G[x][i];
        if(v==y) continue;
        deep[v]=deep[x]+1;
        dfs(v,x);
        sz[x]+=sz[v];
        if(sz[v]>sz[son[x]]) son[x]=v;
    }
}
void dfs2(int x,int f){
    id[x]=++cnt2;
    top[x]=f;
    rh[cnt]=x;
    if(son[x]) dfs2(son[x],f);
    for(int i=0;i<(int)G[x].size();i++){
        int v=G[x][i];
        if(v==fa[x] || v==son[x]) continue;
        dfs2(v,v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    dfs(1,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++){
        int to;
        cin>>to;
        G[i].push_back(to),G[to].push_back(i);
    }
    cin>>Q;
    for(int i=1;i<=n;i++) t[i]=Q;
    for(int i=0;i<Q;i++){
        int type;
        cin>>type;
        if(type==1){
            cin>>q[cnt].x>>q[cnt].y>>q[cnt].c;
            q[cnt].c=i-q[cnt].c-1;
            cnt++;
        }
        else{
            int x;
            cin>>x;
            t[x]=i;
        }
    }
    for(int i=1;i<=n;i++) update(root[i-1],root[i],1,m,t[rh[i]]);
    

        

