#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
long long n,p;
long long a[3000001];
int main (){
    //freopen("testdata.in","r",stdin);
    cin>>n>>p;
    cout<<"1"<<endl;
    a[1]=1;
    for(long long i=2;i<=n;i++){
    	a[i]=(p-(p/i))*a[p%i]%p;
    	printf("%lld\n",a[i]);
	}
    return 0;
}
