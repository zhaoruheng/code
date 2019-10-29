//p1939
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
long long n,m;
struct Ma{
    long long a[4][4];
}A;
Ma operator *(const Ma &A,const Ma &B){
    Ma C;
    memset(C.a,0,sizeof(C.a));
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            for(int k=1;k<=3;k++)
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
    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        m=1000000007;
        if(n<=3){
            cout<<1%m<<endl;
            continue;
        }
        A.a[1][1]=1;A.a[1][2]=0;A.a[1][3]=1;A.a[2][1]=1;A.a[2][2]=0;A.a[2][3]=0;A.a[3][1]=0;A.a[3][2]=1;A.a[3][3]=0;
        Ma ans=fast(A,n-3);
        cout<<(ans.a[1][1]+ans.a[1][2]+ans.a[1][3])%m<<endl;
    }

//    for (int i=1; i<=3; i++) {
//        for (int j=1; j<=3; j++) {
//            cout<<ans.a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return 0;
}
