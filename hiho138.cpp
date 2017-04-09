#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=4;
const int MAXM=4;
const int MAXT=1000;
int Q,N,M,T,S;
int boat[MAXN+1][MAXM+1];
int B[MAXT+11];
int C[MAXT+11];
int main(){
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d%d%d",&N,&M,&T,&S);
        for(int i=0;i<N;i++) for(int j=0;j<M;j++)scanf("%d",&boat[i][j]);
        for(int i=0;i<T;i++) scanf("%d",&B[i]);
        for(int i=0;i<T;i++) scanf("%d",&C[i]);
        sort(B,B+T,greater<int>());
        sort(B,B+T,greater<int>());

        



