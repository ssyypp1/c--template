//树状数组，区间修改，单点查询
#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N],n,m,b[N],tr[N];
void add_b(int l,int r,int x){
	b[l]+=x,b[r+1]-=x;
}
int lowbit(int x){
    return x&-x;
}
int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}
void add(int x, int u) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += u;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add_b(i,i,a[i]);
		add(i,a[i]);
		add(i+1,-a[i]);
	} 
	for(int i=1;i<=m;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			add(x,z),add(y+1,-z);
		}else{
			int x;
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
	}
}