/*program by mangoyang*/
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define INF (0x7f7f7f7f)
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b) ((a) < (b) ? (a) : (b))
#define N (500005)
#define M (500005)
#define int LL
using namespace std;
inline void read(int &x){
    int w = 1; char ch = 0; x = 0;
    while (ch ^ '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    x = x * w;
}
queue <int> q;
int pre[N], st[N], inq[N], num;
int a[M], b[M], nxt[M], head[N], cnt;
int Dis[N], vis[N], n, m, S, T;
inline void add(int x, int y, int z){
    a[++cnt] = y, b[cnt] = z, nxt[cnt] = head[x], head[x] = cnt;
}
inline void SPFA(int S){
    for(int i = 1; i <= n; i++) Dis[i] = -INF / 3;
    q.push(S), vis[S] = 1, Dis[S] = 0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        if(++inq[now] >= n){
            printf("You show me the wrong map!"); exit(0);
        }
        for(int p = head[now]; p; p = nxt[p]){
            int v = a[p];
            if(Dis[now] + b[p] > Dis[v]){
                Dis[v] = Dis[now] + b[p];
                pre[v] = now;
                if(!vis[v]) q.push(v), vis[v] = 1;
            }
        }
        vis[now] = 0;
    }
}
inline void Out_Path(int x){
    if(x == S) return (void) (printf("%lld ", S));
    if(pre[x] && pre[x] != x) Out_Path(pre[x]); printf("%lld ", x);
}
main(){
    scanf("%lld%lld", &S, &T);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= m; i++){
        int x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        add(x, y, z);
    }
    SPFA(S);
    printf("%lld\n", Dis[T]), Out_Path(T);
    return 0;
}
