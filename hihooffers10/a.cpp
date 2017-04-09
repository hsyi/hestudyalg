#include<iostream>
#include<cstring>
using namespace std;
char s[111];
int main(){
    int kas;
    cin>>kas;
    while(kas--){
        cin>>s;
        int a=0,l=0;
        for(int i=0;i<(int)strlen(s);i++){
            if(s[i]=='A') {l=0;a++;if(a>1) break;}
            else if(s[i]=='L'){l++;if(l>=3) break;}
            else l=0;
        }
        if(a>1 || l>2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
            

