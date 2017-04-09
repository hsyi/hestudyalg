#include <iostream>
#include <cstring>
using namespace std;
const int maxn=20;
char s[maxn],ans[maxn];
void gao(){
    int ls=strlen(s);
    char bf;
    int pos=-1;
    for(int i=0;i<ls-1;i++){
        if(s[i]>s[i+1]) {pos=i;break;}
    }
    if(pos==-1) {cout<<s<<endl;return;}
    int jw=0;
    if(--s[pos]=='0') jw=1;
    while(jw && (--pos)>=0){
        if(--s[pos] <= '0'){
            jw=1;
            s[pos]='9';
        }
        else jw=0;
        if(s[pos]>s[pos+1]) {
            s[pos+1]='9';
            jw=1;
        }
    }
    if(jw) ls--;
    for(int i=pos+1;i<ls;i++){
        s[i]='9';
    }
    s[ls]='\0';
}
int main(){
    int T,cas=1;
    cin>>T;
    while(T--){
        cin>>s;
        cout<<"Case #"<<cas++<<": ";
        gao();
        cout<<s<<endl;
    }
    return 0;
}