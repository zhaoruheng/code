//p4479
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int N=100010;
int vis[N],d[N];
struct node{
    int v,w;
};
bool operator < (node x,node y){
    return x.w>y.w;
}
vector<node>g[N];
int n,m,s;
void dijkstra(int s){
    priority_queue<node>Q;
    memset(d,0x3f,sizeof(d));
    Q.push((node){s,0});
    d[s]=0;
    while(!Q.empty()){
        node uu=Q.top();Q.pop();
        int u=uu.v;
        if(vis[u])continue;
        vis[u]=1;
        int k=g[u].size();
        for(int i=0;i<k;i++){
            node f=g[u][i];
            int v=f.v,w=f.w;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                Q.push((node){v,d[v]});
            }
        }
    }
    return;
}
int main (){
    cin>>n>>m>>s;;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back((node){b,c});
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout<<d[i]<<" ";
    }
    cout<<endl;
    return 0;
}
