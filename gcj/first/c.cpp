#include <iostream>
#include <queue>
using namespace std;
int n,k;
priority_queue<int> mq;
void gao(){
    int x;
    int a,b;
    while(!mq.empty()) mq.pop();
    mq.push(n);
    for(int t=0;t<k;t++){
        x=mq.top();
        //cout<<"x:"<<x<<endl;
        mq.pop();
        a=x/2;
        if(x&1) b=a;
        else if(a) b=a-1;
        if(x==1) break;
        //cout<<"a:"<<a<<"b:"<<b<<endl;
        mq.push(a);
        mq.push(b);
    }
    cout<<a<<" "<<b<<endl;
}
int main(){
    int T,cas=1;
    cin>>T;
    while(T--){
        cin>>n>>k;
        cout<<"Case #"<<cas++<<": ";
        //if(n==k) {cout<<"0 0\n";continue;}
        gao();
    }
    return 0;
}