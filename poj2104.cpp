#include<cstdio>
#include<vector>
#include<algorithm>
const int MAXN=1e5+7;
const int MAXM=5e3+11;
int n,m, root[MAXN],cnt,a[MAXN];
struct{int l,r,sum;}T[MAXN*40];
std::vector<int> v;
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
void update(int l,int r,int &x,int y,int num){
    T[++cnt]=T[y];T[cnt].sum++;x=cnt;
    if(l==r) return;
    int mid=l+((r-l)>>1);
    if(num>mid) update(mid+1,r,T[x].r,T[y].r,num);
    else  update(l,mid,T[x].l,T[y].l,num);
    //if(num<=mid) update(l,mid,T[x].l,T[y].l,num);
    //else update(mid+1,r,T[x].r,T[y].r,num);
}

int query(int l,int r,int x,int y,int k){
    if(l==r) return l;
    int mid=l+((r-l)>>1);
    int sum=T[T[y].l].sum-T[T[x].l].sum;
    if(k>sum) return query(mid+1,r,T[x].r,T[y].r,k-sum);
    else return query(l,mid,T[x].l,T[y].l,k);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),v.push_back(a[i]);
    sort(v.begin(),v.end()),v.erase(std::unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++) update(1,n,root[i],root[i-1],getid(a[i]));
    printf("bug");
    for(int i=1;i<=m;i++){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",v[query(1,n,root[l-1],root[r],k)-1]);
    }
}
