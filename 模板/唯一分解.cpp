#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000005;
int p[N],vis[N],num[N];
int cnt=1;
void init(){
	vis[1]=1;
	for(int i=2;i<=1000000;i++){
		if((ll)i*i<=1000000&&!vis[i]){
			p[cnt++]=i;
			for(int j=i*i;j<=1000000;j+=i)
				vis[j]=1;
		}
	}
}
int main (){
    //freopen("testdata.in","r",stdin);
    int a,i=1;
    scanf("%d",&a);
    init();
    while(a!=1){
    	if(!(a%p[i])){
    		a/=p[i];
    		num[i]++;
		}
		else i++;
	}
    return 0;
}
