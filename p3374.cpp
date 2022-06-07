//线段树单点修改，区间查询
#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m,a[N],f[4*N];
void buildtree(int k,int l,int r){
	if(l==r){
		f[k]=a[l];
		return;
	}
	int m=(l+r)>>1;
	buildtree(k+k,l,m);
	buildtree(k+k+1,m+1,r);
	f[k]=f[k+k]+f[k+k+1];
}
void add(int k,int l,int r,int x,int y){
	f[k]+=y;
	if(l==r) return;
	int m=(l+r)>>1;
	if(x<=m) add(k+k,l,m,x,y);
	else add(k+k+1,m+1,r,x,y);
}
int calc(int k,int l,int r,int s,int t){
	if(l==s&&r==t) return f[k];
	int m=(l+r)>>1;
	if(t<=m) return calc(k+k,l,m,s,t);
	else
		if(s>m) return calc(k+k+1,m+1,r,s,t);
		else return calc(k+k,l,m,s,m)+calc(k+k+1,m+1,r,m+1,t);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	buildtree(1,1,n);
	for(int j=1;j<=m;j++){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1) add(1,1,n,x,y);
		else printf("%d\n",calc(1,1,n,x,y));
	}
	return 0;
}