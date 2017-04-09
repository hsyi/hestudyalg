#include<iostream>
#include<cstring>
using namespace std;
const int maxp=1e4+11;
const int maxs=1e6+11;
char p[maxp];
char s[maxs];
int f[maxp];
int lp,ls;
void getfail(){
    f[0]=0;
    f[1]=0;
    int cur=0;
    for(int i=1;i<lp;i++){
        cur=f[i];
        while(p[i]!=p[cur] && cur) cur=f[cur];
        if(p[i]==p[cur])
            f[i+1]=cur+1;
        else f[i+1]=0;
    }
}

int main(){
    int kas;
    cin>>kas;
    while(kas--){
        cin>>p;
        cin>>s;
        lp=strlen(p);
        ls=strlen(s);
        getfail();
        int cur=0;
        int ans=0;
        for(int i=0;i<ls;i++){
            while(p[cur]!=s[i] && cur) cur=f[cur];
            if(s[i]==p[cur]) {cur++;}
            if(cur==lp) {
                ans++; 
                //cout<<f[cur]<<"''''''''"<<endl;}
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

