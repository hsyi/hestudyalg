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
struct Node{
    int r,v,s;
    Node *ch[2];
    Node (int v):v(v){ch[0]=ch[1]=NULL;r=rand();s=1;}
    bool operator < (const Node &a) const{
        return r<a.r;
    }
    int cmp(int x) const {
        if(x==v) return -1;
        return x<v?0:1;
    }
    void pushup(){
        s=1;
        if(ch[0]!=NULL) s+=ch[0]->s;
        if(ch[1]!=NULL) s+=ch[1]->s;
    }
};

void rotate(Node* &o,int d){
    Node *k=o->ch[1^d];o->ch[1^d]=k->ch[d];
    k->ch[d]=o;
    o->pushup();
    k->pushup();
    o=k;
}

void insert(Node* &o,int x){
    if(o == NULL) o=new Node(x);
    else {
        int d=(x<o->v?0:1);
        insert(o->ch[d],x);
        if(o->ch[d]->r > o->r) rotate(o,d^1);
    }
    o->pushup();
}   
void remove(Node* &o,int x){
    int d=o->cmp(x);
    if(d==-1){
        Node *u = o;
        if(o->ch[0]!=NULL && o->ch[1] !=NULL){
            int d2=(o->ch[0]->r > o->ch[1]->r?0:1);
            rotate(o,d2^1);remove(o->ch[d2^1],x);
        }else {
            if(o->ch[0]==NULL) o=o->ch[1];else o=o->ch[0];
            delete u;
        }
    }else {
        remove(o->ch[d],x);
    }
    if(o!=NULL) o->pushup();
}

const int MAXC=500000+11;
struct Command{
    char type;
    int x,p;
} commands[MAXC];

const int MAXN=20000+11;
const int MAXM=60000+11;

int n,m,weight[MAXN],from[MAXM],to[MAXM],removed[MAXM];

int pa[MAXN];

int findset(int x){
    return pa[x]==x?x:pa[x]=findset(pa[x]);
}

Node *root[MAXN];

int kth(Node *o,int k){
    if(o==NULL || k<0 || k>o->s) return 0;
    int s=(o->ch[1]==NULL?0:o->ch[1]->s);
    if(k==s+1) return o->v;
    else if(k>s+1) return kth(o->ch[0],k-s-1);
    else return kth(o->ch[1],k);
}

void mergeto(Node* &src,Node* &dest){
    if(src->ch[0]!=NULL) mergeto(src->ch[0],dest);
    if(src->ch[1]!=NULL) mergeto(src->ch[1],dest);
    insert(dest,src->v);
    delete src;
    src=NULL;
}

void removetree(Node* &x) {
    if(x->ch[0]!=NULL) removetree(x->ch[0]);
    if(x->ch[1]!=NULL) removetree(x->ch[1]);
    delete x;
    x=NULL;
}

void add_edge(int x){
    int u=findset(from[x]);
    int v=findset(to[x]);
    if(u==v) return;
    else {
        if(root[u]->s<root[v]->s) {pa[u]=v;mergeto(root[u],root[v]);}
        else  {pa[v]=u;mergeto(root[v],root[u]);}
    }
}

int query_cnt;
ll query_tot;

void query(int x,int k){
    int u=findset(x);
    query_cnt++;
    query_tot+=kth(root[u],k);
}

void change_weight(int x,int v){
    int u=findset(x);
    remove(root[u],weight[x]);
    insert(root[u],v);
    weight[x]=v;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/heshengyi/Downloads/in.txt","r",stdin);
    //freopen("/Users/heshengyi/Downloads/out.txt","w",stdout);
#endif
    srand(time(NULL));
    int kas=0;
    while(scanf("%d%d",&n,&m)==2 && n){
        for(int i=1;i<=n;i++) scanf("%d",&weight[i]);
        for(int i=1;i<=m;i++) scanf("%d%d",&from[i],&to[i]);
        memset(removed,0,sizeof(removed));
        int c=0;
        for(;;){
            char type;
            int x,p=0,v=0;
            scanf("%c",&type);
            if(type=='E') break;
            scanf("%d",&x);
            if(type=='D') removed[x]=1;
            if(type=='Q') scanf("%d",&p);
            if(type=='C'){
                scanf("%d",&v);
                p=weight[x];
                weight[x]=v;
            }
            commands[c++]=(Command){type,x,p};
        }
        for(int i=1;i<=n;i++){
            pa[i]=i;if(root[i]!=NULL) removetree(root[i]);
            root[i]=new Node(weight[i]);
        }
        for(int i=1;i<=m;i++) {
            if(!removed[i]) add_edge(i);
        }
        query_cnt=query_tot=0;
        for(int i=c-1;i>=0;i--){
            if(commands[i].type=='D') add_edge(commands[i].x);
            if(commands[i].type=='Q')query(commands[i].x,commands[i].p);
             if(commands[i].type=='C')change_weight(commands[i].x,commands[i].p);
            
        }
        printf("%d\n",query_cnt);
        printf("Case %d: %.6lf\n",++kas,(double)query_tot/query_cnt);//强制转化一个就可以
    }

    return 0;
}
