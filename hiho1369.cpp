#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=511;
const int inf=0x3f3f3f3f;
struct Edge{
    int from,to,cap,flow;
    Edge(int a=0,int b=0,int c=0,int d=0):from(a),to(b),cap(c),flow(d){}
};
int n,m;
vector<Edge> G[maxn];
int delta,maxflow;
bool vis[maxn];
int  capacity[maxn];
int  path[maxn];
int findAugmentPath(){
    queue<int> mq;
    mq.push(1);
    memset(vis,0,sizeof(vis));
    memset(capacity,0,sizeof(capacity));
    memset(path,0,sizeof(path));
    capacity[1]=inf;
    while(!mq.empty()){
        int u=mq.front();
        mq.pop();
        if(u==n) return capacity[n];
        for(int i=0;i<(int)G[u].size();i++){
            Edge tmp=G[u][i];
            if(vis[tmp.to] || tmp.cap<=tmp.flow) continue;
            vis[tmp.to]=true;
            capacity[tmp.to]=min(capacity[tmp.from],tmp.cap-tmp.flow); 
            path[tmp.to]=u;
            mq.push(tmp.to);
        }
    }
    return 0;
}

void modifyGraph(){
    int cur=n;
    while(cur!=1){
        int p=path[cur];
        for(int i=0;i<(int)G[cur].size();i++){
            if(G[cur][i].to==p){
                G[cur][i].flow-=delta;
                break;
            }
        }
        for(int i=0;i<(int)G[p].size();i++){
            if(G[p][i].to==cur){
                G[p][i].flow+=delta;
                break;
            }
        }
        cur=p;
    }
}
int h[maxn][maxn];
int main(){
    cin>>n>>m;
    delta=0;
    maxflow=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        h[a][b]+=c;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int c=h[i][j]+h[j][i];
            if(!c) continue;
            int a=i,b=j;
            Edge tmp(a,b,c,0);
            G[a].push_back(tmp);
            tmp.from=b,tmp.to=a;
            G[b].push_back(tmp);
        }
    }
    
    while((delta=findAugmentPath())){
        maxflow+=delta;
        modifyGraph();
    }
    cout<<maxflow<<endl;
    return 0;
}
