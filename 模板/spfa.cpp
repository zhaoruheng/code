//p3371
#include<iostream>
#include<cstdio>
#include<cstring>
//#include<algorithm>
//#include<cmath>
#include<vector>
//#include<map>
#include<queue>
using namespace std;
int n,m,c,ti,v;
struct Edge{
    int v,w;
};
vector<Edge>g[10001];
int vis[10001];
int d[10001];
void spfa(int s){
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        vis[u]=0;
        int k=g[u].size();
        for(int i=0;i<k;i++){
            Edge e=g[u][i];
            int v=e.v,w=e.w;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                if(vis[v]==0){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
int main (){
    cin>>n>>m>>c;
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back((Edge){b,c});
    }
    spfa(c);
    for(int i=1;i<=n;i++){
        if(d[i]!=0x3f3f3f3f)cout<<d[i]<<" ";
        else cout<<"2147483647 ";
    }
    return 0;
}
