#include<cstring>
#include<map>
#include<cstdio>
#include<time.h>
#include<stdlib.h>
const int MAXN=2e4+11;
const int MAXQ=4e4+11;
int fa[MAXN],d[MAXN];
int n,q;
char line[100];
void init(int n){
    for(int i=0;i<=n;i++){
        fa[i]=i;
        d[i]=0;
    }
}
int msfind(int x){
    if(fa[x]!=x) {
        int rt=msfind(fa[x]);
        d[x]=d[fa[x]]^d[x];
        fa[x]=rt;
    }
    return fa[x];
}
void  msunion(int x,int y,int v){
    int rtx=msfind(x),rty=msfind(y);
    int t=rand();
    if(rtx==n) std::swap(rtx,rty);
    if( rty==n ||  t&1){
        fa[rtx]=rty;
        d[rtx]=d[x]^d[y]^v;
    }
    else{
 //       if(rty==n) printf("buggggg\n");
        fa[rty]=rtx;
        d[rty]=d[y]^d[x]^v;
    }
}
int p[20];
int main(){
    int kas=0;
 //   freopen("out.txt","w",stdout);
    srand((unsigned)time(NULL));
    while(~scanf("%d%d",&n,&q) && n){
        init(n);
        printf("Case %d:\n",++kas);
        bool ignore=false;
        int cnti=0;
        for(int Query=0;Query<q;Query++){
            char type[2];
            if(ignore) {gets(line);continue;}
            scanf("%s",type);
            if(type[0]=='I'){
                cnti++;
                gets(line);
                int p,q,v;
                if(sscanf(line,"%d%d%d",&p,&q,&v)==2){v=q,q=n;}
                int x=msfind(p),y=msfind(q);
                //printf("mi p q v %d %d %d\n",p,q,v);
                if(x==y && (d[p]^d[q]) !=v) { ignore=true;printf("The first %d facts are conflicting.\n",cnti);continue;}
                msunion(p,q,v);
   //            if(q==n) { printf("%d %d uninonn",p,msfind(p));}
            }
            else if(type[0]=='Q'){
                int k;
                scanf("%d",&k);
                std::map<int,int> mp;
                int ans=0;
    //            printf("k:%d ",k);
                for(int i=0;i<k;i++){
                    scanf("%d",&p[i]);
                    int rt=msfind(p[i]);
   //                 printf(" rt %d :%d ",p[i],rt);
                    if(!mp[rt]) mp[rt]=1;
                    else mp[rt]++;
                    ans^=d[p[i]];
                }
                for(std::map<int,int>::iterator i=mp.begin();i!=mp.end();i++){
 //                   printf("mp:%d %d",i->first,i->second);
                    if(i->first!=n && i->second%2) {printf("I don't know.\n");ans=0x3f3f3f3f;break;}

                }
                if(ans!=0x3f3f3f3f) printf("%d\n",ans);
            }
        }
        putchar(10);
    }
    return 0;
}



                
