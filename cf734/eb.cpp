#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=2e5+11;
vector<int> G[MAXN];
int color[MAXN];
int dis[MAXN];
void dfs(int rt,int fa){
    for(int i=0;i<(int)G[rt].size();i++){
        int u=G[rt][i];
        if(u==fa) continue;
        dis[u]=dis[rt]+(color[u]^color[rt]);
        dfs(u,rt);
    }
}
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>color[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    int farnode=1;
    for(int i=1;i<=n;i++){
        if(dis[farnode]<dis[i]) farnode=i;
    }
    memset(dis,0,sizeof(dis));
    dfs(farnode,-1);
    for(int i=1;i<=n;i++){
        if(dis[farnode]<dis[i]) farnode=i;
    }
    cout<<(dis[farnode]+1)/2<<endl;
    return 0;
}
    

