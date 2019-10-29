//p3372
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int N=100005;
int m,n;
int t[4*N],tag[N*4];
void pushdown(int l,int r,int now){
	if(l==r){
		tag[now]=0;
		return;
	}
	tag[now<<1]+=tag[now];
	tag[now<<1|1]+=tag[now];
	int mid=(l+r)>>1;
	t[now<<1]+=(mid-l+1)*tag[now];
	t[now<<1|1]+=(r-mid)*tag[now];
	tag[now]=0;
}
void refresh(int now){
	t[now]=t[now<<1]+t[now<<1|1];
}
void build(int l,int r,int now){
	if(l==r){
		scanf("%lld",&t[now]);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,now<<1);
	build(mid+1,r,now<<1|1);
	refresh(now);
}
int que(int l,int r,int now,int ll,int rr){
	if(l>=ll&&r<=rr)return t[now];
	if(tag[now])pushdown(l,r,now);
	int mid=(l+r)>>1;
	int ans=0;
	if(ll<=mid)ans=ans+que(l,mid,now<<1,ll,rr);
	if(rr>mid)ans=ans+que(mid+1,r,now<<1|1,ll,rr);
	return ans;
}
void updata(int l,int r,int now,int ll,int rr,int data){
	if(ll<=l&&r<=rr){
		tag[now]+=data;
		t[now]+=(r-l+1)*data;
		return;
	}
	if(tag[now])pushdown(l,r,now);
	int mid=(l+r)>>1;
	if(ll<=mid)updata(l,mid,now<<1,ll,rr,data);
	if(rr>mid)updata(mid+1,r,now<<1|1,ll,rr,data);
	refresh(now);
}
signed main(){
	cin>>m>>n;
	build(1,m,1);
	while(n--){
		int ch,a,b,k;
		scanf("%lld",&ch);
		if(ch==2){
			scanf("%lld%lld",&a,&b);
			printf("%lld\n",que(1,m,1,a,b));
		}
		else {
			scanf("%lld%lld%lld",&a,&b,&k);
			updata(1,m,1,a,b,k);
		}
	}
	return 0;
}
