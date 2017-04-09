#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+11;
int s[MAXN];
int a[MAXN];
int n;
inline void mod(int x,int y){
    if(a[x]){
        int tmp=a[x];
        for(int i=x;i<=n;i+=i&(-i)){
            s[i]-=tmp;
        }
    }
    for(int i=x;i<=n;i+=i&-i){
        s[i]+=y;
    }
}

inline int sum(int x){
    int ret=0;
    for(int i=x;i;i-=i&-i){
        ret+=s[i];
      //  cout<<i<<" "<<s[i]<<"--"<<endl;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    int kas=0;
    while(cin>>n && n){
        if(kas) cout<<endl;
        cout<<"Case "<<++kas<<":\n";
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            mod(i,x);
            a[i]=x;
        }
        char type;
        //cout<<sum(n)<<"==\n";
        while(cin>>type && type!='E'){
            int x,y;
            if(type=='S') {
                cin>>x>>y;
                mod(x,y);
                a[x]=y;
            }
            else {
                cin>>x>>y;
                //cout<<"x y"<<x<<y<<endl;
                cout<<sum(y)-sum(x-1)<<endl;
            }
        }
        cin.ignore(2,sizeof(char));
    }
    return 0;
}

