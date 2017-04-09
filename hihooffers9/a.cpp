#include<iostream>
#include<time.h>
using namespace std;
const int maxy=40;
const int lds1=11;
const int lds2=16;
struct Date{
    int y,M,d,h,m,s;
};
bool operator<  (Date const &d1,Date const &d2) {
    if(d1.y==d2.y){
        if(d1.M==d2.M){
            if(d1.d==d2.d){
                if(d1.h==d2.h){
                        if(d1.m==d2.m){
                            return d1.s<d2.s;
                        }
                        return d1.m<d2.m;
                }
                    return d1.h<d2.h;
            }
                return d1.d<d2.d;
        }
            return d1.M<d2.M;
    }
        return d1.y<d2.y;
}

bool operator==(Date const &d1,Date const &d2){
    return (d1.s==d2.s&&d1.h==d2.h&&d1.m==d2.m&&d1.M==d2.M&&d1.y==d2.y&&d1.d==d2.d);
}
                
const Date ds1[]={{1972,6,30,23,59,60},
    {1981,6,30,23,59,60},
    {1983,6,30,23,59,60},
    {1982,6,30,23,59,60},
    {1985,6,30,23,59,60},
    {1992,6,30,23,59,60},
    {1993,6,30,23,59,60},
    {1994,6,30,23,59,60},
    {1997,6,30,23,59,60},
    {2012,6,30,23,59,60},
    {2015,6,30,23,59,60}};
const Date ds2[]={
    {1972,12,31,23,59,60},
    {1973,12,31,23,59,60},
    {1974,12,31,23,59,60},
    {1975,12,31,23,59,60},
    {1976,12,31,23,59,60},
    {1977,12,31,23,59,60},
    {1978,12,31,23,59,60},
    {1979,12,31,23,59,60},
    {1987,12,31,23,59,60},
    {1989,12,31,23,59,60},
    {1990,12,31,23,59,60},
    {1995,12,31,23,59,60},
    {1998,12,31,23,59,60},
    {2005,12,31,23,59,60},
    {2008,12,31,23,59,60},
    {2016,12,31,23,59,60}};
const int secy=31536000;
const int secd=86400;
const int secm=3600;
bool isleap(int year){
    if(year%4) return false;
    else if(year%400 == 0) return true;
    else if(year%100 == 0 ) return false;
    else return true;
}
const Date lpd[]={
    {1972,2,29,0,0,0},
    {1976,2,29,0,0,0},
    {1980,2,29,0,0,0},
    {1984,2,29,0,0,0},
    {1988,2,29,0,0,0},
    {1992,2,29,0,0,0},
    {1996,2,29,0,0,0},
    {2000,2,29,0,0,0},
    {2004,2,29,0,0,0},
    {2008,2,29,0,0,0},
    {2012,2,29,0,0,0},
    {2016,2,29,0,0,0}};

int main(){
    Date d1,d2;
    scanf("%d-%d-%d %d:%d:%d",&d1.y,&d1.M,&d1.d,&d1.h,&d1.m,&d1.s);
    scanf("%d-%d-%d %d:%d:%d",&d2.y,&d2.M,&d2.d,&d2.h,&d2.m,&d2.s);
    int ans=0;
    if(d1.s==60) {ans--;d1.s=59;}
    if(d2.s==60) {ans++;d2.s=59;}
    for(int i=0;i<lds1;i++){
        if(ds1[i]<d2 && d1<ds1[i]) ans++;
    }
    for(int i=0;i<lds2;i++){
        if(ds2[i]<d2 && d1<ds2[i]) ans++;
    }
    struct tm D1,D2;
    D1.tm_sec=d1.s;
    D2.tm_sec=d2.s;
    D1.tm_min=d1.m;
    D2.tm_min=d2.m;
    D1.tm_hour=d1.h;
    D2.tm_hour=d2.h;
    D1.tm_mday=d1.d;
    D2.tm_mday=d2.d;
    D1.tm_mon=d1.M-1;
    D2.tm_mon=d2.M-1;
    D1.tm_year=d1.y-1900;
    D2.tm_year=d2.y-1900;
    //cout<<"===="<<mktime(&D1)<<endl;
    //cout<<"===="<<mktime(&D2)<<endl;
    double ans2;
    ans2=difftime(mktime(&D2),mktime(&D1));
    ans2=ans2+(double)ans;
    printf("%.f",ans2);
    return 0;
}
    

