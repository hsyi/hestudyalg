#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=2e5+11;
int color[MAXN];
int belong[MAXN];
vector<int> G[MAXN],G2[MAXN];
int sz,n;
void dfs(int rt){
    for(int i=0;i<(int)G[rt].size();i++){
        int u=G[rt][i];
        if(belong[u]) continue;
        if(color[u]==color[rt]) belong[u]=belong[rt];
        else {
            belong[u]=++sz;
            G2[belong[rt]].push_back(belong[u]);
            //cout<<"debug"<<endl;
            G2[belong[u]].push_back(belong[rt]);
        }
        dfs(u);
    }
}
int depth[MAXN];
int farnode;
int maxdeep;
void dfs2(int rt,int deep){
    depth[rt]=deep;
    if(depth[rt]>maxdeep) {farnode=rt;maxdeep=deep;}
    for(int i=0;i<(int)G2[rt].size();i++){
        int u=G2[rt][i];
        if(depth[u]) continue;
        else dfs2(u,deep+1);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>color[i];
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    belong[1]=++sz;
    dfs(1);
    //cout<<"debug "<<sz<<endl;
    //cout<<belong[2]<<endl;
    if(sz<=1) {cout<<"0"<<endl;return 0;}
    dfs2(1,1);
    memset(depth,0,sizeof(depth));
    maxdeep=0;
    dfs2(farnode,1);
    //int ans=maxdeep&1?maxdeep>>1|1:maxdeep>>1;
    cout<<(maxdeep)/2;
    return 0;
}
