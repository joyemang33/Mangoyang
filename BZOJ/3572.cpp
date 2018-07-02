/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (700005)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
}
int a[N], nxt[N], head[N], cnt;
int sz[N], dep[N], dfn[N], bel[N], f[N][23], ans[N], g[N];
int n, q, m[N];
inline void add(int x, int y){ a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt; }
namespace Lca{
	int ff[N][23], Log[N], tot;
	inline int chkmin(int x, int y){ return dep[x] < dep[y] ? x : y; }
	inline void dfs(int u, int fa){ 
		f[u][0] = fa, sz[u] = 1, dep[u] = dep[fa] + 1, ff[++tot][0] = u, dfn[u] = tot;
		for(int p = head[u]; p; p = nxt[p]){
			int v = a[p];
			if(v != fa) dfs(v, u), ff[++tot][0] = u, sz[u] += sz[v];
		}
	}
	inline void calc(){
		for(int i = 2; i < N; i++) Log[i] = Log[i>>1] + 1;
		for(int j = 1; j <= 22; j++)
			for(int i = 1; i <= n; i++) f[i][j] = f[f[i][j-1]][j-1];
		for(int j = 1; j <= 22; j++)
			for(int i = 1; i + (1 << j) - 1 <= tot; i++)
				ff[i][j] = chkmin(ff[i][j-1], ff[i+(1<<j-1)][j-1]);
	}
	inline int get(int u, int v){
		int x = dfn[u], y = dfn[v];
		if(x > y) swap(x, y); int g = Log[y-x+1];
		return chkmin(ff[x][g], ff[y-(1<<g)+1][g]);
	}
	inline int dis(int u, int v){ return dep[u] + dep[v] - 2 * dep[get(u, v)]; } 
	inline void Doit(){ dfs(1, 0), calc(); }
}
namespace VirTree{
	int a[N], nxt[N], head[N], Node[N], fa[N], vr[N], st[N], tot, cnt;
	inline void Clear(){
		for(int i = 1; i <= tot; i++) bel[vr[i]] = ans[vr[i]] = g[vr[i]] = 0;
		for(int i = 1; i <= cnt; i++) head[a[i]] = 0, a[i] = nxt[i] = 0;
		head[1] = cnt = tot = 0;
	}
	inline bool cmp(int x, int y){ return dfn[x] < dfn[y]; } 
	inline void add(int x, int y){ a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt; }
	inline void build(int m[], int size){
		int top = 0;
		for(int i = 1; i <= size; i++) Node[i] = m[i];
		sort(Node + 1, Node + size + 1, cmp);
		for(int i = 1; i <= size; i++){
			if(Node[i] == Node[i-1]) continue;
			int u = Node[i], lca = Lca::get(u, st[top]);
			if(!top){ st[++top] = u, vr[++tot] = u; continue; }
			while(top > 1 && dep[st[top]] > dep[lca]){
				if(dep[st[top-1]] < dep[lca]) fa[st[top]] = lca; top--;
			}
			if(st[top] != lca) 
				fa[lca] = st[top], st[++top] = lca, vr[++tot] = lca;
			fa[u] = lca, st[++top] = u, vr[++tot] = u; 
		}
		sort(vr + 1, vr + tot + 1, cmp);
		for(int i = 1; i <= tot; i++) if(fa[vr[i]]) add(fa[vr[i]], vr[i]);
	}
	inline void solveD(int u, int fa){
		for(int p = head[u]; p; p = nxt[p]){
			int v = a[p]; 
			if(v != fa){;
				solveD(v, u); if(!bel[u]){ bel[u] = bel[v]; continue; }
				int d1 = Lca::dis(u, bel[v]), d2 = Lca::dis(u, bel[u]);
				if(d1 < d2 || d1 == d2 && bel[v] < bel[u]) bel[u] = bel[v];		
			}
		}
	}
	inline void solveU(int u, int fa){
		if(fa){
			if(!bel[u]) bel[u] = bel[fa];
			else{
				int d1 = Lca::dis(u, bel[fa]), d2 = Lca::dis(u, bel[u]);
				if(d1 < d2 || d1 == d2 && bel[fa] < bel[u]) bel[u] = bel[fa];
			}
		}
		for(int p = head[u]; p; p = nxt[p]) if(a[p] != fa) solveU(a[p], u);
	}
	inline void solveE(int u, int v){
		int x = v, y = v;
		for(int i = 22; i >= 0; i--) if(dep[f[x][i]] > dep[u]) x = f[x][i];
		g[u] += sz[x]; 
		if(bel[u] == bel[v]) return (void) (ans[bel[u]] += sz[x] - sz[v]);
		for(int i = 22; i >= 0; i--){
			int now = f[y][i];
			if(dep[now] <= dep[u]) continue;
			int d1 = Lca::dis(now, bel[u]), d2 = Lca::dis(now, bel[v]);
			if(d1 > d2 || d1 == d2 && bel[u] > bel[v]) y = now;  
		}
		ans[bel[u]] += sz[x] - sz[y], ans[bel[v]] += sz[y] - sz[v];
	}
	inline void solve(){
		solveD(1, 0), solveU(1, 0);
		for(int i = 1; i <= tot; i++){
			int u = vr[i];
			for(int p = head[u]; p; p = nxt[p]) solveE(u, a[p]);
		}
		for(int i = 1; i <= tot; i++){
			int u = vr[i]; ans[bel[u]] += sz[u] - g[u];
		}
	}
}
int main(){
	read(n);
	for(int i = 1; i < n; i++){
		int x, y;
		read(x), read(y), add(x, y), add(y, x);
	}
	Lca::Doit(), read(q);
	while(q--){
		VirTree::Clear();
		int tot = 0, k; m[++tot] = 1, read(k);
		for(int i = 1, x; i <= k; i++) read(x), m[++tot] = x, bel[x] = x;
		VirTree::build(m, tot),  VirTree::solve();
		for(int i = 2; i <= k + 1; i++) printf("%d ", ans[m[i]]);
		printf("\n");
	}
}
