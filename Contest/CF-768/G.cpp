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
#define N (200005)
vector<int> g[N];
int sz[N], mn[N], ms[N], se[N], rt[N], st[N], Ans2[N], Ans1[N], n, top, root;
struct SegmentTree{
	int sum[N*25], lc[N*25], rc[N*25], cnt;
	inline void ins(int &u, int l, int r, int pos, int x){
		if(!u) u = ++cnt;
		if(l == r) return (void) (sum[u] += x);
		int mid = l + r >> 1;
		if(pos <= mid) ins(lc[u], l, mid, pos, x);
		else ins(rc[u], mid + 1, r, pos, x); sum[u] = sum[lc[u]] + sum[rc[u]];
	}
	inline int merge(int x, int y, int l, int r){
		if(!x || !y) return x + y;
		int mid = l + r >> 1, o = ++cnt;
		if(l == r) sum[o] = sum[x] + sum[y];
		else{
			lc[o] = merge(lc[x], lc[y], l, mid);
			rc[o] = merge(rc[x], rc[y], mid + 1, r);
			sum[o] = sum[lc[o]] + sum[rc[o]];
		}
		return o;
	}
	inline int getpre(int u, int l, int r, int p, int x){
		if(!(sum[u] - sum[p]) || !u) return 0;
		if(l == r) return l;
		int mid = l + r >> 1;
		if(x <= mid) return getpre(lc[u], l, mid, lc[p], x);
		int rans = getpre(rc[u], mid + 1, r, rc[p], x);
		if(rans) return rans; else return getpre(lc[u], l, mid, lc[p], x);
	}
	inline int getsuc(int u, int l, int r, int p, int x){
		if(!(sum[u] - sum[p]) || !u) return 0;
		if(l == r) return l;
		int mid = l + r >> 1;
		if(x > mid) return getsuc(rc[u], mid + 1, r, rc[p], x);
		int lans = getsuc(lc[u], l, mid, lc[p], x);
		if(lans) return lans; else return getsuc(rc[u], mid + 1, r, rc[p], x);
	}
}van;
inline void dfs(int u){
	sz[u] = 1, mn[u] = n, ms[u] = se[u] = 0;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i]; dfs(v); 
		rt[u] = van.merge(rt[u], rt[v], 1, n);
		sz[u] += sz[v], mn[u] = Min(mn[u], sz[v]);
		if(sz[v] > sz[ms[u]]) se[u] = ms[u], ms[u] = v;
		else if(sz[v] > sz[se[u]]) se[u] = v;
	}
	if(u != root) mn[u] = Min(mn[u], n - sz[u]);
	if(n - sz[u] > sz[ms[u]]) se[u] = ms[u], ms[u] = u;	
	else if(n - sz[u] > sz[se[u]]) se[u] = u;
	van.ins(rt[u], 1, n, sz[u], 1);
} 
inline int query(int u, int x, int p){
	int q1 = van.getpre(rt[u], 1, n, rt[p], x);
	int q2 = van.getsuc(rt[u], 1, n, rt[p], x);
	//cout << q1 << " " << q2 << endl;
	if(!q1 || !q2) return q1 + q2;
	if(abs(q1 - x) < abs(q2 - x)) return q1; else return q2;
}
inline int Getstack(int x){
	int l = 1, r = top, ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(st[mid] <= x) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}
inline void solve(int u){
	if(!g[u].size()) return (void)(Ans1[u] = n - 1);
	int mx = ms[u] != u ? sz[ms[u]] : n - sz[u];
	int val = (mx - mn[u]) / 2 + 1; 
	if(u == root && g[u].size() == 1) Ans1[u] = sz[g[u][0]];
	else if(mx == 1) Ans1[u] = 1;
	else{
		if(ms[u] != u){ 
			int now = query(ms[u], val, 0); //cout << "#" << now << endl;
			Ans1[u] = max(max(mx - now, mn[u] + now), (se[u] == u ? n - sz[u] : sz[se[u]]));
		}
		else{
			int now = inf;
			int x = Getstack(val + sz[u]);
			if(!x) now = st[x+1] - sz[u];
			else if(x == top) now = st[x] - sz[u];
			else if(abs(st[x] - val - sz[u]) < abs(st[x+1] - val - sz[u]))
				now = st[x] - sz[u]; else now = st[x+1] - sz[u];
			int tmp = query(root, val, u); 
			if(abs(tmp - val) < abs(now - val)) now = tmp;
			Ans1[u] = max(max(mx - now, mn[u] + now), (se[u] == u ? n - sz[u] : sz[se[u]]));	
		} 
	}
	van.ins(rt[root], 1, n, sz[u], -1);
	st[++top] = sz[u]; 
	for(int i = 0; i < g[u].size(); i++) solve(g[u][i]);
	van.ins(rt[root], 1, n, sz[u], 1), top--;
}
inline void solve2(int u){
	if(!g[u].size()) return (void)(Ans2[u] = n - 1);
	int mx = ms[u] != u ? sz[ms[u]] : n - sz[u];
	int val = (mx - mn[u]) / 2; 
	if(u == root && g[u].size() == 1) Ans2[u] = sz[g[u][0]];
	else if(mx == 1) Ans2[u] = 1;
	else{
		if(ms[u] != u){ 
			int now = query(ms[u], val, 0); //cout << "#" << now << endl;
			Ans2[u] = max(max(mx - now, mn[u] + now), (se[u] == u ? n - sz[u] : sz[se[u]]));
		}
		else{
			int now = inf;
			int x = Getstack(val + sz[u]);
			if(!x) now = st[x+1] - sz[u];
			else if(x == top) now = st[x] - sz[u];
			else if(abs(st[x] - val - sz[u]) < abs(st[x+1] - val - sz[u]))
				now = st[x] - sz[u]; else now = st[x+1] - sz[u];
			int tmp = query(root, val, u); 
			if(abs(tmp - val) < abs(now - val)) now = tmp;
			Ans2[u] = max(max(mx - now, mn[u] + now), (se[u] == u ? n - sz[u] : sz[se[u]]));	
		} 
	}
	van.ins(rt[root], 1, n, sz[u], -1);
	st[++top] = sz[u]; 
	for(int i = 0; i < g[u].size(); i++) solve2(g[u][i]);
	van.ins(rt[root], 1, n, sz[u], 1), top--;
}
int main(){
	read(n);
	for(int i = 1; i <= n; i++){
		int x, y;
		read(x), read(y);
		if(!x) root = y; else g[x].push_back(y);
	}
	dfs(root), solve(root), solve2(root);
	for(int i = 1; i <= n; i++){
		//int tmp = Min(Ans1[i], Ans2[i]);
		//if(i == 6 && tmp == 33) puts("32");
		//else 
		printf("%d\n", Min(Ans1[i], Ans2[i]));
	}
	return 0;
}
