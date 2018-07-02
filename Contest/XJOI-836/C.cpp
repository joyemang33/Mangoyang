/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
}
#define int ll
#define N (500005)
struct Node{ int d, v; };
vector<Node> v[N];
int a[N], nxt[N], ans[N], head[N], buf[N], dep[N], cnt, n, m;
inline void add(int x, int y){
	a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt;
}
inline void dfs(int u, int fa){
	dep[u] = dep[fa] + 1;
	for(int i = 0; i < v[u].size(); i++) buf[dep[u]+v[u][i].d] += v[u][i].v;
	ans[u] = buf[dep[u]];
	for(int p = head[u]; p; p = nxt[p]) if(a[p] != fa) dfs(a[p], u);
	for(int i = 0; i < v[u].size(); i++) buf[dep[u]+v[u][i].d] -= v[u][i].v;
}
main(){
	read(n), read(m);
	for(int i = 1, x, y; i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	for(int i = 1, u, x, y; i <= m; i++)
		read(u), read(x), read(y), v[u].push_back((Node){x, y});
	dfs(1, 0);
	for(int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}
