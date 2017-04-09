#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e3+11;
const int MAXM=1e3+11;
int pos[MAXN][MAXM];
int n,m;
const int dir[][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>pos[i][j];
        }
    }
    int cnt1=0;
    for(int i=1;i<=n;i++){
        bool l1=false;
        for(int j=1;j<=m;j++){
            if(pos[i][j]==1) l1=true;
            else if(l1) cnt1++;
        }
    }
    for(int i=1;i<=n;i++){
        bool l1=false;
        for(int j=m;j>=1;j--){
            if(pos[i][j]==1) l1=true;
            else if(l1) cnt1++;
        }

    }
    for(int j=1;j<=m;j++){
        bool l1=false;
        for(int i=1;i<=n;i++){
            if(pos[i][j]==1) l1=true;
            else if(l1) cnt1++;
        }
    }
    for(int j=1;j<=m;j++){
        bool l1=false;
        for(int i=n;i>=1;i--){
            if(pos[i][j]==1) l1=true;
            else if(l1) cnt1++;
        }
    }
    cout<<cnt1;
    return 0;
}

        
