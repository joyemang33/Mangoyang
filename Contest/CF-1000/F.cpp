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
#define Debug 0
#define N (600005)
#define fi first
#define se second
#define par pair<int, int>
int a[N], pre[N], suc[N], last[N], ans[N],  n, m;
struct Point{ int l, r, x; } e[N], q[N];
inline bool cmp(Point A, Point B){ return A.l < B.l; }
struct SegmentTree{
	#define lson (u << 1)
	#define rson (u << 1 | 1)
	par v[N<<2];
	inline void build(int u, int l, int r){
		if(l == r) return (void) (v[u].se = l);
		int mid = l + r >> 1;
		build(lson, l, mid), build(rson, mid + 1, r);
	}
	inline void modify(int u, int l, int r, int pos, int val){
		#if Debug
			if(u == 1)
				cout << "M " << pos << " " << val << endl;
		#endif
		if(l == r) return (void) (v[u].fi = Max(v[u].fi, val));
		int mid = l + r >> 1;
		if(pos <= mid) modify(lson, l, mid, pos, val);
		else modify(rson, mid + 1, r, pos, val); 
		v[u] = max(v[lson], v[rson]);
	}
	inline par query(int u, int l, int r, int L, int R){
		#if Debug
			if(u == 1)
				cout << "Q " << L << " " << R << endl;
		#endif
		if(l >= L && r <= R) return v[u];
		int mid = l + r >> 1; par res; res.fi = res.se = 0;
		if(L <= mid) res = max(res, query(lson, l, mid, L, R));
		if(mid < R) res = max(res, query(rson, mid + 1, r, L, R));
		return res;
	}
}van;
int main(){
	read(n);
	for(int i = 1; i <= n; i++){
		read(a[i]);
		if(last[a[i]]){
			int x = last[a[i]];
			pre[i] = x, suc[x] = i;
		}
		last[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) if(!suc[i]) suc[i] = n + 1;
	for(int i = 1; i <= n; i++) 
		e[i] = (Point){pre[i], suc[i], i};
	sort(e + 1, e + n + 1, cmp); 
	van.build(1, 1, n);
	read(m);
	for(int i = 1, l, r; i <= m; i++) 
		read(l), read(r), q[i] = (Point){l, r, i};
	sort(q + 1, q + m + 1, cmp);
	int pos = 0;
	for(int i = 1; i <= m; i++){
		int l = q[i].l, r = q[i].r, id = q[i].x;
		while(pos < n && e[pos+1].l < l){
			pos++;
			van.modify(1, 1, n, e[pos].x, e[pos].r); 
		}
		par res = van.query(1, 1, n, l, r);
		#if Debug
			cout << "A " << res.fi << " " << res.se << endl;
		#endif
		if(res.fi > r) ans[id] = a[res.se];
	}
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}
