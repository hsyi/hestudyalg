#include<iostream>
#include<queue>
using namespace std;
const int MAXN=23;
const int MAXM=23;
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool  vis[MAXN][MAXM][1<<14];
int m,n,l;
bool  Map[MAXN][MAXM];
struct node{
    int x,y,st,steps;
    bool block(int x,int y){
        if(x>=1 && y>=1 && x<=n && y<=m && Map[x][y]==false){
            int px=this->x;
            int py=this->y;
            int ts=this->st;
            if(px==x && py==y) return true;
            for(int i=1;i<l;i++){
                int d=ts&3;
                ts>>=2;
                px+=dir[d][0],py+=dir[d][1];
                if(x==px && y==py) return true;
            }
            return false;
        }
        return true;
    }
                

};
queue<node> mq;
int BFS(){
    while(!mq.empty()){
        node cnode=mq.front();
        mq.pop();
        if(cnode.x==1 && cnode.y==1) return cnode.steps;
        for(int d=0;d<4;d++){
            int nx=cnode.x+dir[d][0];
            int ny=cnode.y+dir[d][1];
            if(cnode.block(nx,ny)) continue;
            node nnode=cnode;
            nnode.st<<=2;
            nnode.x=nx,nnode.y=ny;
            nnode.st|=d;
            nnode.st&=(1<<(l<<1))-1;
            nnode.steps++;
            if(vis[nx][ny][nnode.st]) continue;
            else vis[nx][ny][nnode.st]=true;
            mq.push(nnode);
        }
    }
    return -1;
}
                       

        
int main(){
    int kas=0;
    while(~scanf("%d%d%d",&n,&m,&l) && (n|m|l)){
        node snode;
        scanf("%d%d",&snode.x,&snode.y);
        int px,py;
        px=snode.x;
        py=snode.y;
        snode.st=0;
        snode.steps=0;
        for(int i=0;i<l-1;i++){
            int tx,ty;
            scanf("%d%d",&tx,&ty);
            for(int d=0;d<4;d++){
                if(px+dir[d][0]==tx && py+dir[d][1]==ty) {
                    snode.st|=d<<(i<<1);
                    px=tx,py=ty;
                    break;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        memset(Map,0,sizeof(Map));
        int num_stone;
        scanf("%d",&num_stone);
        for(int i=0;i<num_stone;i++){
            int tx,ty;
            scanf("%d%d",&tx,&ty);
            Map[tx][ty]=1;
        }
        while(!mq.empty()) mq.pop();
        mq.push(snode);
        vis[snode.x][snode.y][snode.st]=true;
        printf("Case %d: %d\n",++kas,BFS());
    }
    return 0;
}
