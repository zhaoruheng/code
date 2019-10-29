//p3367
#include<iostream>
#include<cstdio>
using namespace std;
int f[10010];
int n,m,x,y,z;
int find(int s){
    if(f[s]==s)return s;
    return f[s]=find(f[s]);
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        if(x==1)f[find(y)]=find(z);
        else
            if(find(y)==find(z))printf("Y\n");
            else printf("N\n");
    }
    return 0;
}
