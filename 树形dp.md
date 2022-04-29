### 树形dp
#### 来源
acw4381翻转树边
```c++
#include<bits/stdc++.h>
using namespace std;

const int N = 200010,M=N*2;
int down[N],up[N],dp[N],cnt[N];
int h[N], e[M], ne[M], idx,w[M];
int n;
void add(int a, int b, int c)  // 添加一条边a->b，边权为c
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
void dfs_down(int x,int from){
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(i==(from^1)) continue;
        dfs_down(j,i);
        down[x]+=down[j]+w[i];
        cnt[x]=cnt[j]+1;
    }
}
void dfs_up(int u,int from){
    for(int i=h[u];i!=-1;i=ne[i]){
        if(i==(from^1)) continue;
        int j=e[i];
        dp[j]=dp[u]-w[i]+w[i^1];//换根法
        dfs_up(j,i);
    }
}
int main(){
    cin>>n;
    memset(h,-1,sizeof h);//表头初始化
    for (int i = 0; i < n-1; i ++ ){
        int a,b;
        cin>>a>>b;
        add(a, b,0);//正向边
        add(b, a, 1);//逆向边
    }
    dfs_down(1,-1);//第二个参数是边的编号idx
    dp[1]=down[1];
    dfs_up(1,-1);
    int res = N;
    for (int i = 1; i <= n; i ++ )
        res = min(res, dp[i]);
    printf("%d\n", res);
    for (int i = 1; i <= n; i ++ )
        if (dp[i] == res)
            printf("%d ", i);

    return 0;
}
```

#### 来源

洛谷3478

```c++
#include<bits/stdc++.h>
using namespace std;
#define ULL long long
const int N = 1000010,M=N*2;
ULL down[N],up[N],cnt[N],dp[N];
int h[N], e[M], ne[M], idx,w[M];
int n;
void add(int a, int b, int c)  // 添加一条边a->b，边权为c
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
void dfs_down(int x,int from){
    
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(i==(from^1)) continue;
        dfs_down(j,i);
        down[x]+=down[j]+cnt[j]+1;
        cnt[x]+=cnt[j]+1;
    }
}
void dfs_up(int u,int from){
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(i==(from^1)) continue;
        dp[j]=dp[u]+n-2*cnt[j]-2;
        dfs_up(j,i);
    }
}

int main(){
    cin>>n;
    memset(h,-1,sizeof h);//表头初始化
    for (int i = 0; i < n-1; i ++ ){
        int a,b;
        cin>>a>>b;
        //add(a, b,0);//正向边
        add(a,b,1);
        add(b,a,1);//逆向边
    }
    dfs_down(1,-1);//第二个参数是边的编号idx
    dp[1]=down[1];
    dfs_up(1,-1);
    ULL res = 0;
    for (int i = 1; i <= n; i ++ ){
        //cout<<down[i]<<" "<<up[i]<<endl;
        res = max(res, dp[i]);
    }
    for (int i = 1; i <= n; i ++ )
        if (dp[i] == res){
            printf("%d ", i);
            break;
        }
    return 0;
}
```



