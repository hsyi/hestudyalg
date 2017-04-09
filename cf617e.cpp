#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
typedef long long ll;
int n,m,k;
const int MAXN=1e5+11;
const int MAXK=2e6+11;
ll flag[MAXK];
struct Query{int l,r,id;} Q[MAXN];
int pos[MAXN],a[MAXN],block;
ll ans[MAXN];
bool cmp(Query &a,Query &b){
    if(pos[a.l]==pos[b.l]) return a.r<b.r;
    return pos[a.l]<pos[b.l];
}
ll tans=0;
void update(int x,int add){
    x=a[x];
    if(add>0){
        tans+=flag[x^k];
        flag[x]++;
    }
    else {
        flag[x]--;
        tans-=flag[x^k];
    }
}    
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]), a[i]=a[i-1]^a[i];
    for(int i=0;i<m;i++) scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id=i;
    block=sqrt(n);
    for(int i=1;i<=n;i++)
        pos[i]=i/block;
    std::sort(Q,Q+m,cmp);
    int l=1,r=0;
    flag[0]=1;
    for(int i=0;i<m;i++){
        for(;r<Q[i].r;r++)
            update(r+1,1);
        for(;r>Q[i].r;r--)
            update(r,-1);
        for(;l<Q[i].l;l++)
            update(l-1,-1);
        for(;l>Q[i].l;l--)
            update(l-2,1);
        ans[Q[i].id]=tans;
    }
    for(int i=0;i<m;i++) printf("%I64d\n",ans[i]);
    return 0;
}

