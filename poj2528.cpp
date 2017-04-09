#include<cstdio>
#include<vector>
#include<cstring>
#include<set>
#include<algorithm>
const int MAXN=1e4+11;
const int MAXL=4e4+11;
std::vector<int> v;
int n;
struct {int l,r;} posts[MAXN];
int getid(int x){return std::lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
struct node{int color;}T[MAXL<<2];
void push_down(int rt){
    if(!T[rt].color) return;
    T[rt<<1].color=T[(rt<<1)+1].color=T[rt].color;
    T[rt].color=0;
}
void update(int l,int r,int L,int R,int color,int rt){
    if(L>=l && R<=r) {T[rt].color=color;return;}
    push_down(rt);
    int mid=(L+R)/2;
    if(L>=R) {T[rt].color=color;return;}
    if(mid>=l) update(l,r,L,mid,color,rt<<1);
    if(mid<r) update(l,r,mid+1,R,color,(rt<<1)+1);
    return;
}
std::set<int> ms;
int count(int l,int r,int rt){
    int ret=0;
    if(T[rt].color) {
        if(ms.end()==ms.find(T[rt].color))  ret=1;
        ms.insert(T[rt].color);
        return ret;
    }
    if(l<r){
        int mid=(l+r)/2;
        ret+=count(l,mid,rt<<1);
        ret+=count(mid+1,r,(rt<<1)+1);
    }
    return ret;
}
int main(){
    int kas;
    scanf("%d",&kas);
    while(kas--){
        scanf("%d",&n);
        v.clear();
        ms.clear();
        for(int i=0;i<n;i++){
            scanf("%d%d",&posts[i].l,&posts[i].r),v.push_back(posts[i].l),v.push_back(posts[i].r),v.push_back(posts[i].l-1),v.push_back(posts[i].r+1);
        }
        std::sort(v.begin(),v.end()),v.erase(std::unique(v.begin(),v.end()),v.end());
        memset(T,0,sizeof(T));
        for(int i=0;i<n;i++){
            update(getid(posts[i].l),getid(posts[i].r),1,4*n,i+1,1);
            //update(posts[i].l,posts[i].r,1,10,i+1,1);
        }
        printf("%d\n",count(1,4*n,1));
    }
    return 0;
}

        

