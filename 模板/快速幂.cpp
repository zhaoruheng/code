//p1226
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
long long c,b,d;
//int fast(long long a,long long n,long long p){
//    if(n==1)return a%p;
//    long long s=fast(a,n/2,p);
//    s=(s*s)%p;
//    if(n%2==1)s=(s*a)%p;
//    return s;
//}
int fast(long long a,long long n,long long p){
    long long s=1;
    while(n){
        if(n&1)s=(s*a)%p;
        a=(a*a)%p;
        n=n>>1;
    }
    return s;
}
int main (){
    //freopen("testdata.in","r",stdin);
    cin>>c>>b>>d;
    if(b==0){
    	printf("%d^%d mod %d=%d\n",c,b,d,1%d);
    	return 0;
    }
    printf("%d^%d mod %d=%d\n",c,b,d,fast(c,b,d));
    return 0;
}
