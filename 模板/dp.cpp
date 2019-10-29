//p1880
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int a[1001];
int s[501];
int f[501][501],g[501][501];
int main(){
    memset(f,0x3f,sizeof(f));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];

        f[i][i]=f[n+i][n+i]=0;
        g[i][i]=g[n+i][n+i]=0;
    }
    for(int i=1;i<=n;i++){
        s[n+i]=s[i]+s[n];
    }
    for(int j=2;j<=n*2;j++){
        for(int i=j-1;i>=1;i--){
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
                g[i][j]=max(g[i][j],g[i][k]+g[k+1][j]+s[j]-s[i-1]);
            }
        }
    }
    int ansi=0x3f3f3f3f,ansx=0;
    for(int i=1;i<=n;i++){
        ansi=min(ansi,f[i][n+i-1]);
        if(g[i][n+i-1]<0x3f3f3f3f)ansx=max(ansx,g[i][n+i-1]);
    }
    cout<<ansi<<endl;
    cout<<ansx<<endl;
    return 0;
}
