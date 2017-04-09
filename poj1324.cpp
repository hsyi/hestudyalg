#include<iostream>
#include<cstring>
#include<queue>
#define mkpair make_pair
using namespace std;
const int MAXN=22;
const int MAXM=22;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,l;
int posx,posy;
int nblocks;
bool visit[MAXN][MAXM][1<<14|1];
struct State{
    int x,y,st;
   // State(int _x,int _y,int _st):x(_x),y(_y),st(_st){}
};
queue<pair<State,int> > mq;
bool Map[MAXN][MAXM];
int ans;
void getnewmap(State s){
    Map[s.x][s.y]=true;
    int px=s.x,py=s.y;
    int tx,ty;
    for(int i=0;i<l-1;i++){
        int ts=s.st;
        ts>>=2*(l-2-i);
        ts=ts & 0x3;
        if(ts ==1) {
            tx=px-1;
            ty=py;
            Map[tx][ty]=true;
        }
        if(ts== 2) {
            tx=px;
            ty=py-1;
            Map[tx][ty]=true;
        }
        if(ts== 0) {
            tx=px;
            ty=py+1;
            Map[tx][ty]=true;
        }
        if(ts == 3 ) {
            tx=px+1;
            ty=py;
            Map[tx][ty]=true;
        }
        px=tx,py=ty;
    }
}

void recovermap(State s){
    Map[s.x][s.y]=true;
    int px,py;
    px=s.x;
    py=s.y;
    int tx,ty;
    for(int i=0;i<l-1;i++){
        int ts=s.st;
        ts>>=2*(l-2-i);
        ts=ts & 0x3;
        if( ts == 1) {
            tx=px-1;
            ty=py;
            Map[tx][ty]=false;
        }
        if( ts == 2) {
            tx=px;
            ty=py-1;
            Map[tx][ty]=false;
        }
        if(ts == 0) {
            tx=px;
            ty=py+1;
            Map[tx][ty]=false;
        }
        if(ts == 3 ) {
            tx=px+1;
            ty=py;
            Map[tx][ty]=false;
        }
        px=tx,py=ty;
    }
}

void changestate(State &s,int d){
    s.st>>=2;
    int x;
    switch(d){
        case 0: x=1;break;
        case 1: x=3;break;
        case 2: x=2;break;
        case 3: x=0;break;
       // default:x=0;cout<<"error in changestate\n";
    }
    x<<=2*(l-2);
    s.st+=x;
}

int  bfs(){
    int ans=-1;
    while(!mq.empty()){
        State ns=mq.front().first;
        int steps=mq.front().second;
        visit[ns.x][ns.y][ns.st]=true;
        mq.pop();
        getnewmap(ns);
        if(ns.x==1 && ns.y==1) {
            ans=steps;
            return ans;
        }
        for(int i=0;i<4;i++){
            State nexts=ns;
            nexts.x+=dir[i][0];
            nexts.y+=dir[i][1];
            if(Map[nexts.x][nexts.y]==true) continue;
            changestate(nexts,i);
            if(visit[nexts.x][nexts.y][nexts.st]) continue;
            mq.push(mkpair(nexts,steps+1));
        }
        recovermap(ns);
    }
    return ans;
}

int main(){
    int kas=0;
    while(cin>>n>>m>>l && n && m && l){
        ans=-1;
        memset(visit,0,sizeof(visit));
        cin>>posx>>posy;
        int px,py;
        px=posx,py=posy;
        int st1=0;
        memset(Map,0,sizeof(Map));
        for(int i=0;i<=n;i++){
            Map[i][0]=true;
            Map[i][m+1]=true;
        }
        for(int i=0;i<=m;i++){
            Map[0][i]=true;
            Map[n+1][i]=true;
        }
        for(int i=0;i<l-1;i++){
            int tx,ty;
            cin>>tx>>ty;
            st1<<=2;
            if(px>tx) st1+=1;
            else if(px<tx) st1+=3;
            else if(py>ty) st1+=2;
            px=tx,py=ty;
        }
        State fs;
        fs.x=posx,fs.y=posy,fs.st=st1;
        //printf("%x\n",st1);
        cin>>nblocks;
        for(int i=0;i<nblocks;i++){
            cin>>px>>py;
            Map[px][py]=1;
        }
        while(!mq.empty()) mq.pop();
        mq.push(mkpair(fs,0));
        bfs();
    MYOUT: cout<<"Case "<<++kas<<": "<<ans<<endl;
    }
    return 0;
}


