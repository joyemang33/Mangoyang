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
#define lson (u << 1)
#define rson (u << 1 | 1)
vector<int> g[N];
int top[N], dep[N], sz[N], fa[N], dfn[N], tot, n, q;
struct SegmentTree{
	int tag[N<<2], val[N<<2];
	inline SegmentTree(){
		for(int i = 0; i < (N << 2); i++) tag[i] = -1;
	}
	inline void pushdown(int u){
		if(tag[u] == -1) return;
		val[lson] = tag[u], val[rson] = tag[u];
		tag[lson] = tag[u], tag[rson] = tag[u];
		tag[u] = -1;
	}
	inline void change(int u, int l, int r, int L, int R, int c){
		//if(u == 1) cout << c << " " << l << " " << r << endl;
		if(l >= L && r <= R) 
			return (void) (val[u] = tag[u] = c);
		int mid = l + r >> 1; pushdown(u);
		if(L <= mid) change(lson, l, mid, L, R, c);
		if(mid < R) change(rson, mid + 1, r, L, R, c);
	}
	inline int query(int u, int l, int r, int pos){
		if(l == r) return val[u];
		int mid = l + r >> 1; pushdown(u);
		if(pos <= mid) return query(lson, l, mid, pos);
		else return query(rson, mid + 1, r, pos);
	}
}van;
namespace DivTree{
	inline void dfs(int u, int ff){
		dep[u] = dep[ff] + 1, sz[u] = 1, fa[u] = ff;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			if(v != ff) dfs(v, u), sz[u] += sz[v];
		}
	}
	inline void getchain(int u, int chain){
		int ms = 0; dfn[u] = ++tot, top[u] = chain;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			if(v != fa[u] && sz[v] > sz[ms]) ms = v;
		}
		if(ms) getchain(ms, chain);
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			if(v != fa[u] && v != ms) getchain(v, v);
		}
	}
	inline void Query(int u){
		int res = van.query(1, 1, n, dfn[u]);
		if(res == 0) puts("0"); else puts("1");
	}
	inline void Modify1(int u){
		van.change(1, 1, n, dfn[u], dfn[u] + sz[u] - 1, 1);
	}
	inline void Modify2(int u){
		int x = u, y = 1;
		while(top[x] != top[y]){
			if(dep[top[x]] < dep[top[y]]) swap(x, y);
			van.change(1, 1, n, dfn[top[x]], dfn[x], 0);
			x = fa[top[x]];
		}
		if(dfn[x] > dfn[y]) swap(x, y);
		van.change(1, 1, n, dfn[x], dfn[y], 0);
	}
	inline void realmain(){ dfs(1, 0), getchain(1, 1); }
}
int main(){
	read(n);
	for(int i = 1, x, y; i < n; i++){
		read(x), read(y);
		g[x].push_back(y), g[y].push_back(x);
	}	
	DivTree::realmain(), read(q);
	for(int i = 1, x, y; i <= q; i++){
		read(x), read(y);
		switch(x){
			case 1: DivTree::Modify1(y); break; 
			case 2: DivTree::Modify2(y); break;
			case 3: DivTree::Query(y); break;
		}
	}
	return 0;
}
