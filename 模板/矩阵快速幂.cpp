//p3390
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
long long n,k,m;
struct Ma{
   long long a[100][100];
}A;
Ma operator *(const Ma &A,const Ma &B){
    Ma C;
    memset(C.a,0,sizeof(C.a));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%m;
    return C;
}
Ma fast(Ma a,long long k){
    Ma S=A;
    k--;
    while(k){
        if(k&1) S=S*A;
        A=(A*A);
        k=k>>1;
    }
    return S;
}
int main (){
    cin>>n>>k;
    m=1000000007;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)cin>>A.a[i][j];
    Ma ans=fast(A,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++)cout<<(ans.a[i][j])%m<<" ";
        cout<<(ans.a[i][n])%m<<endl;
    }
    return 0;
}
