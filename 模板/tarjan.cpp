//p2341
#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int n,m,ys,cnt;
int in[10010],id[10010],du[10010],dfn[10010],low[10010],sum[10010];
vector<int>g[10010];
stack<int>s;
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	s.push(u);
	in[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	int k;
	if(dfn[u]==low[u]){
		ys++;
		do{
			k=s.top();s.pop();
			id[k]=ys;
			in[k]=0;
			sum[ys]++;
		}while(k!=u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			if(id[i]!=id[g[i][j]]){
				du[id[i]]++;
			}
		}
	}
	int e=0;
	for(int i=1;i<=ys;i++){
		if(!du[i]){
			if(e){
				printf("0\n");
				return 0;
			}
			e=i;
		}
	}
	printf("%d\n",sum[e]);
    return 0;
}
