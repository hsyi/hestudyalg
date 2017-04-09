#include<iostream>
using namespace std;
const int MAXN=5e5+11;
const int INF=0x3f3f3f3f;
struct Chess{
    int x,y,type;
} chess[MAXN];
int x,y,n;
int y1,y2,x1,x2,s1,s2,d1,d2;
int main(){
    cin>>n;
    cin>>x>>y;
    y1=y2=x1=x2=s1=s2=d1=d2=INF;
    for(int i=0;i<n;i++){
        char tmp;
        cin>>tmp;
        if(tmp=='B') chess[i].type=1;
        else if(tmp=='R') chess[i].type=2;
        else chess[i].type=3;
        int tx,ty;
        cin>>tx>>ty;
        chess[i].x=tx,chess[i].y=ty;
        if(tx==x){
            if(ty>y) {
                if(y1==INF) y1=i;
                else if(chess[y1].y>ty) y1=i;
            }
            else {
                if(y2==INF) y2=i;
                else if(chess[y2].y<ty) y2=i;
            }
        }
        if(ty==y){
            if(tx>x) {
                if(x1==INF) x1=i;
                else if(chess[x1].x>tx) x1=i;
            }
            else {
                if(x2==INF) x2=i;
                else if(chess[x2].x<tx) x2=i;
            }
        }
        if(tx+ty==x+y){
            if(tx>x) {
                if(s1==INF) s1=i;
                else if(chess[s1].x>tx) s1=i;
            }
            else {
                if(s2==INF) s2=i;
                else if(chess[s2].x<tx) s2=i;
            }
        }
        if(tx-ty==x-y){
            if(tx>x) {
                if(d1==INF) d1=i;
                else if(chess[d1].x>tx) d1=i;
            }
            else {
                if(d2==INF) d2=i;
                else if(chess[d2].x<tx) d2=i;
            }
        }
    }
    //cout<<y1<<" "<<y2<<" "<<s1<<" "<<s2<<" "<<x1<<" "<<x2<<" "<<d1<<" "<<d2<<endl;
    if(y1 !=INF && (chess[y1].type==2|| chess[y1].type==3)) goto YES;
    if(y2 !=INF && (chess[y2].type==2|| chess[y2].type==3)) goto YES;
    if(x2 !=INF && (chess[x2].type==2|| chess[x2].type==3)) goto YES;
    if(x1 !=INF && (chess[x1].type==2|| chess[x1].type==3)) goto YES;
    if(s2 !=INF && (chess[s2].type==1|| chess[s2].type==3)) goto YES;
    if(s1 !=INF && (chess[s1].type==1|| chess[s1].type==3)) goto YES;
    if(d2 !=INF && (chess[d2].type==1|| chess[d2].type==3)) goto YES;
    if(d1 !=INF && (chess[d1].type==1|| chess[d1].type==3)) goto YES;
    cout<<"NO"<<endl;
    return 0;
YES:cout<<"YES"<<endl;
    return 0;
}
