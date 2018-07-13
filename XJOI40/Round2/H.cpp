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

#define par pair<int, int> 
#define fi first
#define se second

const int MAXN = 200001, MAXK = 11;
int a[MAXK], c[MAXK], s[MAXK];
int rt[MAXN], fx[MAXN], fy[MAXN], ax[MAXN], ay[MAXN], n, len;

struct SegmentTree{
	int sz[N*25], lc[N*25], rc[N*25], cnt;
	inline void ins(int &u, int pr, int l, int r, int pos){
		u = ++cnt, sz[u] = sz[pr] + 1;
		lc[u] = lc[pr], rc[u] = rc[pr];
		if(l == r) return;
		int mid = l + r >> 1;
		if(pos <= mid) ins(lc[u], lc[pr], l, mid, pos);
		else ins(rc[u], rc[pr], mid + 1, r, pos);
	}
	inline par query(int u, int l, int r, int res, int k){
		if(l == r) return make_pair(res + sz[u], l);
		int mid = l + r >> 1, lsize = sz[lc[u]];
		if(k <= lsize) return query(lc[u], l, mid, res, k);
		else return query(rc[u], mid + 1, r, res + lsize, k - lsize);
	}
	inline int ask(int x, int y, int l, int r, int L, int R){
		if(l >= L && r <= R) return sz[y] - sz[x];
		int mid = l + r >> 1, res = 0;
		if(L <= mid) res += ask(lc[x], lc[y], l, mid, L, R);
		if(mid < R) res += ask(rc[x], rc[y], mid + 1, r, L, R);
		return res;
	}
}van;

namespace prepare{
	int x[MAXN], y[MAXN];
	struct Point{ int x, y; } d[MAXN];
	inline bool cmp(Point A, Point B){ return A.x < B.x; }	
	inline void Getvalue(){
		for(int i = 1; i <= n; i++) x[i] = ax[i], y[i] = ay[i];
		sort(x + 1, x + n + 1), sort(y + 1, y + n + 1);
		int sx = unique(x + 1, x + n + 1) - x - 1;
		int sy = unique(y + 1, y + n + 1) - y - 1;
		for(int i = 1; i <= n; i++){
			d[i].x = lower_bound(x + 1, x + sx + 1, ax[i]) - x;
			d[i].y = lower_bound(y + 1, y + sy + 1, ay[i]) - y;
			fx[d[i].x] = ax[i], fy[d[i].y] = ay[i];
		}
	}
	inline void Buildtree(){
		sort(d + 1, d + n + 1, cmp);
		for(int i = 1; i <= n; i++){
			if(d[i].x == d[i-1].x) 
				van.ins(rt[d[i].x], rt[d[i].x], 1, n, d[i].y);
			else van.ins(rt[d[i].x], rt[d[i-1].x], 1, n, d[i].y), lm++;
		}
	}
	inline void realmain(){ Getvalue(), Buildtree(); }
}

namespace Count{
	inline int solvex(int x){
		int l = 1, r = len, ans = -1;
		while(l <= r){
			int mid = l + r >> 1;
			if(van.sz[rt[mid]] <= x) 
				ans = mid, l = mid + 1; else r = mid - 1;
		}
		return (~ans && van.sz[rt[ans]] == x) ? ans : -1;
	}
	inline int solvey(int x){
		par res = van.query(rt[len], 1, n, 0, x);
		if(res.fi == x) return res.se; else return -1;
	}
}
namespace Doit{
	int a[MAXK], c[MAXK], sx1, sx2, sy1, sy2;
	inline void prepare(){
		for(int i = 1; i <= 9; i++) a[i] = s[c[i]];
		sx1 = a[1] + a[2] + a[3], sx2 = sx1 + a[4] + a[5] + a[6];
		sy1 = a[1] + a[4] + a[7], sy2 = sy1 + a[2] + a[5] + a[8];
	}
	inline bool check(int x1, int y1, int x2, int y2){
		if(van.ask(rt[0], rt[x1], 1, n, 1, y1) != a[1]) return 0;
		if(van.ask(rt[0], rt[x1], 1, n, y1 + 1, y2) != a[2]) return 0;
		if(van.ask(rt[0], rt[x1], 1, n, y2 + 1, n) != a[3]) return 0;
		if(van.ask(rt[x1], rt[x2], 1, n, 1, y1) != a[4]) return 0;
		if(van.ask(rt[x1], rt[x2], 1, n, y1 + 1, y2) != a[5]) return 0;
		if(van.ask(rt[x1], rt[x2], 1, n, y2 + 1, n) != a[6]) return 0;
		if(van.ask(rt[x2], rt[lm], 1, n, 1, y1) != a[7]) return 0;
		if(van.ask(rt[x2], rt[lm], 1, n, y1 + 1, y2) != a[8]) return 0;
		if(van.ask(rt[x2], rt[lm], 1, n, y2 + 1, n) != a[9]) return 0;
		return 1;
	}
	inline void solve(){ 
		int x1 = Count::slovex(sx1), x2 = Count::solvex(sx2);
		int y1 = Count::solvey(sy1), y2 = Count::solvey(sy2);
		if(x1 != sx1 || x2 != sx2 || y1 != sy1 || y2 != sy2) return;
		if(check(x1, x2, y1, y2)){
			printf("%.12lf %.12lf\n", fx[px1] + 0.5, fx[px2] + 0.5);
			printf("%.12lf %.12lf\n", fy[py1] + 0.5, fy[py2] + 0.5);
			exit(0);
		}
	}
	inline void realmain(){
		for(int i = 1; i <= 9; i++) c[i] = i;
		for(int i = 1; i <= 362880; i++)
			solve(), next_permutation(c + 1, c + 10);
		puts("-1");
	}
}

inline void Init(){
	read(n);
	for(int i = 1; i <= n; i++) read(ax[i]), read(ay[i]);
	for(int i = 1; i <= 9; i++) read(s[i]);
}
int main(){
	Init();
	prepare::realmain(), Doit::realmain();
	return 0;
}
