//线段树，区间修改，区间查询
#include<bits/stdc++.h>
using namespace std;
const int N=100001;

int n,m,a[N];
long long f[4*N],v[4*N];

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
void insert(int k,int l,int r,int x,int y,long long z){
	if(l==x&&r==y){
		v[k]+=z;
		return;
	}
	f[k]+=(y-x+1)*z;
	int m=(l+r)>>1;
	if(y<=m) insert(k+k,l,m,x,y,z);
	else
		if(x>m) insert(k+k+1,m+1,r,x,y,z);
		else insert(k+k,l,m,x,m,z),insert(k+k+1,m+1,r,m+1,y,z);
}
long long calc(int k,int l,int r,int x,int y,long long p){
	p+=v[k];
	if(l==x&&y==r) return p*(r-l+1)+f[k];
	int m=(l+r)>>1;
	if(y<=m) return calc(k+k,l,m,x,y,p);
	else
		if(x>m) return calc(k+k+1,m+1,r,x,y,p);
		else return calc(k+k,l,m,x,m,p)+calc(k+k+1,m+1,r,m+1,y,p);
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
			long long k;
			scanf("%d%d%lld",&x,&y,&k);
			insert(1,1,n,x,y,k);
		}else if(t==2){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",calc(1,1,n,x,y,0));
		}
	}
}