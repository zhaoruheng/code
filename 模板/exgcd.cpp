#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
void exgcd(int a,int b,int& d,int& x,int& y){
	if(!b){
		d=a;x=1;y=0;
	}
	else {
		exgcd(b,a%b,d,y,x);
		y-=(a/b)*x;
	}
}
int main (){
    //freopen("testdata.in","r",stdin);
    int a,b,c,d,x,y;
    cin>>a>>b>>c;
    exgcd(a,b,d,x,y);
    if(c%d!=0);//�޽�
    printf("%d %d",x*(c/d),y*(c/d));
    return 0;
}
