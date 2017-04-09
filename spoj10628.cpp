#include<cstdio>
#include<vector>
#include<algorithm>
const int MAXN=1e5+11;
std::vector<int> G[MAXN];
int n,m;
int w[MAXN];
std::vector<int> v;
int getid(int x){return std::lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
int fa[MAXN][20],deep[MAXN];
int num[MAXN],pos[MAXN];
int root[MAXN],cnt;
struct{int l,r,sum;} T[MAXN*40];
int cur;
void dfs(int rt){
    num[++cur]=rt;pos[rt]=cur;
    for(int i=1;i<20;i++){
        if(deep[rt]-(1<<i)>=0)
        //if(fa[fa[rt][i-1]][i-1])
            fa[rt][i]=fa[fa[rt][i-1]][i-1];
        else break;
    }
    for(int i=0;i<(int)G[rt].size();i++){
        int v=G[rt][i];
        if(v==fa[rt][0]) continue;
        deep[v]=deep[rt]+1;
        fa[v][0]=rt;
        dfs(v);
    }
}
    
void update(int l,int r,int &x,int y,int ps){
    T[++cnt]=T[y];x=cnt;T[x].sum++;
    if(l==r) return;
    int mid=(l+r)/2;
    if(ps<=mid) update(l,mid,T[x].l,T[y].l,ps);
    else update(mid+1,r,T[x].r,T[y].r,ps);
}
int lca(int x,int y){
    if(deep[x]<deep[y]) std::swap(x,y);
    for(int i=19;i>=0;i--) if(deep[x]-(1<<i) >= deep[y]) x=fa[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int query(int l,int r,int x,int y,int k){
    int a=x,b=y,c=lca(x,y),d=fa[c][0];
    a=root[pos[a]],b=root[pos[b]],c=root[pos[c]],d=root[pos[d]];
    while(l<r){
        int mid=(l+r)/2;
        int tmp=T[T[a].l].sum+T[T[b].l].sum-T[T[c].l].sum-T[T[d].l].sum;
        if(tmp>=k) r=mid,a=T[a].l,b=T[b].l,c=T[c].l,d=T[d].l;
        else k-=tmp,l=mid+1,a=T[a].r,b=T[b].r,c=T[c].r,d=T[d].r;
    }
    return v[l-1];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]),v.push_back(w[i]);
    std::sort(v.begin(),v.end()),v.erase(std::unique(v.begin(),v.end()),v.end());
    //for(int i=0;i<(int)v.size();i++) printf("%d--",v[i]);putchar(10);
    //for(int i=1;i<=n;i++) printf("%d---",getid(w[i]));putchar(10);
    for(int i=1;i<=n-1;i++){int u,v;scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);}
    dfs(1);
    for(int i=1;i<=n;i++) {int t=num[i];update(1,n,root[i],root[pos[fa[t][0]]],getid(w[t]));}//按建树顺序建主席树
    int last=0;
    for(int i=1;i<=m;i++) {int x,y,k;scanf("%d%d%d",&x,&y,&k);last=query(1,n,x,y,k);printf("%d",last);if(i!=m) printf("\n");}
    return 0;
}
