#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;

int n,m,a[N];
ll f[4*N],v[4*N];

void buildtree(int k,int l,int r){
	v[k]=0;
	if(l==r){
		f[k]=a[l];
		return;
	}
	int m=(l+r)>>1;
	buildtree(k+k,l,m);
	buildtree(k+k+1,m+1,r);
	f[k]=f[k+k]+f[k+k+1];
}
void insert(int k,int l,int r,int x,int y,ll z){
	if(l==x&&r==y){
		v[k]+=z;
		return;
	}
	int m=(l+r)>>1;
	if(v[k]) v[k+k]+=v[k],v[k+k+1]+=v[k],v[k]=0;
	if(y<=m) insert(k+k,l,m,x,y,z);
	else
		if(x>m) insert(k+k+1,m+1,r,x,y,z);
		else insert(k+k,l,m,x,m,z),insert(k+k+1,m+1,r,m+1,y,z);
	f[k]=f[k+k]+v[k+k]*(m-l+1)+f[k+k+1]+v[k+k+1]*(r-m);
}
long long calc(int k,int l,int r,int x,int y){
	if(l==x&&y==r) return v[k]*(r-l+1)+f[k];
	if(v[k]) v[k+k]+=v[k],v[k+k+1]+=v[k],v[k]=0;
	int m=(l+r)>>1;
	long long res=0;
	if(y<=m) res=calc(k+k,l,m,x,y);
	else
		if(x>m) res= calc(k+k+1,m+1,r,x,y);
		else res= calc(k+k,l,m,x,m)+calc(k+k+1,m+1,r,m+1,y);
	f[k]=f[k+k]+v[k+k]*(m-l+1)+f[k+k+1]+v[k+k+1]*(r-m);
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	buildtree(1,1,n);
	for(int i=1;i<=m;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y;
			ll k;
			scanf("%d%d%lld",&x,&y,&k);
			insert(1,1,n,x,y,k);
		}else if(t==2){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",calc(1,1,n,x,y));
		}
	}
}