#include<iostream>
#include<cstdio>
using namespace std;
void exgcd(long long a,long long b,long long& d,long long& x,long long& y){
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
    long long a,b,c=1,d,x,y;
    cin>>a>>b;
    for(long long i=1;i<=a;i++){
    	exgcd(i,b,d,x,y);
    	if(c%d!=0);//�޽�
    	printf("%lld\n",(x*(c/d)%b+b)%b);
	}

    return 0;
}
