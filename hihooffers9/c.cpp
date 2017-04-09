#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e5+11;
int weight[maxn];
int w[maxn];
int deep[maxn];
int pa[maxn][18];
int rt;
int n;
int target;
vector<int> T[maxn];
vector<int> nodes;
void build_tree(int crt,int dp){
    w[crt]=weight[crt];
    deep[crt]=dp;
    for(int i=0;i<(int)T[crt].size();i++){
        build_tree(T[crt][i],dp+1);
        w[crt]+=w[T[crt][i]];
    }
}
bool anc(int a,int b){
    if(deep[a]<deep[b]) swap(a,b);
    int h=deep[a]-deep[b];
    for(int bit=0;bit<18;bit++){
        if(h&(1<<bit)) a=pa[a][bit];
    }
    if(a==b) return true;
    return false;
}
    

int main(){
    int kas;
    cin>>kas;
    while(kas--){
        cin>>n;
        memset(weight,0,sizeof(weight));
        memset(w,0,sizeof(w));
        memset(pa,0,sizeof(pa));
        memset(deep,0,sizeof(deep));
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>weight[i];
            int p;
            cin>>p;
            pa[i][0]=p;
            if(p==0) {rt=i; continue;}
            T[p].push_back(i);
        }
        build_tree(rt,1);
        target=w[rt];
        if(target%3) {
            cout<<"0\n";
            goto clear;
        }
        target=target/3;
        for(int i=1;i<17;i++){
            for(int j=1;j<=n;j++){
                pa[j][i]=pa[pa[j][i-1]][i-1];
            }
        }
        for(int i=1;i<n;i++){
            if(w[i]==target) {
                nodes.push_back(i);
                cout<<w[i]<<"  ==\n";
            }
        }
        for(int i=0;i<(int)nodes.size();i++){
            for(int j=i+1;j<(int)nodes.size();j++){
                int a=nodes[i],b=nodes[j];
                if(!anc(a,b)) ans++;
            }
        }
        cout<<ans<<endl;
clear:  
        for(int i=1;i<=n;i++) T[i].clear();
        nodes.clear();
    }
    return 0;
}
        


