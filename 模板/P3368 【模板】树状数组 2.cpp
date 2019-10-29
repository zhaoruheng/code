#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[500001],a[500001];
int lowbit(int s){
    return s&-s;
}
void add(int x,int k){
    while(x<=n){
        t[x]+=k;
        x+=lowbit(x);
    }
}
int qu(int x){
    int ans=0;
    while(x){
        ans+=t[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        //int e;
        scanf("%d",&a[i]);
        //add(i,e);
    }
    for(int i=1;i<=m;i++){
        int ch,x,y,k;
        scanf("%d%d",&ch,&x);
        if(ch==1){
            scanf("%d%d",&y,&k);
            add(x,k);
            add(y+1,-k);
        }
        else {
            printf("%d\n",qu(x)+a[x]);
        }
    }
	return 0;
}
