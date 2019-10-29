#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct Edge{
	int u,v,w;
};
Edge e[200001];
int fa[5001];
int n,m,ans=0;
int cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int kru(){
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0;
	for(int i=0;i<m;i++){
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x!=y){
			cnt++;
			fa[x]=y;
			ans+=e[i].w;
			if(cnt==n-1)return 0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e,e+m,cmp);
	kru();
	cout<<ans<<endl;
	return 0;
}

