/*program by mangoyang*/
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define N (4000005)
#define P (998244353)
#define lson (u << 1)
#define rson (u << 1 | 1)
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
int n, m;
struct DS{
	int add[N], mul[N], sum[N];
	void inc (int u, int l, int r, int v) {
		add[u] = (add[u] + v) % P;
		sum[u] = (sum[u] + (ll)(r - l + 1) * v) % P;
	}
	void mult (int u, int l, int r, int v) {
		mul[u] = (ll)mul[u] * v % P;
		add[u] = (ll)add[u] * v % P;
		sum[u] = (ll)sum[u] * v % P;
	}
	void pushdown (int u, int l, int r) {
		int ls = u << 1, rs = ls | 1, mid = (l + r) >> 1;
		if (mul[u] != 1) {
			mult (ls, l, mid, mul[u]);
			mult (rs, mid + 1, r, mul[u]);
			mul[u] = 1;
		}
		if (add[u]) {
			inc (ls, l, mid, add[u]);
			inc (rs, mid + 1, r, add[u]);
			add[u] = 0;
		}
	}
	void build (int u, int l, int r) {
		mul[u] = 1;
		if (l == r) return ;
		int ls = u << 1, rs = ls | 1, mid = (l + r) >> 1;
		build (ls, l, mid), build (rs, mid + 1, r);
	}
	void update (int u, int l, int r, int s, int t, int a, int b) {
		if (l == s && r == t) {
			mult (u, l, r, a), inc (u, l, r, b);
			return ;
		}
		pushdown (u, l, r);
		int ls = u << 1, rs = ls | 1, mid = (l + r) >> 1;
		if (t <= mid) update (ls, l, mid, s, t, a, b);
		else if (s > mid) update (rs, mid + 1, r, s, t, a, b);
		else update (ls, l, mid, s, mid, a, b), update (rs, mid + 1, r, mid + 1, t, a, b);
		sum[u] = (sum[ls] + sum[rs]) % P;
	}
	int query (int u, int l, int r, int s, int t) {
		if (l == s && r == t) return sum[u];
		pushdown (u, l, r);
		int ls = u << 1, rs = ls | 1, mid = (l + r) >> 1;
		if (t <= mid) return query (ls, l, mid, s, t);
		if (s > mid) return query (rs, mid + 1, r, s, t);
		return (query (ls, l, mid, s, mid) + query (rs, mid + 1, r, mid + 1, t)) % P;
	}
}van;
struct Node{
	int l, r; 
	bool operator <(const Node &A) const{ return l < A.l; } 
}; set<Node> s[N];
inline void change(int l, int r, int x){
	set<Node>::iterator it = s[x].lower_bound((Node){l, l});
	int nl = l, nr = r;
	if(it != s[x].begin()){
		--it;
		if(it->r >= r) return (void) van.update(1, 1, n, l, r, 2, 0);
		if(it->r >= l) van.update(1, 1, n, l, it->r, 2, 0), l = it->r + 1;
		if(it->r >= l - 1) nl = it->l, s[x].erase(it); ++it;
	}
	for(; it != s[x].end() && it->l <= r; s[x].erase(it), ++it){
		if(l < it->l) van.update(1, 1, n, l, it->l - 1, 1, 1);
		if(it->r <= r) van.update(1, 1, n, it->l, it->r, 2, 0), l = it->r + 1;
		else van.update(1, 1, n, it->l, r, 2, 0), nr = it->r, l = r + 1;
	}
	if(l <= r) van.update(1, 1, n, l, r, 1, 1); 
	if(it != s[x].end() && it->l == r + 1) nr = it->r, s[x].erase(it);
	s[x].insert((Node){nl, nr}); 
}
main(){
	read(n), read(m);
	van.build(1, 1, n);
	for(int i = 1; i <= m; i++){
		int t, l, r, x; read(t);
		if(t == 1) read(l), read(r), read(x), change(l, r, x);
		else read(l), read(r), printf("%lld\n", van.query(1, 1, n, l, r));
	}
	return 0;
}
