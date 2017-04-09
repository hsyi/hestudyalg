#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
const int maxn=811;
const int maxm=811;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int G[maxn][maxm];
int A[maxn][maxm];
int n,m;
bool vis[maxn][maxn];
struct Node{
    int x,y,d;
};
queue<Node> mq;
void BFS(){
    while(!mq.empty()){
        Node cur=mq.front();
        mq.pop();
        A[cur.x][cur.y]=cur.d;
        for(int i=0;i<4;i++){
            Node p=cur;
            p.x=cur.x+dx[i];
            p.y=cur.y+dy[i];
            p.d=cur.d+1;
            if(vis[p.x][p.y]) continue;
            vis[p.x][p.y] = true;
            if(p.x<1 || p.x>n || p.y<1 || p.y>m) continue;
            mq.push(p);
        }
    }
}


    
int main(){
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        char tc=getchar();
        while(tc!='0' && tc!='1') tc=getchar();
        if(tc=='0'){
            G[i][j]=1;
            mq.push((Node){i,j,0});
            vis[i][j]=1;
        }
        else if(tc=='1'){
            G[i][j]=0;
        }
        else printf("error!\n");
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) 
            A[i][j]=10000000;
    }
    BFS();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
        
