#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n;
    cin>>n;
    char ch;
    int ans=0;
    while((ch=getchar())!='H' &&  ch!='T');
    for(int i=0;i<n;i++){
       // cout<<"=="<<i<<endl;
        if(ch=='H'){
            ans^=(i+1);
        }
        ch=getchar();
    }
    if(ans) cout<<"Alice\n";
    else cout<<"Bob\n";
    return 0;
}
        
