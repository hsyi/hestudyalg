#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e5+11;
char s[MAXN];
char ans[MAXN<<1];
int pos[MAXN];
int n;
struct Link{char t;int next;} l[MAXN];
int head,rear,rear2;
int cnt;

void insert(char t){
    int tmp=l[rear2].next;
    l[rear2].next=++cnt;
    l[cnt].t=t;
    l[cnt].next=tmp;
    rear2=cnt;
    if(l[rear].next==rear2) rear=rear2;
}
int main(){
    while(~scanf("%s",s)){
        cnt=0;head=0;rear=0;
        rear2=0;
        l[head].next=0;
    n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]=='['){
            rear2=head;
        }
        else if(s[i]==']'){
            rear2=rear;
        }
        else insert(s[i]);
    }
    int p=l[head].next;
    while(p!=l[rear].next){
        putchar(l[p].t);
        p=l[p].next;
    }
    putchar(10);
    }
    return 0;
}
        

        
         
        

