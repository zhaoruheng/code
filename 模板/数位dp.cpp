#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b,cntl;
int f[11][13][2],l[11];
int abs(int s){
	return s>0?s:-s;
}
int dfs(int now,int pre,int lim){
	if(now==0)return 1;
	if(f[now][pre][lim]>-1)return f[now][pre][lim];
	int ans=0,up=lim?l[now]:9;
	for(int i=0;i<=up;i++){
		if(abs(i-pre)>=2){
			ans+=dfs(now-1,((i==0)&&(pre==12))?12:i,((i==up)&&(lim==1))?1:0);
		}
	}
	return f[now][pre][lim]=ans;
}
int sol(int x){
	cntl=0;
	while(x){
		l[++cntl]=x%10;
		x/=10;
	}
	if(cntl==0)cntl++;
	int ans=0;
	memset(f,-1,sizeof(f));
	for(int i=0;i<=l[cntl];i++){
		ans+=dfs(cntl-1,i==0?12:i,i==l[cntl]?1:0);
	}
	return ans;
}
int main(){
	cin>>a>>b;
	a--;
	int ansl=sol(a);
	int ansr=sol(b);
	cout<<ansr-ansl<<endl;
	return 0;
}
