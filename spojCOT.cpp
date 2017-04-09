#include<cstdio>
#include<vector>
#include<algorithm>
const int MAXN=1e5+11;
int fa[MAXN][20],deep[MAXN],ind[MAXN],pos[MAXN],root[MAXN];
int m,n;
int w[MAXN];
struct{int sum,l,r;}T[MAXN*40];
int now;
std::vector<int> G[MAXN];
void dfs(int rt){
    ind[++now]=rt,pos[rt]=now;
    for(int i=1;i<20;i++){
        if(fa[fa[rt][i-1]][i-1]) fa[rt][i]=fa[fa[rt][i-1]][i-1];
        else break;
    }
    for(int i=0;i<(int)G[rt].size();i++){
        int v=G[rt][i];
        if(v==fa[rt][0]) continue;
        fa[v][0]=rt;
        deep[v]=deep[rt]+1;
        dfs(v);
    }
}
int cnt;
int lca(int u,int v){
    if(deep[u]<deep[v]) std::swap(u,v);
    for(int i=19;i>=0;i--) if(deep[u]-(1<<i)>=deep[v]) u=fa[u][i];
    if(u==v) return v;
    for(int i=19;i>=0;i--) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
void update(int l,int r,int &x,int y,int ps){
    T[++cnt]=T[y];x=cnt;T[x].sum++;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(mid>=ps) update(l,mid,T[x].l,T[y].l,ps);
    else update(mid+1,r,T[x].r,T[y].r,ps);
}

std::vector<int> v;
int query(int x,int y,int k){
    int l=1;int r=n;
    int a=x,b=y,c=lca(a,b),d=fa[c][0];
    a=root[pos[a]],b=root[pos[b]],c=root[pos[c]],d=root[pos[d]];
    while(l<r){
        int tmp=T[T[a].l].sum+T[T[b].l].sum-T[T[c].l].sum-T[T[d].l].sum;
        int mid=(l+r)>>1;
        if(tmp>=k) r=mid,a=T[a].l,b=T[b].l,c=T[c].l,d=T[d].l;
        else k-=tmp,l=mid+1,a=T[a].r,b=T[b].r,c=T[c].r,d=T[d].r;
    }
    return v[l-1];
}

int getid(int x) {return std::lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]),v.push_back(w[i]);
    std::sort(v.begin(),v.end()),v.erase(std::unique(v.begin(),v.end()),v.end());
    for(int i=0;i<n-1;i++) {
        int uu,vv;
        scanf("%d%d",&uu,&vv);
        G[uu].push_back(vv);
        G[vv].push_back(uu);
    }
    deep[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++){
        update(1,n,root[i],root[pos[fa[ind[i]][0]]],getid(w[ind[i]]));
    }
    for(int i=0;i<m;i++){
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        printf("%d\n",query(x,y,k));
    }
}
