/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (600005)
#define int ll
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
    if(f) x = -x;
} 
int a[N], b[N], nxt[N], head[N], cnt;
int dep[N], dfn[N], isv[N], ans[N], n, m;
inline void add(int x, int y, int z){
	a[++cnt] = y, b[cnt] = z, nxt[cnt] = head[x], head[x] = cnt;
}
namespace Lca{
	int f[N][23], Log[N], tot;
	inline int chkmin(int x, int y){ return dep[x] < dep[y] ? x : y; }
	inline void dfs(int u, int fa){
		dfn[u] = ++tot, f[tot][0] = u, dep[u] = dep[fa] + 1;
		for(int p = head[u]; p; p = nxt[p]){
			int v = a[p];
			if(v != fa) dfs(v, u), f[++tot][0] = u;
		}
	}
	inline void calc(){
		for(int i = 2; i < N; i++) Log[i] = Log[i>>1] + 1;
		for(int j = 1; j <= 22; j++)
			for(int i = 1; i + (1 << j) - 1 <= tot; i++)
				f[i][j] = chkmin(f[i][j-1], f[i+(1<<j-1)][j-1]);
	}
	inline int get(int u, int v){
		int x = dfn[u], y = dfn[v];
		if(x > y) swap(x, y); int g = Log[y-x+1];
		return chkmin(f[x][g], f[y-(1<<g)+1][g]); 
	}
	inline void Doit(){ dfs(1, 0), calc(); }
}
namespace Mndis{
	int s[N][23], f[N][23];
	inline void dfs(int u, int fa){
		for(int p = head[u]; p; p = nxt[p]){
			int v = a[p];
			if(v != fa) f[v][0] = u, s[v][0] = b[p], dfs(v, u);
		}
	}
	inline void calc(){
		for(int j = 1; j <= 22; j++)
			for(int i = 1; i <= n; i++){
				f[i][j] = f[f[i][j-1]][j-1];
				s[i][j] = Min(s[i][j-1], s[f[i][j-1]][j-1]);
			}
	}
	inline int get(int u, int v){
		int ans = inf;
		for(int i = 22; i >= 0; i--)
			if(dep[f[u][i]] >= dep[v]) ans = Min(s[u][i], ans), u = f[u][i];
		return ans;
	}
	inline void Doit(){ dfs(1, 0), calc(); }
}
namespace virtree{
	int vr[N], fa[N], st[N], tot;
	inline bool cmp(int x, int y){ return dfn[x] < dfn[y]; }
	inline void build(int Node[], int size){
		int top = 0; tot = 0;
		sort(Node + 1, Node + size + 1, cmp);
		for(int i = 1; i <= size; i++){
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
	}
	inline int solve(){
		for(int i = 1; i <= tot; i++) ans[vr[i]] = 0;
		for(int i = tot; i >= 2; i--){
			int u = vr[i];
			if(isv[u]) ans[fa[u]] += Mndis::get(u, fa[u]); 
			else ans[fa[u]] += min(Mndis::get(u, fa[u]), ans[u]);   
		} 
	}
}
main(){
	read(n);
	for(int i = 1; i < n; i++){
		int x, y, z;
		read(x), read(y), read(z);
		add(x, y, z), add(y, x, z);
	}
	Lca::Doit(), Mndis::Doit(), read(m);
	while(m--){
		int tot = 0, k; read(k), a[++tot] = 1;
		for(int i = 1, x; i <= k; i++) read(x), isv[x] = 1, a[++tot] = x;
		virtree::build(a, tot), virtree::solve(), printf("%lld\n", ans[1]);
		for(int i = 1; i <= tot; i++) isv[a[i]] = 0;
	}
	return 0;
}
