#include<iostream>
#include<cstdio>
using namespace std;
long long n,p;
long long fast(long long a,long long n,long long p){
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
    cin>>n>>p;
    for(long long i=1;i<=n;i++){
    	long long ans=fast(i,p-2,p)%p;
    	printf("%lld\n",ans);
	}
    return 0;
}
