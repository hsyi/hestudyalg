#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1e5+11;
vector<int> G[maxn];
int w[maxn],n;
void dfs1(int rt){
    for(int i=0;i<(int)G[rt].size();i++){
        dfs1(G[rt][i]);
        w[rt]+=w[G[rt][i]];
    }
}
long long  ans;
int tar,fir,sec,mrt;
void dfs2(int rt){
    if(w[rt]==tar) {ans+=fir+sec;}
    if(w[rt]==2*tar && rt!=mrt) sec++;
    for(int i=0;i<(int)G[rt].size();i++){
        dfs2(G[rt][i]);
    }
    if(w[rt]==tar) fir++;
    if(w[rt]==2*tar && rt!=mrt) sec--;
}
int main(){
    int kas;
    cin>>kas;
    while(kas--){
        cin>>n;
        int rt;
        memset(w,0,sizeof(w));
        for(int i=1;i<=n;i++){
            cin>>w[i];
            int pa;
            cin>>pa;
            if(pa==0) {mrt=rt=i;continue;}
            G[pa].push_back(i);
        }
        ans=fir=sec=0;
        dfs1(rt);
        if((w[rt]%3+3)%3!=0){
            cout<<"0"<<endl;
            continue;
        }
        tar=w[rt]/3;
        dfs2(rt);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            G[i].clear();
        }
    }
    return 0;
}
    
        
        

