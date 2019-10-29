#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=500010;
int n,m,s;
//vector<int>g[N];
int f[N][21],d[N];
int to[N*2],nxt[N*2],head[N*2],tot;
void add(int x,int y){
    tot++;
    to[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
void dfs(int u,int p,int dep){
    d[u]=dep;
    f[u][0]=p;
    /*
    for (int i = 0; i <g[u].size(); i++) {
        int v=g[u][i];
        if(v!=p)dfs(v,u,dep+1);
    }
    */
    for(int i=head[u];i;i=nxt[i]){
        int v=to[i];
        if(v!=p)dfs(v,u,dep+1);
    }
}
void init(){
    int H=log(n)/log(2)+1;
    for (int j = 1; j <=H; j++) {
        for (int i = 1; i <= n; i++) {
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    int H=log(n)/log(2)+1;
    for (int i = H; i >=0; i--) if(d[f[x][i]]>=d[y])x=f[x][i];
    if(x==y)return x;
    for(int i=H;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int main() {
    scanf("%d%d%d",&n,&m,&s);
    for (int i = 1; i <n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
        //g[x].push_back(y);
        //g[y].push_back(x);
    }
    dfs(s,0,1);
    init();
    for (int i = 1; i <=m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n", lca(x,y));
    }
    return 0;
}
