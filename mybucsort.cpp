#include <iostream>
using namespace std;
const int MAXN=1000;
void mybucsort(int a[]){
    int c[10];
    memset (c,0,sizeof(c));
    for(int i=0;i<MAXN;i++) c[a[i]%10] ++;
    for(int i=1;i<10;i++)   c[i]+=c[i-1];
    for(int i=0;i<MAXN;i++) a[


int main(){
    return 0;
}
