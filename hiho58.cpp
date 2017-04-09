#include<iostream>
using namespace std;
const int maxl=1024*1024*11;
char s[maxl];
int main(){
    int kas;
    cin>>kas;
    while(kas--){
        int n;
        cin>>n;
        cin>>s;
        int c[3]={1,0};
        char b=s[0];
        int cur=0;
        bool flag=false;
        for(int i=1;i<n;i++){
            char tem=s[i];
            //cout<<"b:"<<b<<"  tem:"<<tem<<endl;
            if(tem==b){
                c[cur]++;
            }
            else if(tem==b+1){
                cur=(cur+1)%3;
                c[cur]=1;
                //cout<<"===="<<c[0]<<"  "<<c[1]<<"  "<<c[2]<<endl;
            }
            else {
                c[0]=1;
                cur=0;
            }
            if(c[0]>=c[1] && c[2]>=c[1] && c[2]) {
                puts("YES");
                flag=true;
                break;
            }
            b=tem;
        }
        if(!flag) puts("NO");
    }
    return 0;
}
