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
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
    if(f) x = -x;
}
#define N (1000005)
#define fi first
#define se second
int a[N], nxt[N], head[N], cnt;
int sz[N], dep[N], f[N][24], n, m;
inline void add(int x, int y){
	a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt;
}
inline void dfs(int u, int fa){
	sz[u] = 1, dep[u] = dep[fa] + 1, f[u][0] = fa;
	for(int p = head[u]; p; p = nxt[p]){
		int v = a[p];
		if(v != fa) dfs(v, u), sz[u] += sz[v];
	}	
}
inline int Lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 22; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(dep[x] == dep[y]) break;
	}
	if(x == y) return x;
	for(int i = 22; i >= 0; i--)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
inline pair<int, int> pp(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 22; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]) x = f[x][i];
		if(dep[x] == dep[y]) break;
	}
	for(int i = 22; i >= 0; i--)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return make_pair(x, y);
}
int main(){
	read(n);
	for(int i = 1, x, y; i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	dfs(1, 0);
	for(int j = 1; j <= 22; j++)
		for(int i = 1; i <= n; i++) f[i][j] = f[f[i][j-1]][j-1];
	read(m);
	while(m--){
		int x, y; read(x), read(y);	
		if(x == y){ printf("%d\n", n); continue; }
		int lca = Lca(x, y), dis = dep[x] + dep[y] - 2 * dep[lca];
		if(dis & 1){ puts("0"); continue; }; 
		if(dep[x] < dep[y]) swap(x, y); int u = x;
		for(int i = 22; i >= 0; i--)
			if(dep[x] - dep[f[u][i]] < dis / 2 && dep[f[u][i]] > dep[lca]) u = f[u][i];
		if(dep[x] - dep[f[u][0]] == dis / 2){
			if(f[u][0] == lca){
				pair<int, int> p = pp(x, y);
				printf("%d\n", n - sz[p.fi] - sz[p.se] );
			}
			else printf("%d\n", sz[f[u][0]] - sz[u]);
		} 
		else puts("0"); 
	}
	return 0;
}
