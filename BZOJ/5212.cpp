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
#define int ll
set<int> s;
int a[N], nxt[N], head[N], cnt;
int sz[N], mx[N], del[N], v[N], sum[N], dif[N], n, m, ans;
inline void add(int x, int y){
	a[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt;
}
inline void dfs(int u, int fa){
	sz[u] = mx[u] = v[u];
	for(int p = head[u]; p; p = nxt[p]){
		int v = a[p];
		if(v != fa){
			dfs(v, u), sz[u] += sz[v];
			if(sz[v] > mx[u]) mx[u] = sz[v];
		}
	}
	ans += Min(sz[u] - 1, 2 * (sz[u] - mx[u]));
}
inline void addsize(int x, int w){ for(; x <= n; x += x & (-x)) sum[x] += w; }
inline int query(int x){ int ans = 0; for(; x; x -= x & (-x)) ans += sum[x]; return ans; }
inline int size(int x){ return query(n) - query(x - 1); }
main(){
	read(n), read(m);
	for(int i = 1; i <= n; i++) read(v[i]);
	for(int i = 1, x, y; i < n; i++)
		read(x), read(y), add(x, y), add(y, x);
	dfs(1, 0), printf("%lld\n", ans);
	for(int i = 1; i <= n; i++) addsize(i, v[i]);
	for(int i = 1; i < n; i++) if(v[i] > size(i+1)) s.insert(i);
	while(m--){
		int x, w, num = 0;
		read(x), read(w), addsize(x, w);
		if(size(x+1) >= v[x] && x < n){ 
			s.insert(x); 
			if(size(x+1) >= v[x] + w) ans += 2 * w;
			else ans += 2 * (size(x+1) - v[x]), del[++num] = x;
		}
		v[x] += w;
		for(set<int>::iterator it = s.begin(); it != s.end() && (*it) < x; ++it){
			int now = (*it);
			if(size(now+1) >= v[now]){
				ans += 2 * (v[now] - size(now+1) + w), del[++num] = now;
			} 
			else ans += 2 * w;
		}
		for(int i = 1; i <= num; i++) s.erase(del[i]); printf("%lld\n", ans);
	}
}
