#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
char s[111];
char ans[111];
const char pt[]={'o','g','o'};
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    int ansp=0;
    for(int i=0;i<n;){
        bool flag=false;
        for(int p=0;p<3;p++){
            if(s[i+p]!=pt[p]) {flag=1;break;}
        }
        if(!flag){
            int p=3;
            ans[ansp++]='*';
            ans[ansp++]='*';
            ans[ansp++]='*';
            while(s[i+p]=='g'&& s[i+p+1]=='o' && i+p+2<=n){p+=2;}
            i=i+p;

        }
        else{
            ans[ansp++]=s[i++];
        }
    }
    puts(ans);
}
            

