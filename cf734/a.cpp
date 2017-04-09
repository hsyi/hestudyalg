#include<iostream>
#include<cstdio>
using namespace std;
int cnt1,cnt2;
int n;
int main(){
    scanf("%d",&n);
    char tmp;
    getchar();
    for(int i=0;i<n;i++){
        scanf("%c",&tmp);
        if(tmp=='A') cnt1++;
        else cnt2++;
    }
    if(cnt1>cnt2) printf("Anton\n");
    else if(cnt1<cnt2) printf("Danik\n");
    else printf("Friendship\n");
    return 0;
}
