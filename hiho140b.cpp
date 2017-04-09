#include<iostream>
#include<vector>
using namespace std;
const int maxn=1011;
struct Post{
    int x1,x2,y1,y2;
}ps[maxn];

bool intersect(Post& a,Post& b){
    return (!(a.x1>=b.x2 || b.x1>=a.x2 || a.y1>=b.y2 || b.y1>=a.y2));
}

bool inrec(int x,int y,Post& a){
    return (x>a.x1 && x<a.x2 && y>a.y1 && y<a.y2);
}
bool vis[maxn];
int w,h,n;
void  dfs(int s){
    vis[s]=true;
    for(int i=s+1;i<n;i++){
        if(!intersect(ps[s],ps[i])) continue;
        if(!vis[i]) dfs(i);
    }
}

int main(){
    cin>>w>>h>>n;
    for(int i=0;i<n;i++){
        cin>>ps[i].x1>>ps[i].y1>>ps[i].x2>>ps[i].y2;
    }
    int pos,ans=0;
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        dfs(i);
        int cnt=1;
        bool cover[4]={0};
        for(int j=i+1;j<n;j++){
            cnt+=vis[j]?1:0;
            if(inrec(ps[i].x1,ps[i].y1,ps[j])) cover[0]=1;
            if(inrec(ps[i].x2,ps[i].y1,ps[j])) cover[1]=1;
            if(inrec(ps[i].x2,ps[i].y2,ps[j])) cover[2]=1;
            if(inrec(ps[i].x1,ps[i].y2,ps[j])) cover[3]=1;
        }
        if(cnt>ans) {
            if(!(cover[0] && cover[1] && cover[2] && cover[3])){
                ans=cnt;
                pos=i+1;
            }
        }
    }
    cout<<ans<<" "<<pos<<endl;
    return 0;
}

