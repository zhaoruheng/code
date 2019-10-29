#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[10000001];
int main (){
    //freopen("testdata.in","r",stdin);
    cin>>n>>m;
    a[1]=1;
    for(int i=2;i<=n;i++){
    	if(!a[i]&&(long long)i*i<=n)
    		for(int j=i*i;j<=n;j+=i)a[j]=1;
	}
	while(m--){
		int q;
		scanf("%d",&q);
		if(!a[q])printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}
