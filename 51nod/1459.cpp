//最短路径
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxv=511;
int score[maxv];
const int inf=0x3f3f3f3f;
int getscore[maxv];
struct edge{
    int v,dis;
};
vector<edge> G[maxv];
int dis[maxv];
inline void addedge(int u,int v,int tm){
    edge tmp;
    tmp.v=v;
    tmp.dis=tm;
    G[u].push_back(tmp);
    tmp.v=u;
    G[v].push_back(tmp);
}
int n,m,s,d;
struct node{
    int v,dis,score;
    node(int a,int b,int c):v(a),dis(b),score(c){}
    bool operator< (const node &b) const{
        return dis==b.dis?score<b.score:dis>b.dis;

    }
};
void gao(){
    priority_queue<node> mq; 
    fill(dis,dis+maxv,inf);
    dis[s]=0;
    getscore[s]=score[s];
    mq.push(node(s,0,score[s]));
    while(!mq.empty()){
        int x=mq.top().v;
        int tmpdis=mq.top().dis;
        int tmpscore=mq.top().score;
        mq.pop();
        if(tmpdis>dis[x]) continue;
        if(tmpdis == dis[x] && tmpscore > getscore[x]) continue;
        for(int i=0;i<(int)G[x].size();i++){
            if(dis[x]+G[x][i].dis<dis[G[x][i].v]){
                dis[G[x][i].v]=dis[x]+G[x][i].dis;
                getscore[G[x][i].v]=getscore[x]+score[G[x][i].v];
                mq.push(node(G[x][i].v, dis[G[x][i].v],getscore[G[x][i].v]));
            }
            else if(dis[x]+G[x][i].dis==dis[G[x][i].v] && getscore[x]+score[G[x][i].v]>getscore[G[x][i].v]){
                 getscore[G[x][i].v]=getscore[x]+score[G[x][i].v];
            }
        }
    }
}
int main(){
    cin>>n>>m>>s>>d;
    for(int i=0;i<n;i++){
        cin>>score[i];
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        addedge(a,b,c);
    }
    //cerr<<"debug"<<endl;
    gao();
    cout<<dis[d]<<" "<<getscore[d]<<endl;
}