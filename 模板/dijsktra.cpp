//p1339
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
//#include<vector>
//#include<map>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=2510;
int g[N][N];
int d[N];
int vis[N];
int n,m,s,e;
void dij(int s){
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    for(int i=1;i<=n;i++){
        int x=0,mn=0x3f3f3f3f;
        for(int j=1;j<=n;j++)if(vis[j]==0&&d[j]<mn)mn=d[x=j];
        if(x==0||x==e)return;
        vis[x]=1;
        for(int j=1;j<=n;j++){
            if(vis[j]==0)d[j]=min(d[j],d[x]+g[x][j]);
        }
    }
}
int main (){
    cin>>n>>m>>s>>e;
    memset(g,0x3f,sizeof(g));
    for(int i=0;i<m;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	g[u][v]=g[v][u]=w;
    }
    dij(s);
    cout<<d[e]<<endl;
    return 0;
}
