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
#define N (500005)
map<pair<int, int>, int> mp;
int Ans[N], fa[N], n, m; 
struct Point{ int x, y, z, id; } e[N];
inline bool cmp(Point A, Point B){ 
	return A.z < B.z; 
}
inline int ask(int x){ 
	return x == fa[x] ? x : fa[x] = ask(fa[x]); 
}
namespace Graph{
	int dfn[N], low[N], Index; 
	struct Edge{ int x, id; }; vector<Edge> g[N];
	map<int, int> mp; vector<int> s;
	inline void Clear(){
		for(int i = 0; i < s.size(); i++) 
			dfn[s[i]] = low[s[i]] = 0, g[s[i]].clear();
		s.clear(), mp.clear(), Index = 0;
	}
	inline void Add(int x, int y, int id){
		g[x].push_back((Edge){y, id});
		g[y].push_back((Edge){x, id});
		if(!mp[x]) s.push_back(x), mp[x] = 1;
		if(!mp[y]) s.push_back(y), mp[y] = 1;
	}
	inline void dfs(int u, int fa){
		dfn[u] = low[u] = ++Index;
		for(int i = 0; i < g[u].size(); i++){
			int v = g[u][i].x; 
			if(!dfn[v]){
				dfs(v, u), low[u] = Min(low[u], low[v]);
				if(low[v] > dfn[u]) Ans[g[u][i].id] = 2;
			}
			else if(v != fa) low[u] = Min(low[u], dfn[v]);
		}
	}
	inline void solve(){
		for(int i = 0; i < s.size(); i++) if(!dfn[s[i]]) dfs(s[i], 0);
	}
}
inline void solve(int l, int r){
	Graph::Clear(), mp.clear();
	for(int i = l; i <= r; i++){
		int p = ask(e[i].x), q = ask(e[i].y);
		if(p == q) Ans[e[i].id] = 1; 
		else{
			pair<int, int> now = make_pair(min(p, q), max(p, q));
			if(++mp[now] == 1) Graph::Add(p, q, e[i].id);
		}
	}
	Graph::solve();
	for(int i = l; i <= r; i++){
		int p = ask(e[i].x), q = ask(e[i].y);
		if(p == q) continue;
		if(mp[make_pair(min(p, q), max(p, q))] > 1) Ans[e[i].id] = 0;
	}
	for(int i = l; i <= r; i++){
		int p = ask(e[i].x), q = ask(e[i].y);
		if(p != q) fa[p] = q;
	}
}
int main(){
	read(n), read(m);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1, x, y, z; i <= m; i++){
		read(x), read(y), read(z);
		e[i] = (Point){x, y, z, i};
	}
	sort(e + 1, e + m + 1, cmp), e[0].z = e[m+1].z = -1;
	for(int i = 1, l = 1; i <= m; i++){
		if(e[i].z != e[i-1].z) l = i;
		if(e[i].z != e[i+1].z) solve(l, i);
	}
	for(int i = 1; i <= m; i++){
		if(Ans[i] == 0) puts("at least one");
		if(Ans[i] == 1) puts("none");
		if(Ans[i] == 2) puts("any");
	}
	return 0;
}
