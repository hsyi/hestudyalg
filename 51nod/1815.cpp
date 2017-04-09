#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxv = 4e5+11;
vector<int> G[maxv];
int first[maxv];
int second[maxv];
int a[maxv];
int n,q,m;
int s;
bool vis[maxv];
void dfs(int u){
    vis[u]=true;
    for(int i=0;i<(int)G[u].size();i++){
        int v=G[u][i];
        bool flag=false;
        vector<int> vec;
        vec.push_back(first[u]);
        vec.push_back(first[v]);
        vec.push_back(second[u]);
        vec.push_back(second[v]);
        sort(vec.begin(),vec.end(),greater<int>() );
        unique(vec.begin(),vec.end());
        // cout<<"v:"<<v<<endl;
        // for(int ii=0;ii<(int)vec.size();ii++){
        //     cout<<vec[ii]<<" ";
        // }
        // cout<<endl;
        if(vec[0] == first[v] && vec[1]==second[v]) {}
        else flag=true;
        if(flag){
            first[v]=vec[0];
            second[v]=vec[1];
            if(first[v]==second[v]) second[v]=0;
        }
        //cout<<first[v]<<" "<<second[v]<<endl;


        if(!vis[v] || flag) dfs(v);
    }

}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>n>>m>>q>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        first[i]=a[i];
        second[i]=0;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    dfs(s);
    for(int i=0;i<q;i++){
        int ct;
        cin>>ct;
        if(vis[ct])
        cout<<second[ct]<<" ";
        else cout<<"-1 ";
    }
    return 0;
}