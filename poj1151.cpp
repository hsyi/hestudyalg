//线段树的点表示以该点为起点的最短线段
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
const int MAXN=211;
const int MAXL=500;
struct Seg{
    double y1,y2,x;
    int in;
    //Seg(int y1,int y2,int x,int in):y1(y1),y2(y2),x(x),in(in){}
    //Seg(){}
} seg[MAXN];
bool cmp(const Seg &a,const Seg &b) {return a.x<b.x;}
double sum[MAXL<<2];
int cov[MAXL<<2];
std::vector<double> v;
int getid(double x) {return std::lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
int n;
int sz;
void push_up(int l,int r,int rt){
    if(cov[rt]) sum[rt]=v[r]-v[l-1];
    else if(l==r) sum[rt]=0;
    else {
        sum[rt]=sum[rt<<1]+sum[(rt<<1)+1];
    }
}
void update(int l,int r,int add,int L,int R,int rt){
    if(L>=l && R<=r) {cov[rt]+=add;push_up(L,R,rt);return;}
    int mid=(L+R)>>1;
    if(mid>=l) update(l,r,add,L,mid,rt<<1);
    if(mid<r) update(l,r,add,mid+1,R,(rt<<1)+1);
    push_up(L,R,rt);
}

int main(){
    int kas=0;
    while(~scanf("%d",&n) && n){    
        v.clear();
        sz=0;
        for(int i=0;i<n;i++){
            double x1,x2,y1,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            Seg tmp;tmp.y1=y1,tmp.y2=y2,tmp.x=x1,tmp.in=1;
            seg[sz++]=tmp;
            tmp.x=x2,tmp.in=-1;
            seg[sz++]=tmp;
            //seg[sz++]=(Seg){y1,y2,x1,1};
            //seg[sz++]=(Seg){y1,y2,x2,-1};
            v.push_back(y1),v.push_back(y2);
        }
        std::sort(v.begin(),v.end()),v.erase(std::unique(v.begin(),v.end()),v.end());
        std::sort(seg,seg+sz,cmp);
        memset(sum,0,sizeof(sum));
        memset(cov,0,sizeof(cov));
        //printf("%lf==%lf\n",seg[0].y1,seg[0].y2);
        update(getid(seg[0].y1),getid(seg[0].y2)-1,seg[0].in,1,v.size(),1);
        //printf("%lf==%lf\n",v[getid(seg[0].y1)-1],v[getid(seg[0].y2)-1]);
        double ans=0;
        for(int i=1;i<sz;i++){
            double len=sum[1];
            //printf("%d %f--\n",i,len);
            ans+=len*(seg[i].x-seg[i-1].x);
            if(i==sz-1) break;
            update(getid(seg[i].y1),getid(seg[i].y2)-1,seg[i].in,1,v.size(),1);
        }
        if(kas) printf("\n");
        printf("Test case #%d\nTotal explored area: %.2f\n",++kas,ans);
    }
    return 0;
}
