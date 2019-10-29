#include<iostream>
//p3865
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n,m;
long long a[100010],f[100010][21];
void st(){
	int k=log(n)/log(2);
	for(int i=1;i<=n;i++)f[i][0]=a[i];
	for(int j=1;j<=k;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
}
long long an(int l,int r){
	int k=log(r-l+1)/log(2);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main (){
    //freopen("testdata.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}
	st();
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",an(x,y));
	}
    return 0;
}
